/*
 * helper.cpp
 *
 *  Created on: Mar 29, 2013
 *      Author: indresh
 */
#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<climits>
#include<string>
#include <cstring>
using namespace std;

#define ARRAYSIZE(A) (sizeof(A)/sizeof(A[0]))

void printArray(int A[],size_t size){
	printf("values= [");
   for(int i=0;i<size-1;i++)
	   printf("%d ,",A[i]);
   printf("%d]\n",A[size-1]);
}



