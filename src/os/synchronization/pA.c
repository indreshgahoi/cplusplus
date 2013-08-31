/*
 * pA.c
 *
 *  Created on: May 11, 2013
 *      Author: Indresh Gahoi
 */

#include<stdio.h>

int main(int argc ,char **argv[])
{
	int i,LIMIT;
	char output[100];

	LIMIT=atoi(argv[1]);
	printf("%d\n",LIMIT);

	for(i=1;i<=LIMIT;++i)
	{
		sprintf(output,"printing %d from A",i);
		printf("%s\n",output);
	}
}


