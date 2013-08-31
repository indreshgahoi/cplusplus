/*
 * climbingStair.cpp
 *
 *  Created on: Mar 28, 2013
 *      Author: indresh
 */

#include<iostream>
#include<cstdio>
#include<sstream>
#include <vector>
using namespace std;


int climbStairs(int n) {
    if(n<3) return n;
	int n1=2,n2=1;
	for(int i=3;i<=n;i++){
		int temp=n2;
		 n2=n1;
		 n1+=temp;
	}
    return n1;

}

int main(){
	return 0;

}

