/*
 * CodeParsing.cpp
 *
 *  Created on: Dec 16, 2012
 *      Author: indresh
 */

#include <iostream>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
char str[1000005];
int main(){

scanf("%s",str);
int x=0,y=0;
int i=0;

while(str[i]!='\0'){
	if(str[i]=='x')
		x++;
	else y++;
}

if(x>y){
	for(int i=0;i<(x-y);i++){
		cout<<"y";
	}
   }
else{
	for(int i=0;i<(y-x);i++){
			cout<<"x";
		}
	}
return 0;
}




