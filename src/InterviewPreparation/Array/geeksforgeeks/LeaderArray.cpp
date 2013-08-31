/*
 * LeaderArray.cpp
 *
 *  Created on: Mar 29, 2013
 *      Author: indresh
 */
#include "constant.h"

/*
Leaders in an array
December 7, 2009

Write a program to print all the LEADERS in the array. An element is
leader if it is greater than all the elements to its right side. And the
rightmost element is always a leader.
For example int the array {16, 17, 4, 3, 5, 2},
leaders are 17, 5 and 2.
Let the input array be arr[] and size of the array be size.
*/

vector<int> leadersInArray(int A[],size_t size){
	vector<int> leaders;
	leaders.push_back(A[size-1]);
	int rightMax=A[size-1];
	for(int i=size-2;i>=0;i--){
		if(A[i]>rightMax)
		{
			leaders.push_back(A[i]);
			rightMax=A[i];
		}
	}
	return leaders;
}
void driver(){
	int A[]={1,2,3,56,13,2,5,17,18,4,0,10};
	size_t size=ARRAYSIZE(A);
	cout<<" "<<leadersInArray(A,size);
}




