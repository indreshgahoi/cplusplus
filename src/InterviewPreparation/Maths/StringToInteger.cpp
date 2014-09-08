/*
 * StringToInteger.cpp
 *
 *  Created on: Jun 11, 2014
 *      Author: root
 */


#include<iostream>
#include<cstdio>
#include<string>
#include <fstream>
#include<istream>
#include <ostream>
#include <limits>
#include <limits.h>
using namespace std ;


class Solution{
public :

	int atoi(const char * str){

		int res = 0 ;
		char ch ;
		while(*str){
           ch = *str ;
           if(isNumeric(ch)) {
        	   	   break ;
           }
           else if(ch == '+' || ch == '-') {
        	   str++ ;
        	   break ;
           }else if(ch !=' '){
        	   return 0 ;
           }
           str++ ;
        }
		int len = 0 ;
		while(*str){
		 if(!isNumeric(*str)) break ;
		 len++;
		 if(len > 10) {
			 res = -1 ;
			 break ;
		 }
		 res = res * 10 + ((*str) - '0') ;
		 str++ ;
		}
		if(res < 0 ){
			if(ch == '-'){
				return INT_MIN ;
			}else {
				return INT_MAX;
			}
		}
		if(ch == '-'){
			res = - res ;

		}
		return res ;
	}

	inline bool isAlpha(char ch){
		return  (ch >= 'a' && ch <= 'z') || ( ch >= 'A' || ch <= 'Z');
	}
	inline bool isNumeric(char ch){
		return ( ch >= '0' && ch <= '9') ;
	}
};
int main(){
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	   string str ;
  while(fin >> str ){
	   Solution sol ;
	   fout << sol.atoi(&str[0]) << "\n";
  }
  return 0 ;
}
