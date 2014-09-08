/*
 * GussingGame.cpp
 *
 *  Created on: Jun 15, 2014
 *      Author: Indresh Gahoi
 */



#include<iostream>
#include<cstdio>

using namespace std ;


long long int GCD(long long int a , long long int b){

	if(b==0) return a ;
	return GCD(b,a%b);
}



int main(){
	int T;
	long long int N,M ;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&N,&M);
        long long int possibleSum = (((N+1)>>1) * (M>>1)) + (((M+1)>>1) * (N>>1)) ;
        long long int total = N * M ;
        long long int gcd =  GCD(total,possibleSum) ;
        printf("%lld/%lld\n",possibleSum/gcd,total/gcd);
 }

 return 0 ;
}




