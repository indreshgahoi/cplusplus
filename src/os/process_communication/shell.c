/*
 * shell.c
 *
 *  Created on: May 11, 2013
 *      Author: Indresh Gahoi
 */

/*
 * The created child process does not have to run the same program as
 * the parent process does. The exec type system calls allow a process
 * to run any program files, which include a binary executable or a
 * shell script. On this page, we only discuss one such system call: execvp().
 * The execvp() system call requires two arguments:

 1->The first argument is a character string that contains the name of a file to be executed.
 2->The second argument is a pointer to an array of character strings. More precisely, its type is char **, which is exactly identical to the argv array used in the main program:

    int  main(int argc, char **argv)

 Note that this argument must be terminated by a zero.

When execvp() is executed, the program file given by the first argument will be loaded into
the caller's address space and over-write the program there. Then, the second argument will
be provided to the program and starts the execution. As a result, once the specified program
file starts its execution, the original program in the caller's address space is gone and is
replaced by the new program.

execvp() returns a negative value if the execution fails
(e.g., the request file does not exist).
 */

#include<stdio.h>
#include <sys/types.h>
#include<string.h>



void parse(char *line,char **argv)
{

	while(*line!='\0')
	{
		while(*line==' ' || *line=='\t' || *line=='\n')
			*line++='\0';
		*argv++=line;
		while(*line!='\0' && *line!=' ' && *line!='\t' && *line!='\n')
			line++;

	}
	*argv='\0';

}

void execute(char **argv)
{

 pid_t pid;
 int status;

  if((pid=fork())<0)
  {
	  printf("***error forking a child process\n");
	  exit(1);
  }
  else if(pid==0)
  {
	  if(execvp(*argv,argv)<0)
	  {
		  printf("***Error exec failed\n");
		  exit(1);
	  }
  }
  else {
	  while(wait(&status)!=pid);
  }

}

void main(){

	char line[1024];
	char *argv[64];

	while(1)
	{
		printf("shell->");
		gets(line);
		printf("\n");
		parse(line,argv);

		if(strcmp(argv[0],"exit")==0)
			exit(0);
		execute(argv);


	}
}

























