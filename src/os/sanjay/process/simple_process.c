/*
 * simple_process.cpp
 *
 *  Created on: May 12, 2013
 *      Author: Indresh Gahoi
 */

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#define   MAX_COUNT  3
#define   BUF_SIZE   100

void create_process()
{
   pid_t pid;
   int i,check=5;
   char   buf[BUF_SIZE];
   pid=fork();
   if(pid)
   {
	   printf("\nthis is parent process...id:%d\n",pid);
	   pid_t p= wait(&i);
	   printf("\nparent was waiting for the child process:%d\n",i);
	   printf("\nvalue of i before change:%d\n",check);
	   check=100;
	   printf("\nvalue of i before change:%d\n",check);

   }
   else
   {
	   printf("\n this is child process...id:%d\n",getpid());
	   printf("\nvalue of i before change:%d\n",check);
	   printf("\nvalue of i before change:%d\n",check);
   }
//   for (i = 1; i <= MAX_COUNT; i++) {
//        sprintf(buf, "\nThis line is from pid %d, value = %d\n", pid, i);
//        write(1, buf, strlen(buf));
//        }
}

int main()
{

   create_process();
   return 0;
}


