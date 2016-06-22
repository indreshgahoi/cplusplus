/*
 * SerajaEditDist.cpp
 *
 *  Created on: Oct 6, 2014
 *      Author: indresh
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<algorithm>

#define DEBUG
using namespace std ;
#define MAX_SIZE  100003

char S[MAX_SIZE],T[MAX_SIZE] ;
int  H[MAX_SIZE];

void solve(){
	int k , a , b ,i,j,top,cost,E,time,rc ;
	scanf("%s%s",&S[1],&T[1]);
	scanf("%d%d%d",&a,&b,&k);


	if(a==0){
		printf("0\n");
		return ;
	}


	int m = strlen(&S[1])  , n = strlen(&T[1]) ;

	H[0] = 0 ;
	cost = a ;
	int s = 0 , e = 0 ;
	for(i = 1 ; i <= m ; ++i)
		H[i] = H[i-1] + cost  ;

	for(int i = 1 ; i <= n ; ++i){

    	s = e = i-1 ;
    	while(s >=0 && H[s] <= k) s-- ;
    	while(e<=m && H[e] <=k ) e++;
        s++;




        cost = H[s];
        H[s] = H[s] + a ;
    	for(int j = s+1 ; j <= e ; ++j){

    		if(S[j]==T[i]) E = cost ;
    		else E = min(H[j]+a,min(H[j-1] + a,cost + b));
    		cost = H[j] ;
    		H[j] = E ;
    	}
//    	for(int j = s ; j <=e ; ++j){
//    		printf("H[%d]=%d ",j,H[j]);
//    	}
//    	printf("\n");
    }

    if(H[m] <= k){
    	printf("%d\n",H[m]);
    }else {
    	printf("-1\n");
    }
}



int main(){

//	freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
	int T ;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0 ;
}

