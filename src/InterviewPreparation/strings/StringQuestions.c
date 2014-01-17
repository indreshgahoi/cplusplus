#include <stdio.h>
#include <string.h>


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
