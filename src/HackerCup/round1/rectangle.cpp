/*
 * rectangle.cpp
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
#define N 5000
using namespace std;
//int a[N][N],n,m;
//int dp[N][N];
vector<int> d(N,-1);



bool mon[N][N];
int main()
{
	freopen("input.txt","rt",stdin);
	//freopen("output.out","wt",stdout);
	int T;
	scanf("%d",&T);
	for(int u=1;u<=T;u++){
		int i,j,k,t,m,n,f,ans=0,W,H,P,Q,X,Y,a,b,c,d3,z,fl;

		scanf("%d%d%d%d%d%d%d%d%d%d%d",&W,&H,&P,&Q,&n,&X,&Y,&a,&b,&c,&d3);

		int res=0;
		// memset(mon,1,sizeof(mon));
		for(i=0;i<=H;i++){
			for(j=0;j<=W;j++)
				mon[i][j]=1;
		}
		mon[Y][X]=0;
		int pX=X,pY=Y;
		//  cout<<" X="<<X<<" Y= "<<Y<<endl;
		//x[i] = (x[i - 1] * a + y[i - 1] * b + 1) % W (for 0 < i < N)
		//y[i] = (x[i - 1] * c + y[i - 1] * d + 1) % H (for 0 < i < N)
		printf("n:%d\n",n);
		for( j=2;j<=n;j++){
			X=(pX*a+pY*b+1)%W;
			Y=(pX*c+pY*d3+1)%H;
			mon[Y][X]=0;
			printf("%d%d ",Y,X);
			//   cout<<" X="<<X<<" Y= "<<Y<<endl;
			pX=X;
			pY=Y;
		}
		printf("print matrix\n");
		for(i=0;i<H;i++){
			for(j=0;j<W;j++)
				printf("%d",mon[i][j]);
			printf("\n");
		}
		m=W,n=H;
		vector<int> d1(N),d2(N);
		stack<int> st;
		for(j=0;j<m;j++){
			d[j]=-1;}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(mon[i][j]==0)
					d[j]=i;

			}

			while(!st.empty()) st.pop();
			for(j=0;j<m;j++)
			{
				while(!st.empty()&&d[j]>=d[st.top()])st.pop();
				d1[j]=st.empty()?-1:st.top();
				st.push(j);
			}
			// cout<<"value of d1"<<endl;
			//   for(j=0;j<m;j++)
			//  	cout<<"  "<<d1[j];
			while(!st.empty()) st.pop();
			for(j=m-1;j>=0;j--)
			{
				while(!st.empty()&&d[j]>=d[st.top()]) st.pop();
				d2[j]=st.empty()?m:st.top();
				st.push(j);
			}
			// cout<<"value of d2"<<endl;
			//   for(j=0;j<m;j++)
			//	cout<<"  "<<d2[j];
			//int z=0,fl=1;
			z=0;fl=1;
			cout<<"P="<<P<<"Q="<<Q<<endl;
			for(j=0;j<m;j++)
			{
				//cout<<"z="<<z<<endl;
				//	if(z>0&&z--)
				//	continue;
				cout<<" j="<<j<<" width= "<<(d2[j]-j)<<endl;
				if((i-d[j])>=Q &&((d2[j]-j)>=P)){
					cout<<"P="<<(i-d[j])<<" Q="<<(d2[j]-d1[j]-1)<< " i="<<i<<" j="<<j<<endl;
					res++;
					/*if(fl)
    		{	z=P-1;
    			cout<<" z="<<z<<endl;

    			fl=0;
    		}*/
				}
				//cout<<res<<endl;
				// printf("%d\n",(i-d[j])*(d2[j]-d1[j]-1));
			}
		}

		//  printf("%lld\n",(long long)ans*f);
		printf("%d\n",res);
	}

	return 0;
}




