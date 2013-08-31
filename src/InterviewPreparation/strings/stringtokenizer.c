/*
 * stringtokenizer.c
 *
 *  Created on: Aug 4, 2013
 *      Author: Indresh Gahoi
 */

#include"stringtokenizer.h"
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

enum Quotestate
{
  NOQuote=0,
  SingleQuote,
  DoubleQuote
};



 void string_tokenizer_init(struct StringTokenizer **tokenizer)
{

   *tokenizer=(struct StringTokenizer *)malloc(sizeof(struct StringTokenizer));


     (*tokenizer)->position=0;
     (*tokenizer)->end=0;
     (*tokenizer)->buffer=0;
     (*tokenizer)->size=0;
}


 void  string_tokenize(struct StringTokenizer* tokenizer,const char *charStream,const char *separtor)
{


   if(tokenizer==0)
	{
		fprintf(stderr,"tokenizer is null");
		exit(0);
	}

	if(*charStream=='\0')
	{
		tokenizer->position=0;
		 return ;
	}

	size_t len=strlen(charStream)+1;

    if(tokenizer->size<len)
    {
    	if(tokenizer->buffer)
    		free(tokenizer->buffer);
    	tokenizer->buffer=malloc(len*sizeof (char));
    	tokenizer->size=len;
    	tokenizer->position=0;
    }


   tokenizer->end=tokenizer->buffer;

    enum Quotestate quoteState=NOQuote;
    for(;*charStream!='\0';++charStream)
    {
        const char *x=strchr(separtor,*charStream);

    	if( *charStream=='"' && !quoteState)
    		quoteState=DoubleQuote;
    	else if(*charStream=='\'' && !quoteState)
    			quoteState=SingleQuote;
    	else if((*charStream=='"' && quoteState==DoubleQuote)
    			||(*charStream=='\'' && quoteState==SingleQuote))
    		  quoteState=NOQuote;
    	else if(x && !quoteState)
    	      *tokenizer->end++=0;
    	else
    		*tokenizer->end++=*charStream;

    }

     *tokenizer->end=0;

     if(tokenizer->end-tokenizer->buffer<1)
    	 tokenizer->position=0;
     else
    	 tokenizer->position=tokenizer->buffer;
}


short int hasMoreTokens(struct StringTokenizer *tokenizer)
{
	if(tokenizer==0)
	{
		fprintf(stderr,"tokenizer is null");
		exit(0);
	}

	return tokenizer->position!=0;
}


const char * nextToken(struct StringTokenizer *tokenizer)
{
	const char *ret;
	if(tokenizer==0)
	{
		fprintf(stderr,"tokenizer is null");
	}
 do{
    ret=tokenizer->position;
    tokenizer->position+=strlen(tokenizer->position)+1;


    if(tokenizer->position>=tokenizer->end){
    	tokenizer->position=0;
    	break;
    }
 }while(strlen(ret)==0);
    return ret;
}



void string_tokenizer_destroy(struct StringTokenizer **tokenizer)
{


	if((*tokenizer)->buffer)
		free((*tokenizer)->buffer);
	free(*tokenizer);
	*tokenizer=0;
}
