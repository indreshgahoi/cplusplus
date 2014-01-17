/*
 * Median.cpp
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
#include <climits>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>

#define MAX_INT  99999999999999999

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
typedef long long ul;
multiset<ul> maxheap,minheap;
ul getMax(multiset<ul> &heap){
	if(heap.size()>0)
	{
	 multiset<ul>::reverse_iterator it=heap.rbegin();
	  return (*it);
	}

	return -MAX_INT;
}
ul getMin(multiset<ul> &heap){
	if(heap.size()>0){
	 multiset<ul>::iterator it=heap.begin();
	 return (*it);
	}
	return (MAX_INT);
}
bool isIn(multiset<ul> &mset,ul x){

	return (mset.find(x)!=mset.end());
}

void getMedian(){
	ul maxtop=(maxheap.size()==0)?0:getMax(maxheap);
	 ul mintop=(minheap.size()==0)?0:getMin(minheap);
		if(maxheap.size()==minheap.size()){
			if(((maxtop+mintop)&1)){
				printf("%.1f\n",((double)(maxtop+mintop+.0))/2.0);
			}
			else{
			printf("%lld\n",(maxtop+mintop)/2);
			}
		}
		else
			printf("%lld\n",maxtop);
}
void del(multiset<ul> &mset,ul x){
	mset.erase(mset.find(x));
}
bool remove(ul x){
	if(!((isIn(maxheap,x) && maxheap.size()!=0) ||( isIn(minheap,x) && minheap.size()!=0))){
		//cout<<"Wrong!"<<endl;
		return false;
	}
	else
	{
		ul maxtop,mintop;
      if(maxheap.size()>minheap.size()){
    	  if(isIn(maxheap,x))
    		  del(maxheap,x);
    	  else
    	  {
    		  maxtop=getMax(maxheap);
    		   minheap.insert(maxtop);
    		   //maxheap.erase(maxtop);
    		   del(maxheap,maxtop);
    		 //  maxheap.erase(maxheap.begin());
               //minheap.erase(x);
    		   del(minheap,x);
    	  }
      }
      else{
            if(isIn(minheap,x)){
            	//minheap.erase(x);
            	 del(minheap,x);
            }
            else{
            	mintop=getMin(minheap);
            	 maxheap.insert(mintop);
            	// minheap.erase(mintop);
            	 del(minheap,mintop);
            	// minheap.erase(minheap.begin());
            	 //maxheap.erase(x);
            	 del(maxheap,x);
            }
      }
	}
	return true;
}
/*
 *  to maintain the median   (maxHeapSize,maxHeapSize+1)==minHeap or
 */
void add(ul x){
	ul maxtop,mintop;
	if(maxheap.size()<=minheap.size())
	{
		mintop=getMin(minheap);
		if(x<=mintop)
			maxheap.insert(x);
		else{
			maxheap.insert(mintop);
			//minheap.erase(mintop);
			del(minheap,mintop);
			minheap.insert(x);
		}
	}
	else{
		maxtop=getMax(maxheap);
		if(x>=maxtop)
			minheap.insert(x);
		else{
			minheap.insert(maxtop);
			//maxheap.erase(maxtop);
			del(maxheap,maxtop);
			maxheap.insert(x);
		}
	}

}

int main(){

 int op;
 scanf("%d",&op);

 char s[2], ch ;ul x;
 while(op--){
	 scanf("%s%lld",s,&x);
	// cout<<ch<<endl;
  ch=s[0];
	 switch(ch){
	 case 'r':

		 if(remove(x)){
		   if(maxheap.size()==0 && minheap.size()==0){
			   printf("Wrong!\n");
		   }
		   else{
			 getMedian();}
		 }
		 else {
			 printf("Wrong!\n");
		 }
		// cout<<"op="<<op<<" ch="<<ch<<endl;
		 break;
	 case 'a':
		 add(x);
		 //cout<<"op="<<op<<" ch="<<ch<<endl;
		 getMedian();

		 break;
	 }
 }

	return 0;
}


