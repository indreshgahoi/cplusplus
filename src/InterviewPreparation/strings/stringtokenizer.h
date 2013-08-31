/*
 * stringtokenizer.h
 *
 *  Created on: Aug 4, 2013
 *      Author: Indresh Gahoi
 */

#ifndef STRINGT_OKENIZER_H_
#define STRING_TOKENIZER_H_

#include<stdio.h>
#include<stdint.h>
#include<unistd.h>


struct StringTokenizer
{

	char *buffer;
	char *end;
	size_t size;
	char *position;

};

void string_tokenizer_init(struct StringTokenizer **tokenizer);
void string_tokenize(struct StringTokenizer* tokenizer,const char *charStraem, const char *spertor_list);
short int hasMoreTokens(struct StringTokenizer* tokenizer);
const char * nextToken(struct StringTokenizer* tokenizer);
void string_tokenizer_destroy(struct StringTokenizer **tokenizer);
#endif /* STRINGTOKENIZER_H_ */
