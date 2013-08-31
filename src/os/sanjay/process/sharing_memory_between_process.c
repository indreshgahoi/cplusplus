/*
 * sharing_memory_between_process.c
 *
 *  Created on: May 12, 2013
 *      Author: Indresh Gahoi
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>



void create_process()
{
	key_t segment_id;
	char *sharedAddress;
	int i,j;
	pid_t pid;
	segment_id=shmget(IPC_PRIVATE,1024,0666);
	sharedAddress=(char *)shmat(segment_id,NULL,0666);
	pid=fork();
	if(pid)
	{
		printf("\nthis is parent process..\n");
		char s[]="parant proces is sharing data...";
		sprintf(sharedAddress,s);

			printf("\nparents wait is over..\n");
		shmdt(sharedAddress);
		shmctl(segment_id,IPC_RMID,NULL);
		//if(wait(&i)==pid);
	}
	else
	{
		child_process(sharedAddress);
	}
}

void child_process(char *sharedAddress)
{
	printf("\nwe are inside child process\n");

	printf("\nchild get data shared by parent.\n:%s\n",sharedAddress);

	exit(0);
}

int main()
{
   create_process();
   return 0;
}

