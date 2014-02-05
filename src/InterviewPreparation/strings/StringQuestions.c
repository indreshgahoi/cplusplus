#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define NO_OF_CHAR 256

char* RemoveDulpiCateChar(char *str)
{
    
    char *nextPos = str ,*currPos = str;
    
    int char_map[NO_OF_CHAR] = {0} ;
    
    while (*currPos != '\0')
    {
        if(!char_map[*currPos])
        {
            *nextPos = *currPos ;
            nextPos++ ;
        }
        char_map[*currPos] ++ ;
        
        currPos++ ;
    }
   
    *nextPos = '\0' ;
    
    return str ;
}


char* RemoveDuplicate(char *inStr , char *fromStr)
{
    
    int char_map[NO_OF_CHAR] ;
    memset(char_map, 0, sizeof(char_map)) ;
    char *nextStr , *currStr;
    while(*fromStr)
    {
        char_map[*fromStr++]++ ;
    }

    nextStr = inStr ;
    currStr = inStr ;

    while(*nextStr)
    {
        if(!char_map[*currStr])
        {
            *nextStr = *currStr ;
            nextStr++ ;
        }
        
        currStr++ ;
    }
    
    return inStr ;
}


void PrintAllDuplicates(char *str)
{
    int char_map[NO_OF_CHAR] ;
    int i = 0 ;
    memset(char_map, 0, sizeof(char_map)) ;
    while(*str)
    {
        char_map[*str++]++ ;
    }
    for( i = 0 ; i < NO_OF_CHAR ; ++i)
    {
        if(char_map[i] > 1) // that means it is Duplicate
        {
            printf("%c ==> %d  ",i,char_map[i]) ;
        }
    }
}


int CheckRoatation(char *str1 , char *str2)
{
	size_t len1 = strlen(str1) ;
	size_t len2 = strlen(str2) ;
    char *str1Double , *ret ;

    if(len1 != len2) return 0 ;
	str1Double = (char *) malloc(sizeof(*str1Double)*((len1<<1)+1)) ;

	strcpy(str1Double,str1);
	strcpy(str1Double+len1,str1) ;

	ret = strstr(str1Double,str2) ;
	if(ret != 0)
	{
          printf(" %s \n",ret) ;
          free(str1Double) ;
          return 1 ;
	}
	free(str1Double) ;
  return 0 ;
}

void PrintReverseRecurr(char *str)
{
	if(*str)
	{
		PrintReverseRecurr(str+1) ;
		printf("%c",*str);
	}
}

void swap(char *a , char *b)
{
	char t = *a ;
	*a = *b ;
	*b = t ;
}

void PrintAllPermutation(char *str , int start ,int end)
{
	int iter = 0 ;
	if(start==end)
	{
		printf("%s\n",str);
	}
	else
	{
		for( iter = start ; iter <= end ; ++iter)
		{
             swap(str+iter,str+start);
			 PrintAllPermutation(str,start+1,end);
             swap(str+iter,str+start);
		}
	}
}

void DivideStringNEqualParts(char *str , int n)
{
      size_t len = strlen(str) ;
      int iter=0, prt_size ;
      if((((int)len) % n) != 0)
      {
    	  perror("Input is Invalid\n") ;
    	  return ;
      }

      prt_size = len/n ;
      for(;*str;str++,iter++)
      {
    	  if((iter%prt_size)==0)
    	  {
    		  printf("\n") ;
    	  }
    	  printf("%c",*str) ;
      }

}

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

char* FirstNonRepeatingV2(char *str)
{

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
    	 FirstNonRepeating(str);
    	 printf("\n");
     }
	return 0 ;
}

