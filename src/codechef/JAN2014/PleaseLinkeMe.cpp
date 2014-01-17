/*
 * PleaseLinkeMe.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/codechef/JAN2014/PleaseLinkeMe.cpp -o /usr/build/Main.o
 *
 *  Created on: Jan 12, 2014
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

typedef long long Int64 ;

int L , S;
Int64 pow(Int64 x , Int64 y)
{
	if(y==0) return 1 ;
	Int64 t = pow(x,y/2) ;
	if( t >=L)
		return L ;
    t = t * t ;
	if(y & 1)
	{
		if((t *x* S)>= L){
			 return L ;
		}

		return  t * x ;
	}
		if((t*S)>=L)
			return L ;
		return t  ;

}



int main()
{
	int D,C,T ;
	//freopen("input.txt","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&L,&D,&S,&C);
		Int64 res = pow(1+C,D-1)  ;
        if(res >= L || (res * S) >= L)

        {
        	printf("ALIVE AND KICKING\n") ;
        }
        else
        {
        	printf("DEAD AND ROTTING\n") ;
        }

	}
	return 0;
}
