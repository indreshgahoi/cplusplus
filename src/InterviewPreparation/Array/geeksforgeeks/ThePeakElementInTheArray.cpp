/*
 * FindThePeakElementInTheArray.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/Array/geeksforgeeks/FindThePeakElementInTheArray.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 11, 2013
 *      Author: Indresh Gahoi
 */

/*
 * Link :- http://www.geeksforgeeks.org/find-a-peak-in-a-given-array/
 *
 *  http://courses.csail.mit.edu/6.006/spring11/lectures/lec02.pdf
	http://www.youtube.com/watch?v=HtSuA80QTyo
 *
 *   Question :-
 *   	Given an array of integers. Find a peak element in it.
 *   	An array element is peak if it is NOT smaller than its neighbors.
 *   	For corner elements, we need to consider only one neighbor. For example,
 *   	for input array {5, 10, 20, 15}, 20 is the only peak element.
 *   	For input array {10, 20, 15, 2, 23, 90, 67},
 *   	there are two peak elements: 20 and 90. Note that we need to return any one
 *   	 peak element.
 *
 */
#include<iostream>
#include<vector>
#include<cstdio>
#include<limits.h>

using namespace std ;

int FindThePeakElment(vector<int> &v)
{
	int l = 0 ;
	int r = v.size();
	int mid ;

	while(l<=r)
	{
		if(l==r)
			return l ;

		 mid =  l + (r-l)/2 ;


		 if(l<mid && v[mid-1] > v[mid])
			 r = mid -1 ;
		 else if(r>mid && v[mid+1]>v[mid])
			 l = mid+1 ;
		 else
			 return mid ;
	}
	return -1 ;
}


template<class T>
ostream& operator<<(ostream &out,const vector<T>& V){
	out<<"[";
	for(typename vector<T>::const_iterator it=V.begin();it!=V.end();it++){
	 out<<" "<<*it;
	}
	out<<"]"<<endl;
	return out;
}

void getInput(vector<int> &v)
{
#define ARRAYSIZE(A) sizeof(A)/sizeof(A[0])
	int arr[] = { 20,20,20,21} ;
	int size = ARRAYSIZE(arr) ;
	for(int iter = 0 ; iter < size ; ++iter)
	{
		v.push_back(arr[iter]);
	}
}

void test()
{
	vector<int> input ;
    getInput(input);
    cout<<input;
    int p = FindThePeakElment(input);
    cout<<" index = "<<p ;
    cout<<"\n Element = "<<input[p];

}


int main()
{
    test();
    cout<<"\n";
	return 0 ;
}
