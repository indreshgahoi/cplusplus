/*
 * allCharWordinList.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/strings/allCharWordinList.cpp -o /usr/build/Main.o
 *
 *  Created on: Jan 18, 2014
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<climits>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>

using namespace std;

#define NO_OF_CHAR 256


void PrintAllWordInList(char *strings[] , size_t size , char *word)
{

	int char_hash[NO_OF_CHAR] ;
	memset(char_hash,0,sizeof(char_hash)) ;
	char *wordIter = word ;
	int listIter = 0 , count , target = 0 ;
	while(*wordIter)
	{
		if(!char_hash[*wordIter])
		{
			char_hash[*wordIter]=1 ;

		}
	 wordIter++ ;
	}
	target = wordIter - word ;
	for(listIter = 0 ; listIter<size ; ++listIter)
	{
		wordIter = strings[listIter] ;
		count = 0;
		while(*wordIter)
		{
			if(char_hash[*wordIter])
			{
				char_hash[*wordIter]= 0 ;
				count++ ;
			}
			wordIter++ ;
		}

		if(count==target)
		{
			printf("%s\n",strings[listIter]) ;
		}
		wordIter = word ;
		while(*wordIter)
		{
			if(!char_hash[*wordIter])
			{
				char_hash[*wordIter]=1 ;
			}
			wordIter++ ;
		}
	}

}


#define MAX_LEN 10005
#define ARRAY_SIZE(A)  (sizeof(A)/sizeof(*A))
int main(){

	FILE *fin = fopen("input.txt","rw");

	char *strings[] = {"sunday", "geeksforgeeks", "utensils", "just" , "sss","nus"} ;
	char *word = "sun" ;

     PrintAllWordInList(strings,ARRAY_SIZE(strings),word) ;

	return 0;
}
