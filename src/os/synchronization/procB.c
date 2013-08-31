/*
 * procB.c
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
		 x=rand()/30; //process B run Faster
	 for(j=0;j<x;j++)
	 {
		 y=rand();
	 }
	 printf("            Hi, B here Random No=%d \n",x);
	}
	 printf("            Process B complete\n");
}

