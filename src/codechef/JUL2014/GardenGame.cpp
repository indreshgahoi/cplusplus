/*
 * GardenGame.cpp
 *
 *  Created on: Jul 12, 2014
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include <assert.h>
#include<cstring>
#include<limits.h>
using namespace std;

#define MAX 100005
int currentArray[MAX];
int stepsArray[MAX];

int MOD = 1000000007;
int T;


int powmod(int base, int expo) {
	if (expo == 0)
		return 1;
	else if (expo & 1)
		return (long long) base * powmod(base, expo - 1) % MOD;
	else {
		int root = powmod(base, expo >> 1);
		return (long long) root * root % MOD;
	}
}


int main() {
	int T, N;
	map<int,int> p ;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		N++;
		for (int i = 1; i < N; ++i) {
			int x;
			scanf("%d", &x);
			currentArray[i] = x;
			stepsArray[i] = 0;
		}
		int currentIndex, steps;
		p.clear();
		for (int i = 1; i < N; ++i) {
			if (stepsArray[i] == 0) {
				steps = 0;
				currentIndex = i;
				do {
					steps++;
					stepsArray[currentIndex] = 1 ;
					currentIndex = currentArray[currentIndex];
				} while (currentIndex != i);

				//printf("cycle length:%d\n", steps );
				for(int d = 2 ; d * d <= steps ; d+= 1){
                     int maxPow = 0 ;
                     while((steps % d) == 0){
                    	 maxPow++ ;
                    	 steps/= d ;
                     }
                     if(maxPow){
                    	p[d] = max(p[d],maxPow);
                     }
				}
				if(steps != 1){
					p[steps] = max(p[steps],1);
				}

			}
		}


          long long mul = 1;
          map<int,int>::iterator it = p.begin() ;
          for(; it != p.end();++it){
        	  mul = (mul * powmod(it->first,it->second)) % MOD ;
          }



		printf("%lld\n", mul);
	}
	return 0;
}

