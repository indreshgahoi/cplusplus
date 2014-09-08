/*
 * ProblemA.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/codeforces/DIV248/ProblemA.cpp -o /usr/build/Main.o
 *
 *  Created on: May 24, 2014
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<climits>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>

using namespace std;

int main(){
	int n ;
	cin >> n ;

	int c1 = 0 , c2 = 0 ;
	int x ;
	for(int i = 0 ; i < n ; ++i){
		cin >> x ;
		if(x==100){
			c1++ ;
		}
		if(x==200){
			c2++ ;
		}
	}

	if(c1 & 1){
		cout<<"NO";
	}else{
		if(c2 & 1){
			c1 = c1-2 ;
			c2++ ;
			if(c1 >= 0 && c1 % 2== 0 ){
				cout<<"YES";
			}else{
				cout<<"NO";
			}

		}else{
			cout<<"YES";
		}
	}

	return 0;
}
