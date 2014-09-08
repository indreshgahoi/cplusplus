/*
 * CountSubstrings.c
 *
 *  Created on: Jul 8, 2014
 *      Author: Indresh Gahoi
 */

#include<stdio.h>

int main() {
	char str[100002];
	int T,L;
	long long int count ;
	scanf("%d",&T);
	while(T--){
       count = 0 ;
       scanf("%d",&L);
       scanf("%s",str);
       while(L--){
    	   if(str[L]=='1') count++;
       }
	 printf("%lld\n",((count)*(count-1))/2 + count);
	}
	return 0;
}

