/*
 * parent_child_communication.c
 *
 *  Created on: May 12, 2013
 *      Author: Indresh Gahoi
 */

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

void ChildProcess(int []);


int main(int argc,char* argv[])
{
	pid_t pid;
	int status;
	int shmId;
	int *shmPtr;

	if(argc!=5)
	{
		printf("USE: %s #1 #2 #3 #4\n",argv[0]);
		exit(1);
	}

	shmId=shmget(IPC_PRIVATE,4*sizeof(int),IPC_CREAT|0666);

	if(shmId<0)
	{
		printf("***shmget error (server)\n");
		exit(1);
	}

	printf("server has received a shared memory for four integer...\n");

	shmPtr=(int *)shmat(IPC_PRIVATE,NULL,0);

	if(((int)shmPtr)==-1)
	{
		printf("shmat error (server)\n");
		exit(1);
	}

	printf("server has attached the shared memory...\n");

	shmPtr[0]=atoi(argv[1]);
	shmPtr[1]=atoi(argv[2]);
	shmPtr[2]=atoi(argv[3]);
	shmPtr[3]=atoi(argv[4]);

	printf("server has filled %d %d %d %d in shared memory...\n",
			shmPtr[0],shmPtr[1],shmPtr[2],shmPtr[3]);

	printf("server is about to fork child process...\n");

	pid=fork();
	if(pid<0)
	{
		printf("***fork error***\n");
		exit(1);
	}
	if(0==pid)
	{
		ChildProcess(shmPtr);
		exit(0);
	}

	wait(&status);
	printf("server detected the completion of its child process...\n");

	shmdt((void *)shmPtr);  //shmdt syscall to detached the shared memory

	printf("server has detached its shared memory...\n");

	shmctl(shmId,IPC_RMID,NULL);

	printf("server has removed its shared memory...\n");

	printf("server exits...\n");

	exit(0);

}


void ChildProcess(int sharedMemory[])
{
	printf("    Client is started...\n");
	printf("    Client is found %d %d %d %d in shared memory\n",sharedMemory[0],
			sharedMemory[1],sharedMemory[2],sharedMemory[3]);
	printf("    Client is about to exit\n");
	sleep(10000);

}
