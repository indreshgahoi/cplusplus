#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>

#define MSGKEY 19
#define TYPEKEY 19
#define SEMKEY 19

int semid, shmid;

void cleanup(void)
{
   semctl(semid, 1, IPC_RMID, NULL);
   shmctl(shmid, IPC_RMID, NULL);
}

int main(void)
{
   semid = semget(SEMKEY, 1, 0777|IPC_CREAT);
   shmid = shmget(TYPEKEY, 4096, 0777|IPC_CREAT);
   char *shm = (char*)shmat(shmid, 0, 0);
   *(int*)shm = 1;
   short initarray[1];
   int i;

   for (i=1; i<20; i++) {
      signal(i, cleanup);
   }

   initarray[0] = 1;
   semctl(semid, 1, SETALL, initarray);
   shmdt(shm);
   pause();
   return 0;
}  
