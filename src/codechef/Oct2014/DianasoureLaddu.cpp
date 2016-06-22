/*
 * DianasoureLaddu.cpp
 *
 *  Created on: Oct 5, 2014
 *      Author: indresh
 */

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

int D[100001], n, v, d;
int main() {
	//freopen("input.txt","rt",stdin);
	//freopen("output.txt","wt",stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		v = d = -1;
		for (int i = 0; i < n; ++i) {
			scanf("%d", D + i);
			if (d < 0) {
				if (D[i] < 0) {
					d = i;
				}
			}
			if (v < 0) {
				if (D[i] > 0) {
					v = i;
				}
			}
		}

		long long int cost = 0 ;
		for(int i = v ; i < n ; ++i){

			while(d < n && D[i] > 0 && D[d] < 0){
				//printf("d : %d  i : %d\n",d,i);
				if(abs(D[i]) <= abs(D[d])){
					cost += (((long long int)D[i]) * abs(d-i)) ;
					D[d]+=D[i];
					D[i] = 0 ;
				}else {
					cost += (((long long int) abs(D[d])) * abs(d-i));
					D[i]+= D[d];
					D[d] = 0 ;
				}
				while(d < n && D[d] >= 0) d++;
			}
		}
		printf("%lld\n",cost);
	}
	return 0;
}

