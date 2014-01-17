/*
 * AmazonStringMakeWordtext.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/strings/AmazonStringMakeWordtext.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 8, 2013
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;


/* Quetion:-
 *   Given a string containing words separated by arbitrary number of spaces.
 *   Write a function that returns a string consisting of the first letter of each
 *    word. (Note: there may be any number of spaces at the starting of the given
 *     string, at the end of the given string or in between words of the string.)
Example:
Input: ” this is a test case ”
Output: tiatc
(Function prototypes and main was given for both the questions. Although many solutions passed the initial test cases, they were rejected later as they did not satisfy boundary cases
 *
 */

vector<char> makeword(char *s){
	vector<char> res ;
    while(*s != '\0')
    {
    	while( *s != '\0' && *s==' ') s++;

    	if(*s != '\0')
    	{
    		res.push_back(*s);
    	   s++ ;
    	}

    	while(*s !='\0' && *s != ' ' ) s++;

    }
  return res ;
}

void printword(vector<char> &v)
{
	for(vector<char>::iterator it = v.begin() ; it != v.end() ; ++it)
	{
		cout<<*it;
	}
	cout<<"\n";
}

int main()
{   vector<char> res = makeword(" this is a test case ");
    printword(res);
    res = makeword("The bucket is full of water");
    printword(res);
    res = makeword("  k   ki kkkkkk ttt   ");
    printword(res);
	return 0 ;
}


