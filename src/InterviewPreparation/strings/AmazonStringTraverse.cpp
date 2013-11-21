/*
 * AmazonStringTraverse.cpp
 * run command
  g++ /Algorithm/src/InterviewPreparation/strings/AmazonStringTraverse.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 6, 2013
 *      Author: Indresh Gahoi
 */



/* Question : -
 * Given a String s and int r , first fill each character row wise and print column
 	 wise.
 for e.g. String s = “abcdefgh” and r = 3
 so filling column wise would give :
 a d g
 b e h
 c f

and final ans would be adgbehcf.
he just wanted the exact output. Internally how we handle string was not concern.
 *
 */
#include<iostream>
#include<string>
#include<cstdio>

using namespace std ;

void traverse(string &str , int r){
	int len = str.size();
	int c = (len-1)/3 +1  ;
	int count = 0 ;

	for(int i = 0 ; i < r ; ++i)
		for(int j = 0 ; j < c ; ++j)
		{
			printf("%c",str[j*c + i]);
			count ++;
			if(count == len)
				break ;
		}

}


int main(){
	string str("abcdefgh");
	traverse(str,3);
	return 0 ;
}
