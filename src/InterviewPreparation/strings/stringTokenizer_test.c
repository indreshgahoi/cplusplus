/*
 * stringTokenizer_test.c
 *
 *  Created on: Aug 4, 2013
 *      Author: Indresh Gahoi
 */


#include "stringtokenizer.h"


int main()
{
char *separator="\"{},";

 char string[1024];

 gets(string);
 struct StringTokenizer *st=NULL;
 int i=0;
 string_tokenizer_init(&st);



 string_tokenize(st,string,separator);


 while(hasMoreTokens(st))
 {
	 puts(nextToken(st));
 }
 string_tokenizer_destroy(&st);
 getchar();
 return 0;
}
