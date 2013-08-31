/*
 * client.c
 *
 *  Created on: May 12, 2013
 *      Author: Indresh Gahoi
 */

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#include"shared_memory.h"

int main(void)
{
	key_t shmKey;
	int shmId;
	struct Memory *shmPtr;



		shmKey=ftok(",",'a');

		shmId=shmget(shmKey,sizeof(struct Memory),0666);

		if(shmId<0)
		{
			printf("     ***shmget error (client)\n");
			exit(1);
		}

		printf("     client has received a shared memory for four integer...\n");

		shmPtr=(struct Memory *)shmat(shmId,NULL,0);

		if(((int)shmPtr)==-1)
		{
			printf("     shmat error (client)\n");
			exit(1);
		}

		printf("     client has attached the shared memory...\n");

		while(shmPtr->status!=FILLED)
			sleep(1);
	   printf("     client fount data is ready...\n");

	   printf("     client has found %d %d %d %d in shared memory...\n",
				shmPtr->data[0],shmPtr->data[1],shmPtr->data[2],shmPtr->data[3]);

      shmPtr->status=TAKEN;
		printf("     client has infromed server data has beeen taken...\n");

		shmdt((void *)shmPtr);  //shmdt syscall to detached the shared memory

		printf("     client has detached its shared memory...\n");
        printf("     client exits...\n");

		exit(0);
}


