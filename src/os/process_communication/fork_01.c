/*
 * fork_01.c
 *
 *  Created on: May 11, 2013
 *      Author: Indresh Gahoi
 */


#include<stdio.h>
#include<string.h>
#include<sys/types.h>

#define MAX_SIZE (200)
#define BUFF_SIZE 100



int main(void)
{
	pid_t pid;
	int i;
	char buff[BUFF_SIZE];
	fork();
	pid=getpid();
	for(i=1;i<=MAX_SIZE;++i)
	{
		sprintf(buff,"This line from pid=%d value=%d\n",pid,i);
		write(1,buff,strlen(buff));
	}
}


