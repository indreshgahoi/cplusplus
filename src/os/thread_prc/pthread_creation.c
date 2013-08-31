/*
 * pthread_creation.c
 *
 *  Created on: May 13, 2013
 *      Author: Indresh Gahoi
 */


#include<pthread.h>
#include<stdio.h>


#define NUM_OF_THREADS (5)



void* PrintHello(void* threadid)
{
	long tid;
	tid=(long)(threadid);

	printf("Hello World :It's me thread=%ld\n",tid);
	pthread_exit(NULL);
}

int main(void)
{
	pthread_t thread[NUM_OF_THREADS];
	long i;
	int rc;

	for(i=1;i<=NUM_OF_THREADS;i++)
	{
		printf("creating thread %ld from main...\n",i);

		rc=pthread_create(&thread[i-1],NULL,PrintHello,i);

		if(rc)
		{
			printf("error creating thread %ld\n",i);
			exit(-1);
		}


	}

	pthread_exit(NULL);

}
