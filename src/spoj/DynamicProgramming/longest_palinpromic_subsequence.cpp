/*
 * longest_palinpromic_subsequence.cpp
 *
 *  Created on: Oct 23, 2013
 *      Author: Indresh Gahoi
 */


#include<iostream>
#include <cstring>
#include<cstdio>
#define Max(a,b)  ((a)>(b)? (a) : (b))
using namespace std;


int longest_palindromic_subsequence_rec(char *seq , int i, int j){

 // Base Case
 if(i==j) return 1;

 if(seq[i]==seq[j] && j==(i+1)) return 2;

 if(seq[i]==seq[j])
	 return longest_palindromic_subsequence_rec(seq,i+1,j-1)+2;

 return Max(longest_palindromic_subsequence_rec(seq,i,j-1),longest_palindromic_subsequence_rec(seq,i+1,j));
}


int main(){

  char *str="GEEKSFORGEEKS";
  int len=strlen(str);

  len=longest_palindromic_subsequence_rec(str,0,len-1);
  printf("Length of seq %d\n",len);
 return 0;
}
