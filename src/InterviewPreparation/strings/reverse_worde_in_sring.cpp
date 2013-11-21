/*
 * reverse_worde_in_sring.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/strings/reverse_worde_in_sring.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 8, 2013
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<cstdio>

void reverse(char *begin, char *end)
{
  char temp;
  while (begin < end)
  {
    temp = *begin;
    *begin++ = *end;
    *end-- = temp;
  }
}


void reverseWords(char *s)
{
    char *word_begin = NULL;
    char *temp = s; /* temp is for word boundry */

    /*STEP 1 of the above algorithm */
    while( *temp )
    {
        /*This condition is to make sure that the string start with
          valid character (not space) only*/
        if (( word_begin == NULL ) && (*temp != ' ') )
        {
            word_begin=temp;
        }
        if(word_begin && ((*(temp+1) == ' ') || (*(temp+1) == '\0')))
        {
            reverse(word_begin, temp);
            word_begin = NULL;
        }
        temp++;
    } /* End of while */

    /*STEP 2 of the above algorithm */
    reverse(s, temp-1);
}
