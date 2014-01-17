/*
 * KMPStringMatching.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/strings/KMPStringMatching.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 6, 2013
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std ;


/* Definition of prefix function
 * Given a pattern of characters P[1....q] match T[s+1 ....s+q]
 * What is leat shift s' > s such that k < q
 *
 * P[1....k] = T[s'+1....s'+k]
 *
 * In other words Pq is suffix of Ts+q  we want longest proper prefix Pk of Pq
 * that is also a suffix of Ts+q
 *   s'+ k = s + q
 *    s' = s + (q-k)
 *  Pf:{1,2,....m}-> {0,1....m-1}
 *
 * pf(q) = max{k : k< q and Pk suffix of Pq }
 */


void compute_prefix_function(string &P , int *prefix_fn){

	int len = P.size() ;
	prefix_fn[0] = 0 ;

	int k = 0 ;
	for(int q = 1 ; q < len ; ++q){

		while( k > 0 && P[k]!=P[q])
			k = prefix_fn[k] ;
		if(P[k]==P[q])
			k = k+1;
		prefix_fn[q] = k ;
	}
}


void KMPMatcher(string &T ,string &P){
	int n = T.size();
	int m = P.size() ;

	int *pi = new int[m];
	compute_prefix_function(P,pi);
	int q = 0 ;
	for (int i = 0 ; i < n ; ++i)
	{
		while( q > 0 && P[q] != T[i])
			q = pi[q] ;
		if(P[q]==T[i])
			q = q + 1 ;
		if(q==m){
			printf("pattern occur with shift %d \n",i-m+1);
			q= pi[q] ;
		}
	}
	delete pi   ;
}


void test_0_KMPMatcher(){

	 string P("ABABCABAB");
	 string T("ABABDABACDABABCABAB");
     KMPMatcher(T,P);
}



int main(){
	test_0_KMPMatcher();
	return 0 ;
}




