/*
 * MagicRanking.cpp
 *
 *  Created on: Dec 3, 2012
 *      Author: indresh
 */

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<stack>
#include<set>
#include<cmath>
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define REP(i,n)   for(i=0;i<n;i++)



using namespace std;

typedef long long int LL;
typedef int I;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef vector<int> VI;
typedef pair< int,pair< int,int > > tri;

//int n;
double M[100][100][2];

void initialize(int n){
   int i,j;
	FOR(i,0,n-1)
     FOR(j,0,n-1)
     { int d;
		scanf("%d",&d);
		M[i][j][0]=(double)d;
		M[i][j][1]=1;
		//printf("%f\n",M[i][j][0]);
     }

	M[0][0][0]=0;
	M[0][0][1]=0;
	M[n-1][n-1][0]=M[n-1][n-1][1]=0;
}
 double solve(){
	int i,j;
	 FOR(i,1,n-1){
	    M[0][i][0]+=M[0][i-1][0];
	    M[0][i][1]=i;
	 }
	 FOR(i,1,n-1){
	 	    M[i][0][0]+=M[i-1][0][0];
	 	    M[i][0][1]=i;
	 	 }
	FOR(i,1,n-1)
	 FOR(j,1,n-1)
	 { double s1=M[i][j][0];


		if((M[i-1][j][0]+s1)/(M[i-1][j][1]+M[i][j][1])-
		(M[i][j-1][0]+s1)/(M[i][j-1][1]+M[i][j][1])>0){
			M[i][j][0]=M[i-1][j][0]+s1;
			M[i][j][1]=M[i-1][j][1]+M[i][j][1];
			// printf("%f",M[i][j][0]);
		}
		else{
			M[i][j][0]=M[i][j-1][0]+s1;
		    M[i][j][1]=M[i][j-1][1]+M[i][j][1];
		  //  printf("%f",M[i][j][0]);
		}

	 }


	return M[n-1][n-1][0]/M[n-1][n-1][1];
}

/*int main() {
	int T;

	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
				initialize(n);
		double d=solve();
		if(M[n-1][n-1][0]<0)
		 printf("Bad Judges\n");
		else
		 printf("%f\n",d);
	}
	return 0;
}*/




