/*
 * mycat.c
 *
 *  Created on: Sep 1, 2013
 *      Author: Indresh Gahoi
 */


#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<fcntl.h>


void typefile(char *filename){

	int fd,nread;
	char buf[1024];

	fd=open(filename,O_RDONLY);

	if(fd==-1){
		perror(filename);
		return;
	}

	while((nread=read(fd,buf,sizeof(buf)))>0)
		write(1,buf,nread);

	close(fd);

}



int main(int argc,char **argv){

	int argn;

	for(argn=1;argn<argc;++argn)
		typefile(argv[argn]);

	exit(0);
}



