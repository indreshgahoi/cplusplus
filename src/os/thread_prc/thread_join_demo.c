/*
 * thread_join_demo.c
 *
 *  Created on: May 16, 2013
 *      Author: Indresh Gahoi
 */

#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define FOR(i,a,b) for(i=(a);i<(b);i++)

struct thread_data
{
	int id;
	char name[16];
};

typedef struct thread_data* data_t;

#define NUM_THREAD   10

void* worker(void *data)
{
	data_t mydata=(data_t)data;

	printf("my name is %s and my id=%d\n",mydata->name,mydata->id);
	pthread_exit((void *)&mydata->id);
}

int main(void)
{
	pthread_t tid[NUM_THREAD];
	struct thread_data data[NUM_THREAD];
	char* names[]={"A","B","C","D","E","F","G","H","I","J"};
	int i=0,*status,rc;

	FOR(i,0,NUM_THREAD)
	{   data[i].id=i+1;
	    strcpy(data[i].name,names[i]);
		rc=pthread_create(tid+i,NULL,worker,(void *)(data+i));
		if(rc)
		{
			printf("error for ceating threading no=%d\n",i);
			exit(1);
		}
	}

	FOR(i,0,NUM_THREAD)
	{
		pthread_join(tid[i],(void **)&status);
		printf("from main thread status of thread=%d\n  ",*status);
	}

	printf("Main thread completed and about to exit\n");
	pthread_exit(NULL);

}
