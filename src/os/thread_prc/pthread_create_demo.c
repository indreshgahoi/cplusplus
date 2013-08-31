/*
 * pthread_create_demo.c
 *
 *  Created on: May 15, 2013
 *      Author: Indresh Gahoi
 */

#include<stdio.h>
#include<pthread.h>


void* do_loop(void* data)
{
	int i,j;
	int me=*((int*)data);

	for(i=1;i<=10;i++)
	{
		for(j=1;j<=50000;j++);
	   printf("Hello it %d me=%d \n",i,me);
	}
	pthread_exit(NULL); // this is for thread termination

}


int main(void)
{
	int t_id;
	pthread_t tid;
	int a=1,b=2;

	t_id=pthread_create(&tid,NULL,do_loop,(void*)&a);

	do_loop((void*)&b);
	return (0);
}

