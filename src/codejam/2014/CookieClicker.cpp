/*
 * CookieClicker.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/codejam/2014/CookieClicker.cpp -o /usr/build/Main.o
 *
 *  Created on: Apr 12, 2014
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<climits>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>

using namespace std;

int main() {
	int T;
	double X, C, F, now, time, rate;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%lf%lf%lf", &X, &C, &F);
	//	printf("%f : %f : %f \n",X,C,F);
		time = now = 0.0;
		rate = 2.0;

		while (true) {
			double t1 = X / rate;
			double t2 = (C - now) / rate ;

			if((X/(rate+F)+t2)  (t1) ){
				rate += F ;
				time += t2 ;
				now =  0 ;
			}else {
				time += t1 ;
				now = X ;
			}
		}
		printf("Case #%d: %f\n",t,time) ;
	}
	return 0 ;
}
