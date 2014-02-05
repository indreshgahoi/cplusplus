#include<stdio.h>
#include<string.h>



void RunLengthEncoding(char *str)
{
    int len = (int)strlen(str) ;
    int iter = 0 , jter , count  ;
    char *dest = (char*) malloc(sizeof(*dest) *((len<<1)+1)) ;
    char *last = dest ;
    int k ;
    for( iter = 0 ; iter < len ; )
    {
        jter = iter + 1 ;
        count = 1;
        while(iter < len && str[iter]==str[jter])
        {
            count++ ; jter++ ;
        }
        
        k=sprintf(last,"%d",count) ;
        last += k ;
        *last = str[iter] ;
        last++;
        
        iter = jter ;
    }
    *last = '\0' ;
    
    printf("character =  %s ",dest) ;
}
