/*
 d * minimumSteptoEqualSalary.cpp
 *
 *  Created on: Jan 4, 2013
 *      Author: indresh
 */
#include<iostream>
#include <fstream>
#include <string>
#include<cstdio>
#include<algorithm>
#define MAX_INT 1000000
#define FOR(i,s,e) for(int i=s;i<=e;i++)
#define REP(i,n)   for(int i=0;i<n;i++)
#define si(i)      int i; scanf("%d",&i);
#define gi(i)       scanf("%d",&i);
using namespace std;
typedef int Integer;

Integer T;
Integer A[105];

Integer main(){
#ifndef ON_LINE_JUDGE
   // freopen("input.txt","rt",stdin);
   // freopen("output.txt","wt",stdout);
  #endif
	   // ofstream fout ("ride.out");
	   // ifstream fin ("ride.in");
Integer T,m;
long sum=0;
     gi(T)
     while(T--)
     {
    	 si(n)
    	 sum=0;
    	 m=MAX_INT;
      REP(i,n){
        gi(A[i])
        m=min(m,A[i]);
        sum+=A[i];
    	 }
     printf("%ld\n",(long)(sum-(n*m)));

     }
	return 0;
}



