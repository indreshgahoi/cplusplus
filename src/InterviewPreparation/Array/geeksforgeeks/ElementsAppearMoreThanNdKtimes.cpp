/*
 *  Link :-
 *  	http://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/
 *
 * Question :- Given an array of size n, find all elements in array that appear more than n/k times.
 *  For example, if the input arrays is {3, 1, 2, 2, 1, 2, 3, 3} and k is 4, then the output should be [2, 3].
 *  Note that size of array is 8 (or n = 8), so we need to find all elements that appear more than 2 (or 8/4)
 *  times. There are two elements that appear more than two times, 2 and 3.
 *
 * Solutions :-
 * 		A simple method is to pick all elements one by one. For every picked element, count its occurrences by
 * 		traversing the array, if count becomes more than n/k, then print the element. Time Complexity of this
 * 		 method would be O(n2).

A better solution is to use sorting. First, sort all elements using a O(nLogn) algorithm. Once the array is
sorted, we can find all required elements in a linear scan of array. So overall time complexity of this method
is O(nLogn) + O(n) which is O(nLogn).

Following is an interesting O(nk) solution:
We can solve the above problem in O(nk) time using O(k-1) extra space. Note that there can never be more than k-1 elements in output (Why?). There are mainly three steps in this algorithm.

1) Create a temporary array of size (k-1) to store elements and their counts
 (The output elements are going to be among these k-1 elements).
 Following is structure of temporary array elements.

struct eleCount {
    int element;
    int count;
};

struct eleCount temp[];

This step takes O(k) time.

2) Traverse through the input array and update temp[] (add/remove an element or increase/decrease count)
for every traversed element. The array temp[] stores potential (k-1) candidates at every step.
This step takes O(nk) time.

3) Iterate through final (k-1) potential candidates (stored in temp[]).
 or every element, check if it actually has count more than n/k. This step takes O(nk) time.

The main step is step 2, how to maintain (k-1) potential candidates at every point?
The steps used in step 2 are like famous game: Tetris. We treat each number as a piece in Tetris,
which falls down in our temporary array temp[]. Our task is to try to keep the same number stacked on the
same column (count in temporary array is incremented)
 *
 */

#include<iostream>
#include<cstdio>
#include<vector>

using namespace std ;

/*
 *  Find Potential candidate
 *   crteate (k-1) array
 *
 *
 *
 */


template<class T>
ostream& operator<<(ostream &out,const vector<T>& V){
	out<<"[";
	for(typename vector<T>::const_iterator it=V.begin();it!=V.end();it++){
	 out<<" "<<*it;

	}
	out<<"]"<<endl;
	return out;
}




struct info
{
	int elem ;
	int count ;
	info():count(0),elem(-1)
	{

	}
};
	ostream&  operator<<(ostream &out , const info &I)
	{
		out<<"("<<I.elem <<","<<I.count<<") " ;

	return out;
	}



vector<int> FindElementAppearMoreThanNdKTimes(vector<int> &V,int  k)
				{
	vector<info> majoirty(k-1);
	vector<int> res ;

	for(vector<int>::const_iterator it = V.begin() ; it != V.end() ; ++it)
	{
		int j ;
		for( j = 0 ; j < k-1 ; ++j)
		{
			if(majoirty[j].count==0)
			{
				majoirty[j].count= 1 ;
				majoirty[j].elem = *it ;
				break ;
			}
			else if(majoirty[j].elem == (*it))
			{
				majoirty[j].count++;
				break ;
			}
		}


		if(j==(k-1))
		{
			for(j= 0 ; j < k-1 ; ++j)
			{
				majoirty[j].count-- ;
			}
		}

	}

	int actual_count = 0 ;
	for(int j =0 ; j < k-1 ; ++j )
	{
		if(majoirty[j].count>0)
		{
			actual_count = 0 ;

			for(vector<int>::iterator it = V.begin() ; it != V.end() ; ++it)
			{
				if((*it) == majoirty[j].elem)
				{
					actual_count++;
				}

			}
			if(actual_count > (V.size()/k))
				res.push_back(majoirty[j].elem);
		}
	}
	return res ;
}



int main()
{

	vector<int> input;
    input.push_back(5);
    input.push_back(2);
    input.push_back(3);
    input.push_back(4);
    input.push_back(2);
    input.push_back(2);
    input.push_back(3);
    input.push_back(5);
    input.push_back(5);
    input.push_back(3);
    input.push_back(3);
    input.push_back(5);
    input.push_back(8);
    input.push_back(3);
    input.push_back(3);
    cout<<input;
    int k ;
    while(cin>>k)
    cout<<FindElementAppearMoreThanNdKTimes(input,k);

    return 0 ;
}


