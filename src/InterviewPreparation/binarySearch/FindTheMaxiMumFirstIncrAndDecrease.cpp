/*
 * FindTheMaxiMumFirstIncrAndDecrease.cpp
 * run command
 * g++ Algorithm/src/InterviewPreparation/binarySearch/FindTheMaxiMumFirstIncrAndDecrease.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 15, 2013
 *      Author: Indresh Gahoi
 */


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std ;
#define ARRAY_SIZE(A)  (sizeof(A)/sizeof(A[0]))
#define DEBUG
/*
 *  Link :- http://www.geeksforgeeks.org/find-the-maximum-element-in-an-array-which-is-first-increasing-and-then-decreasing/
 *  Question :
 *  	Find the maximum element in an array which is first increasing and then decreasing
 *
 *
 */
// This Method Only Work for  Distinct word
int* FindMaxIndex(int *first ,int *last)
{
	int *mid ;
	while(first <= last)
	{
		if(first==last)
	       return first ;
		if((first+1)==last)
			return (*first) > (*last) ? first : last ;

		mid = first + (last-first) / 2 ;

		/*
		 *  Case 1 : mid is solution means boundary
		 *  Case 2 : mid falls in increasing Part
		 *  Case 3 : mid falls in decreasing part
		 *
		 *
		 */
		// case 1 code
		if(*(mid-1) < *mid && *mid > *(mid+1))
			return mid ;
		// case 2
		if((*mid) < *(mid+1))
		{
			first = mid+1 ;
		}
		else
		{
			last = mid -1 ;
		}
	}

    return 0 ;
}

// Handle Duplicate case
int* FindMaxIndexHandleDuplicate(int *first ,int *last)
{
	int *mid ;
	while(first <= last)
	{
		if(first==last)
	       return first ;
		if((first+1)==last)
			return (*first) > (*last) ? first : last ;

		mid = first + (last-first) / 2 ;

		/*
		 *  Case 1 : mid is solution means boundary
		 *  Case 2 : mid falls in increasing Part
		 *  Case 3 : mid falls in decreasing part
		 *
		 *
		 */
		// case 1 code
		if(*(mid-1) < *mid && *mid > *(mid+1))
			return mid ;
		// case 2
		if((*mid) < *(mid+1))
		{

#ifdef DEBUG
         cout<<"\n first = "<<*first<<" last = "<<*last<<" "<<*mid<<" "<<*(mid+1)<<" second Half"<<"\n";
#endif
         first = mid+1 ;
		}
		else if((*mid)>*(mid+1))
		{

#ifdef DEBUG
         cout<<"\n first = "<<*first<<" last = "<<*last<<" "<<*mid<<" "<<*(mid-1)<<" first Half"<<"\n";
#endif
         last = mid -1 ;
		}
		else
		{
#ifdef DEBUG
         cout<<"\n first = "<<*first<<" last = "<<*last<<" "<<*mid<<" "<<*(mid-1)<<" linear Half"<<"\n";
#endif
			first++;
		}
	}

    return 0 ;
}

void printArray(int *start ,int n)
{
	for(int iter = 0 ; iter < n ; ++iter )
	{
		printf(" %d",start[iter]);
	}
	printf("\n");
}
int main()
{
   //int arr[] = {-1, -30 ,-31,-56,-4,-70 };
	//int arr[] = {70 ,80};
   int arr[] = {0, 1, 1, 2, 2, 2, 2, 2, 3, 4, 4, 5, 3, 3, 2, 2, 1, 1} ;
   int n = ARRAY_SIZE(arr);
   printArray(arr,n);
   printf("The maximum element is %d", *FindMaxIndexHandleDuplicate(arr,arr+n-1));
   std::cout<<"\n";
   return 0;
}
