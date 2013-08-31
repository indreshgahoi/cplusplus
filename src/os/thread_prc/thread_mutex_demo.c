/*
 * thread_nutex_demo.c
 *
 *  Created on: May 18, 2013
 *      Author: Indresh Gahoi
 */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define NUM_OF_THREAD   4
#define VECTOR_LENTH    1000

struct dot_prod_data
{
	double *a;
	double *b;
	double sum;
	int len;
};

// mutex variable share by all thread

pthread_mutex_t mutex;

// global dot product data share by all data
 struct dot_prod_data vecdata;


void* worker_thread(void* data_t)
{

	int offset=(int)(data_t);

	int start,end;
	double local_sum=0.0;
	int len=vecdata.len;

	start=(len)*offset;
	end=start+len;


	while(start<end)
	{
		local_sum+=(vecdata.a[start]*vecdata.b[start]);
		start++;
	}

    pthread_mutex_lock(&mutex);
    vecdata.sum+=local_sum;
    printf("----local sum for thread%f %d\n",local_sum,offset);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);

}


int main(void)
{
    pthread_attr_t attr;
    pthread_t tid[NUM_OF_THREAD];
    double *a,*b;
    int i,rc;

    a=(double*) malloc((sizeof(double)*NUM_OF_THREAD*VECTOR_LENTH));
    b=(double*) malloc((sizeof(double)*NUM_OF_THREAD*VECTOR_LENTH));

    for(i=0;i<NUM_OF_THREAD*VECTOR_LENTH;++i)
    {
    	a[i]=1.0;
    	b[i]=a[i];
    }

    vecdata.len=VECTOR_LENTH;
    vecdata.a=a;
    vecdata.b=b;
    vecdata.sum=0.0;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
    pthread_mutex_init(&mutex,NULL);

    for(i=0;i<NUM_OF_THREAD;i++)
    {
      rc=pthread_create(tid+i,&attr,worker_thread,(void *)i);
      if(rc)
      {
    	  printf("*** error in creating thread***\n");
    	  exit(1);
      }
    }
    pthread_attr_destroy(&attr);
    for(i=0;i<NUM_OF_THREAD;++i)
    {
    	pthread_join(tid[i],NULL);
    }


    printf("vector sum=%f\n",vecdata.sum);

    free(a);
    free(b);

    pthread_mutex_destroy(&mutex);
    pthread_exit(NULL);
}





