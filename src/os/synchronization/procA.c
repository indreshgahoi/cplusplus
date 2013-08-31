/*
 * procA.c
 *
 *  Created on: May 11, 2013
 *      Author: Indresh Gahoi
 */

#include<stdio.h>
#include<stdlib.h>


#define LIMIT (20)

int main(void)
{
	int i,j,x,y;

	srand(time(NULL));

	for(i=0;i<LIMIT;++i){
		 x=rand()/10;  //get a random number and scale it
	 for(j=0;j<x;j++)
	 {
		 y=rand();
	 }
	 printf("Hi, A here Random No=%d \n",x);
	}
	printf("Process A complete\n");
}

  // gcc procA.c -o A.out
 //  gcc procB.c -o B.out
//   A.out & B.out

