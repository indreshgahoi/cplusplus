/*
 * ChefForgs.cpp
 *
 *  Created on: Jul 12, 2014
 *      Author: Indresh Gahoi
 */


#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAX 100001
int indexArray[MAX];
int forgsPosition[MAX] ;
int groups[MAX];
int N , P,K ;
int X , Y ;
int comp(int i , int j){
	return forgsPosition[i] < forgsPosition[j] ;
}

int main(){

	scanf("%d%d%d",&N,&K,&P);
    for(int i = 0 ; i < N ; ++i){
    	indexArray[i] = i ;
    	scanf("%d",&X);
    	forgsPosition[i] = X ;
    }
    sort(indexArray,indexArray+N,comp);


    groups[indexArray[0]] = 0 ;
    for(int i = 1 ; i < N ; ++i){
         if((forgsPosition[indexArray[i]]-forgsPosition[indexArray[i-1]]) <=K ){
        	 groups[indexArray[i]] = groups[indexArray[i-1]] ;
         }else {
        	 groups[indexArray[i]] = groups[indexArray[i-1]]+1 ;
         }
    }

    for(int i = 0 ; i < P ; ++i){
    	scanf("%d%d",&X,&Y);
    	if(groups[X-1]==groups[Y-1]){
    		printf("Yes\n");
    	}else {
    		printf("No\n");
    	}
    }
    return 0 ;

}


