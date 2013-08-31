/*
 * thread_stack_management_demo.c
 *
 *  Created on: May 16, 2013
 *      Author: Indresh Gahoi
 */


#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include <string.h>

#define NUM_OF_THREAD 5
#define N 1000
#define MEGAEXTRA (30000)

#define FOR(i,a,b)  for(i=(a);i<(b);++i)

pthread_attr_t attr;

struct thread_data
{
	size_t id;
	char name[16];
};

typedef struct thread_data* data_t;


/*
 *
 * pthread_attr_getstacksize (attr, stacksize)

   pthread_attr_setstacksize (attr, stacksize)

   pthread_attr_getstackaddr (attr, stackaddr)

   pthread_attr_setstackaddr (attr, stackaddr)
 *
 *
 *
 *
 */

void* worker_thread(void* data)
{
    data_t my_data=(data_t)(data);

    double M[N][N];
    size_t mystack_size;
    int my_id=my_data->id;
    int i=0,j=0;
    pthread_attr_getstacksize(&attr,&mystack_size);

    printf("My id=%d and stack size=%li bytes\n",my_id,mystack_size);

    FOR(i,0,N)
     FOR(j,0,N)
     {
    	M[i][j]=M[i][j]/3.4523+(N-i);
     }

   pthread_exit(NULL);
}



int main(void)
{
     pthread_t tid[NUM_OF_THREAD];
     size_t stacksize;
     int rc=0,i=0;
     char *names[]={"A","B","C","D","E","F"};
     pthread_attr_init(&attr);
     pthread_attr_getstacksize(&attr,&stacksize);
     printf("Defaut stack size=%li\n",stacksize);
     stacksize=sizeof(double)*(N*N) + MEGAEXTRA;
     pthread_attr_setstacksize(&attr,stacksize);
     printf("thread stack size will be size=%li bytes\n");

     FOR(i,0,NUM_OF_THREAD)
     {
        data_t data=(data_t) malloc(sizeof(struct thread_data));
        data->id=i+1;
        strcpy(data->name,names[i]);
        rc=pthread_create(tid+i,&attr,worker_thread,(void*)data);
        if(rc)
        {
        	printf("error in creating thread\n");
        	exit(-1);
        }
     }

    printf("Main created all the threads\n");
	pthread_exit(NULL);
}
