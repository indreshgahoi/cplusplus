#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>

#define MSGKEY 19
#define TYPEKEY 19
#define SEMKEY 19

typedef struct {
        int type;
        char buf[2048];
} msg_t;

void getline (char *buf)
{
   int pointer=0;

   while (1) {
      scanf("%c", &buf[pointer]);
      if (buf[pointer] == '\n') return;
      pointer++;
   }
}

void printline(char *buf)
{
   int pointer=0;

   while (1) {
      printf("%c", buf[pointer]);
      if (buf[pointer] == '\n') return;
      pointer++;
   }
}

int main(void)
{
    char *p=getenv("USER"), buf[1024], *shm;
    msg_t msg;
    int msgid, shmid, semid, mytype, yourtype;
    struct sembuf Poplist, Voplist;

    if (p == NULL) {
       printf("Cannot get screenname. Aborting...\n");
       exit(0);
    }

    semid = semget(SEMKEY, 1, 0777);
    if (semid < 0) {
       printf("Chat server not started! Aborting...\n");
       exit(1);
    }
    shmid = shmget(TYPEKEY, 4096, 0777);
    if (shmid < 0) {
       printf("Chat server not started! Aborting...\n");
       exit(1);
    }
    shm = (char*)shmat(shmid, 0, 0);
    
    Poplist.sem_num = 0;
    Poplist.sem_op = -1;
    Poplist.sem_flg = SEM_UNDO;

    Voplist.sem_num = 0;
    Voplist.sem_op = 1;
    Voplist.sem_flg = SEM_UNDO;

    semop(semid, &Poplist, 1);
    mytype = *(int*)shm;
    (*(int*)shm)++;
    semop(semid, &Voplist, 1);
    shmdt(shm);

    if ((mytype % 2) == 0) {
       yourtype = mytype - 1;
    }
    else {
       yourtype = mytype + 1;
    }
    printf("[%d]My message type: %d, your message type: %d\n", getpid(), mytype, yourtype);

    msgid = msgget (MSGKEY, 0777 | IPC_CREAT);
    
    if ((mytype % 2) == 1) {
       while(1) {
          printf("%s>", p);
          getline(buf);
          msg.type = mytype;
          sprintf(msg.buf, "%s> %s", p, buf);
          msgsnd(msgid, &msg, 2048, 0);
          msgrcv(msgid, &msg, 2048, yourtype, 0);
          printline(msg.buf);
       }
    }
    else {
       while (1) {
          msgrcv(msgid, &msg, 2048, yourtype, 0);
          printline(msg.buf);
          printf("%s>", p);
          getline(buf);
          msg.type = mytype;
          sprintf(msg.buf, "%s> %s", p, buf);
          msgsnd(msgid, &msg, 2048, 0);
       }
    }
    return 0;
}
