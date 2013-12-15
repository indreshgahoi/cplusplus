/*
 * RearrangePositiveAndNegativeNumber.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/Array/geeksforgeeks/RearrangePositiveAndNegativeNumber.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 10, 2013
 *      Author: Indresh Gahoi
 */

/* Link :-
 * 		http://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers-publish/
 *
 *	Q:-Rearrange positive and negative numbers in O(n) time and O(1) extra space
 *
 * An array contains both positive and negative numbers in random order.
 * Rearrange the array elements so that positive and negative numbers are placed
 * alternatively. Number of positive and negative numbers need not be equal.
 *  If there are more positive numbers they appear at the end of the array.
 *  If there are more negative numbers, they too appear in the end of the array.
 *
 *
 */

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std ;

//template < typename T>
//void swap(T &a , T &b)
//{
//	T temp = a ;
//	a = b;
//	b = temp;
//}


template<class T>
ostream& operator<<(ostream &out,const vector<T>& V){
	out<<"[";
	for(typename vector<T>::const_iterator it=V.begin();it!=V.end();it++){
		out<<" "<<*it;

	}
	out<<"]"<<endl;
	return out;
}

/*	This Method Also return
 *
 */
int SeparatePositiveAndNegative(vector<int> &V)
{
	int size = V.size();
	int l=0 , r=0;
	while(r<size)
	{
		if(V[r]<0)
		{
			swap(V[l++],V[r]);
		}
		r++ ;
	}
	cout<<V<<std::endl;
	return l ;
}


void RearrangePositiveAndNegativeNumbers(vector<int> &V)
{

	int size = V.size();
	int l ,r  ;

	r=SeparatePositiveAndNegative(V);
	l = 1 ;

	while(r < size && V[l] < 0 )
	{
		swap(V[l],V[r++]);
		l+=2;
		cout<<" result " << V ;

	}
	cout<<" result " << V ;
}

void getInput(vector<int> &v)
{
#define ARRAYSIZE(A) sizeof(A)/sizeof(A[0])
	int arr[] = {-2,-3,1,2,3,-4,-5,6,7,-10,11,-12};
	int size = ARRAYSIZE(arr) ;
	for(int iter = 0 ; iter < size ; ++iter)
	{
		v.push_back(arr[iter]);
	}
}

void test()
{
	vector<int> v ;
    getInput(v);
    cout<<v<<"\n";
    RearrangePositiveAndNegativeNumbers(v);
    cout<<v ;
}

void closeApp()
{
	int x ;
	while(cin>>x)
		exit(0);
}

int main()
{
	test();

	closeApp();
	return 0 ;
}
