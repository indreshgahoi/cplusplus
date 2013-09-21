/*
 * NewSyntax.c
 *
 *  Created on: Sep 20, 2013
 *      Author: Indresh Gahoi
 */

#include<stdio.h>

typedef enum {
 	Fatal_error,
 	Devide_error
} error_t ;

static const char* error_strig[2]={
		[Fatal_error]="Fatal error",
		[Devide_error]="Devide Error"
};


int main(){
	printf("%s\n",error_strig[Fatal_error]);
	printf("%s\n",error_strig[Devide_error]);
 return 0;
}
