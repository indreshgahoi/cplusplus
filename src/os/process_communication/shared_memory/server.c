/*
 * server.c
 *
 *  Created on: May 12, 2013
 *      Author: Indresh Gahoi
 */


#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#include "shared_memory.h"


int main(int argc,char* argv[])
{

	key_t shmKey;
	int shmId;
	struct Memory *shmPtr;

	if(argc!=5)
	{
		printf("USE: %s #1 #2 #3 #4\n",argv[0]);
		exit(1);
	}

	shmKey=ftok(",",'a');

	shmId=shmget(shmKey,sizeof(struct Memory),IPC_CREAT|0666);

	if(shmId<0)
	{
		printf("***shmget error (server)\n");
		exit(1);
	}

	printf("server has received a shared memory for four integer...\n");

	shmPtr=(struct Memory *)shmat(shmId,NULL,0);

	if(((int)shmPtr)==-1)
	{
		printf("shmat error (server)\n");
		exit(1);
	}

	printf("server has attached the shared memory...\n");
    shmPtr->status=NOT_READY;
	shmPtr->data[0]=atoi(argv[1]);
	shmPtr->data[1]=atoi(argv[2]);
	shmPtr->data[2]=atoi(argv[3]);
	shmPtr->data[3]=atoi(argv[4]);

	printf("server has filled %d %d %d %d in shared memory...\n",
			shmPtr->data[0],shmPtr->data[1],shmPtr->data[2],shmPtr->data[3]);


	shmPtr->status=FILLED;
	printf("please start the client another window...\n");

	while(shmPtr->status!=TAKEN)
		sleep(1);

  printf("server detected the completion of its child process...\n");

	shmdt((void *)shmPtr);  //shmdt syscall to detached the shared memory

	printf("server has detached its shared memory...\n");

	shmctl(shmId,IPC_RMID,NULL);

	printf("server has removed its shared memory...\n");

	printf("server exits...\n");

	exit(0);

}

