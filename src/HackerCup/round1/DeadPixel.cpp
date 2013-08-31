/*
 * DeadPixel.cpp
 *
 *  Created on: Feb 3, 2013
 *      Author: indresh
 */

#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <string.h>
#include <cmath>

#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>

#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>

#define MAX_INT 9999999

#define FOR(i,s,e) for(int i=s;i<=e;i++)
#define REP(i,n)   for(int i=0;i<n;i++)
#define tr(c,i)    for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

#define dbgi(x)    printf(#x" = %d\n",x);
#define dbgll(x)   printf(#x" = %ll\n",x);
#define dbgd(x)    printf(#x" = %f\n",x);
#define nl         printf("\n");

#define gi(v)      scanf("%d",&v);
#define si(v)       int v; gi(v);
#define gll(v)     scanf("%lld",&v);
#define sll(v)     long long v;gll(v)
#define gd(v)      scanf("%f",&v);
#define sd(v)      ld v;gd(v)
#define sui(v)     scanf("%u",&v);
#define sull(v)    scanf("%ull",&v);

#define gs(s)      scanf("%s",s);
#define ps(s)      puts(s);
#define pi(i)      printf("%d\n",i);
#define pll(i)     printf("%ll\n",i);
#define pd(i)      printf("%f\n",i);

#define sl(s)  strlen(s)
#define mcl(buff) memset(buff,0,sizeof(buff));
#define mst(buff,val) memset(buff,val,sizeof(buff));
#define mp     make_pair
#define pb     push_back
#define EPS 1e-6
#define sqr(a) ((a)*(a))
#define mod 1000000007

using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef long long LL;
typedef vector<long long > vll;
typedef pair<int, int > pii;
typedef vector< pii > vpii;
#define N 500
#define miN(a,b) ((a)<(b)?(a):(b))
bool mon[N][N];
int monx[100][N],mony[100][N];
int W,H,P,Q,n,X,Y,a,b,c,d;

int solve(int P,int Q){
	int res=0;
	REP(i,W+1)
	 REP(j,H+1){
		if(i==0 || j==0)
		{
			monx[i][j]=0;
		mony[i][j]=0;
			continue;
		}
       if(mon[i-1][j-1]==0){
    	   monx[i][j]=miN(miN(monx[i-1][j-1],monx[i-1][j]),monx[i][j-1])+1;
    	   mony[i][j]=miN(miN(mony[i-1][j-1],mony[i-1][j]),mony[i][j-1])+1;
       }

       else{
    	          monx[i][j]=0;
    	       	   mony[i][j]=0;

	}
       if(monx[i][j]>=Q && mony[i][j]>=P){
    	   res++;
        cout<<"i="<<i<<" j="<<j<<endl;}
	}
	cout<<" P="<<P<<" Q="<<Q<<endl;
	REP(i,W+1){
		 REP(j,H+1){
	    cout<<	" "<<monx[i][j];
	}
		 cout<<endl;
	}
	cout<<endl;
	REP(i,W+1){
			 REP(j,H+1){
		    cout<<	" "<<mony[i][j];
		}
			 cout<<endl;
		}
	return res;
}

int main(){
	        freopen("input.txt","rt",stdin);
			freopen("output.out","wt",stdout);
	int T;
	cin>>T;
	for(int i=1;i<(T+1);i++){
		memset(mon,0,sizeof(mon));
     	cin>>W>>H>>P>>Q>>n>>X>>Y>>a>>b>>c>>d;
     	mon[Y][X]=1;
         int pX=X,pY=Y;
     	  cout<<" X="<<X<<" Y= "<<Y<<endl;
     	//x[i] = (x[i - 1] * a + y[i - 1] * b + 1) % W (for 0 < i < N)
     	//y[i] = (x[i - 1] * c + y[i - 1] * d + 1) % H (for 0 < i < N)
     	for(int j=2;j<=n;j++){
     		X=(pX*a+pY*b+1)%W;
            Y=(pX*c+pY*d+1)%H;
            mon[Y][X]=1;
            cout<<" X="<<X<<" Y= "<<Y<<endl;
            pX=X;
            pY=Y;
     	}
     	cout<<"Case #"<<i<<": "<<solve(P,Q)<<endl;
	}
	return 0;
}


