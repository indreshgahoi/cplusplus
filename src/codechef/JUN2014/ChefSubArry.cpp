/*
 * ChefSubArry.cpp
 *
 *  Created on: Jun 16, 2014
 *      Author: Indresh Gahoi
 */



#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(){
	int N , A ,len = 0 , MAX = 0;
	scanf("%d",&N);
	while(N--){
		scanf("%d",&A);
		if(A!=0){
			len++;
		}
		else {
			MAX=max(MAX,len);
			len = 0 ;
		}
	}
		MAX = max(MAX,len);
	printf("%d\n",MAX);

	return 0 ;
}
