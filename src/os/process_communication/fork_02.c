/*
 * fork_02.c
 *
 *  Created on: May 11, 2013
 *      Author: Indresh Gahoi
 */


#include<stdio.h>
#include<sys/types.h>

#define MAX_COUNT 200

void ChildProcess(void);                //child process prototype
void ParentProcess(void);              // parent process prototype

int main(void)
{
 pid_t pid;

 pid=fork();

 if(pid==0)
	 ChildProcess();
 else
	 ParentProcess();

}


void ChildProcess()
{
	int i;
	for(i=1;i<=MAX_COUNT;++i)
		printf("     This is from child process and value= %d\n",i);
	printf("     ***Child process id done\n");
}

void ParentProcess()
{
	int i;
		for(i=1;i<=MAX_COUNT;++i)
			printf("This is from parent process and value= %d\n",i);
		printf("parent process id done\n");
}
