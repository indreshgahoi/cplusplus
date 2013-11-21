/*
 * Powxn.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/Maths/Powxn.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 15, 2013
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std ;

class Solution {
public:

	double powHelper(double x, int n)
	{
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		if(n==0)
			return 1 ;
		double t = pow(x,n/2);
		t = t * t ;
		if(n & 1)
		{
			t= t*x;
		}
		return t;
	}
	double pow(double x, int n) {
		double t = powHelper(x,abs(n));
		if(n<0) return 1/t ;
		else
		{
			return t ;
		}
	}
};

#define debug(x) cout<<#x<<x<<"\n";
int main()
{
	Solution sl ;
	double res  = sl.pow(2,-3);
	debug(res)
	return 0 ;
}





