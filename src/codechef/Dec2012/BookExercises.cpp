/*
 * BookExercises.cpp
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
#define EVER          while(1)
#define  dbgi(x)  printf(#x" = %d\n",x);
#define  dbgll(x) printf(#x" = %ll\n",x);
#define gi(i)         scanf("%d",&i);
#define gll(i)        scanf("%lld",&i);
#define gd(i)         scanf("%f",&i);
#define gui(i)        scanf("%u",&i);
#define gull(i)       scanf("%ull",&i);
#define gs(s)         scanf("%s",s);
#define gdi(m,n) scanf("%d%d",&m,&n);
#define ps(s) printf("%s\n",s);
#define pi(i) printf("%d\n",i);
#define pll(i) printf("%ll\n",i);
#define pd(i)  printf("%f\n",i);
#define sl(s)  strlen(s)
#define nl   puts("");
#define mcl(buff) memset(buff,0,sizeof(buff));
#define mst(buff,val) memset(buff,val,sizeof(buff));
#define f first
#define s second
#define x   f
#define y   s.f
#define z   s.s
#define N 1000000
#define pb push_back
#define mp make_pair
#define mt(a,b,c) mp(a,mp(b,c))

using namespace std;

typedef long long int LL;
typedef int I;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef vector<int> VI;
typedef pair< int,pair< int,int > > tri;



struct info{
	string s1;
	int idx;
	int ex;
	struct info *min;
	struct info *pre;
	};

int main(){
	I T;
	info *pre=NULL,*current;
	gi(T)
	 int m=0;
	 //int min=1000001;
	while(T--){
	 int n;
	 gi(n)

	 if(n==-1){
		 cout<<current->idx-current->min->idx<<" "<<current->min->s1<<"\n";
		// printf("min=%d\n",min);
		 current=current->min->pre;
		 pre=current;
        if(current)
         m=current->idx;
        else
         m=0;
	 }else if(n==0){
		string s;
		cin>>s;
	 }
	 else{
		 m++;

		info *temp=new info;
		current=temp;
		temp->idx=m;

		temp->ex=n;
        string s;
		//cin>>s;

		//1temp->s1=string(s);
        cin>>temp->s1;


		//temp->s1=s;
		if(pre && pre->min->ex<n)
		{
			temp->min=pre->min;
			temp->pre=pre;
			//cout<<"pre info  \n"<<pre->idx<<" "<<pre->s1 ;
           //cout<<"current info \n"<<current->idx<<current->s1;
			pre=temp;
		}
		else if(pre==NULL)
		{
			temp->min=temp;
			temp->pre=NULL;
			pre=temp;


			//cout<<"pre info  \n"<<pre->idx<<" "<<pre->s1 ;
           //cout<<"current info \n"<<current->idx<<current->s1;

		}
		else{
			temp->min=temp;
		    temp->pre=pre;
		  //  cout<<"pre info  \n"<<pre->idx<<" "<<pre->s1 ;
         //	cout<<"current info \n"<<current->idx<<current->s1;
		    pre=temp;
		}


	 }

	}
	return 0;
}


