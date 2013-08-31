/*
 * pB.c
 *
 *  Created on: May 11, 2013
 *      Author: Indresh Gahoi
 */

#include<stdio.h>

int main(void)
{
	int i,LIMIT;
	char input[100];

	gets(input);
	LIMIT=atoi(input);


	for(i=1;i<=LIMIT;++i)
	{
		gets(input);
		printf("          From B: %s\n",input);
	}
}


