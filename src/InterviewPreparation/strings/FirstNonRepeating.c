/*
 * FirstNonRepeating.c
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/strings/FirstNonRepeating.c -o /usr/build/Main.o
 *
 *  Created on: Jan 18, 2014
 *      Author: Indresh Gahoi
 */

#include<stdio.h>
#include <string.h>
#include<malloc.h>

#define NO_OF_CHAR 256

char * FirstNonRepeatingV1(char *str)
{
    int char_map[NO_OF_CHAR] ;
    char *charIter = str ;
    int index = 0 ;

    memset(char_map,0,sizeof(char_map)) ;

    while(*charIter) char_map[*charIter++]++;

    while(*str)
    {
    	if(char_map[*str]==1)
    		break ;
    	index++ ;
    	str++;
    }

    if(*str)
    {
    	printf(" index: %d %c",index,*str) ;
    	return str ;
    }
    return 0 ;
}


struct info
{
	size_t index ;
	size_t count  ;
};

int FirstNonRepeatingV2(char *str)
{
	 struct info char_hashTable[NO_OF_CHAR] ;
     char *strIter = str  ;
     int iter , resIdx;
	 memset(char_hashTable,0,sizeof(char_hashTable)) ;

	 while(*strIter)
	 {
		 if(char_hashTable[*strIter].count==0)
		 {
			 char_hashTable[*strIter].index = strIter - str ;
		 }
		 char_hashTable[*strIter++].count++ ;
	 }
	 resIdx = strIter-str ;
	 for(iter = 0 ; iter< NO_OF_CHAR ; ++iter)
	 {
		 if(char_hashTable[iter].count == 1 && resIdx > char_hashTable[iter].index)
		 {
			 resIdx = char_hashTable[iter].index ;
		 }
	 }
 return resIdx ;
}

#define MAX_LENGTH 1005

int main()
{
	 char str[MAX_LENGTH] ;
     char str1[MAX_LENGTH] ;
     int n ;
	 FILE *fin = fopen("input.txt","rw") ;

	 while(~fscanf(fin,"%s",str))
     {
    	 printf("%s  ====> ",str) ;
    	 printf(" index :%d",FirstNonRepeatingV1(str));
    	 printf("\n");
     }
	return 0 ;
}


