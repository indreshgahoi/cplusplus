/*
 * FairWorkLoad.cpp
 *
 *  Created on: Feb 5, 2013
 *      Author: indresh
 */
#include<iostream>
#include<vector>
#define REP(i,n) for(int i=0;i<n;i++)

using namespace std;
int globalMax=0;

void generate(vector<int> f ,int start,int w,int localmax){
   if(w==1){
	   int sum=0;
	   	for(int i=start;i<(f.size()-w);i++)
	   		sum+=f[i];
	   	if(sum>localmax)localmax=sum;
	   	if(globalMax>localmax)
	   		 globalMax=localmax;

   }
	int sum=0;
	for(int i=start;i<(f.size()-w);i++){
		sum+=f[i];
		generate(f,i+1,w-1,sum>localmax?sum:localmax);
	}
	}

int getMostWork(vector<int> folder,int workers){


	REP(i,folder.size()) globalMax+=folder[i];
	generate(folder,0,workers,0);
	return globalMax;
}

int cmp(int a,int b){
	if(a>b)return 1;
	if(b>a) return -1;
	return 0;
}

int worstRank(vector <int> v){
	int x=v[0],y=v[1],z=v[2];
	int c=(x+y+z)-min(x,min(y,z));
	vector<int>::iterator it=v.begin();
	it++;i++;it++;
	sort(it,v.end());
	int sz=v.size()-3;
	int k=(sz/3)<<1;
	int rank=1;
	for(int i=0,z=sz-1;i<k;i=i+2,z--){
         if((v[3+i]+v[3+i+1]-v[z])>c)rank++;
	}
	return rank;
}


