/*
 * Walk.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/CodeChef/src/MAR14/Walk.cpp -o /usr/build/Main.o
 *
 *  Created on: Mar 9, 2014
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<cstdio>



int main()
{
	int T ;

	scanf("%d",&T);
	int *A = new int[100001] ;
	 int size ;
	while(T--)
	{
		scanf("%d",&size);
		for(int i = 0 ; i < size ; ++i)
		 scanf("%d",A+i);
		int start_val = A[0] ;
		int curr_val = start_val - 1 ;

		for(int i = 1 ; i < size ; ++i)
		{
			if(curr_val < A[i])
			{
				start_val+= (A[i]-curr_val) ;
				curr_val = A[i] ;
			}
			curr_val-- ;
		}
		printf("%d\n",start_val);
	}
    delete[] A ;
    return 0 ;
}

