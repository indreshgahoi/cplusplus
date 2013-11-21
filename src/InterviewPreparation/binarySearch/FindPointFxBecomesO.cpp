/*
 * FindPointFxBecomesO.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/binarySearch/FindPointFxBecomesO.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 10, 2013
 *      Author: Indresh Gahoi
 */


/*  Link :-
 * Question :-
Find the point where a monotonically increasing function becomes positive
first time


Given a function ‘int f(unsigned int x)’ which takes a non-negative integer ‘x’ as
input and returns an integer as output. The function is monotonically increasing with
respect to value of x, i.e., the value of f(x+1) is greater than f(x) for every input
 x. Find the value ‘n’ where f() becomes positive for the first time. Since f() is
	monotonically increasing, values of f(n+1), f(n+2),… must be positive and values of
	f(n-2), f(n-3), .. must be negative.
	Find n in O(logn) time, you may assume that f(x) can be evaluated in O(1) time for
 any input x.
 *
 */

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std ;

#define debug(x) cout<<#x" "<<x<<"\n";
#define nl cout<<"\n";

int F(int x)
{
	return x*x -10*x-20 ;
}

int BinarySearch(int low , int high)
{
	int mid = -1;
	while(low <= high)
	{
		mid = low + (high-low)/2 ;
		if(F(mid)> 0 && (mid==low || F(mid-1)<= 0))
			return mid ;
		if(F(mid) <= 0)
			low = mid+1 ;
		else
			high = mid - 1;
	}

	return -1 ;
}

int FindPointWhereFxBecomePositive( )
{
	int i = 0 ;

	if(F(i)>0) return i ;

	i= 1;
	while(F(i)<= 0) i<<=1;

	return BinarySearch(i>>1,i);
}


int main()
{
	cout<<"result = "<<FindPointWhereFxBecomePositive()<<"\n";
	return 0 ;
}






