/*
 * fork_03.c
 *
 *  Created on: May 11, 2013
 *      Author: Indresh Gahoi
 */

#include<stdio.h>
#include<sys/types.h>
#include<string.h>

#define MAX_COUNT 5
#define BUFF_SIZE 100

void ChildProcess(char [],char []); // child process prototype

int main(void)
{
	pid_t pid1,pid2,pid;
	int i;
	int status;
	char buff[BUFF_SIZE];

	printf("***Parent process is about to fork process 1 ***\n");

	if((pid1=fork())<0)
	{
		printf("Faild to fork process 1\n");
		exit(1);
	}
	else if(pid==0)
	{
		ChildProcess("First","     ");
	}


	printf("***Parent process is about to fork process 2 ***\n");

	if((pid2=fork())<0)
	{
		printf("Faild to fork process 1\n");
		exit(1);
	}
	else if(pid2==0)
	{
		ChildProcess("Second","       ");
	}

	sprintf(buff,"***parent process is waiting status.....\n");
	write(1,buff,strlen(buff));

	pid=wait(&status);
	sprintf(buff,"***parent detects %d process was done***\n",pid);
	write(1,buff,strlen(buff));
	pid=wait(&status);
	sprintf(buff,"***parent detects %d process was done***\n",pid);
	write(1,buff,strlen(buff));
	printf("***parent exits***\n");
	exit(0);

}


void ChildProcess(char* number,char *space){

	pid_t  pid;
	int    i;
	char   buf[BUFF_SIZE];

	pid = getpid();
	sprintf(buf, "%s%s child process starts (pid = %d)\n",space, number, pid);
	write(1, buf, strlen(buf));

	for (i = 1; i <= MAX_COUNT; i++)
	{
		sprintf(buf, "%s%s child's output, value = %d\n", space, number, i);
		write(1, buf, strlen(buf));
	}
	sprintf(buf, "%s%s child (pid = %d) is about to exit\n",space, number, pid);
	write(1, buf, strlen(buf));
	exit(0);
}



