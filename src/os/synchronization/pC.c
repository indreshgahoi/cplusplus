/*
 * pC.c
 *
 *  Created on: May 11, 2013
 *      Author: Indresh Gahoi
 */

#include<stdio.h>

int main(void)
{
	int i,LIMIT;
	char input[100];

	while(fgets(input,LIMIT,stdin)!=NULL)
		printf("      From C: %s\n",input);
}


