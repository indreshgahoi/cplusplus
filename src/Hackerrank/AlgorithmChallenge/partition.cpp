/*
 * partition.cpp
 *
 *  Created on: Feb 26, 2013
 *      Author: indresh
 */


#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#define  mod 1000000007
using namespace std;
typedef int Integer;
vector<Integer> num;
Integer globalmax=-999999999;
Integer Max;
Integer size;





map <int , long long> P;

long long Calculate_Pn(long long n)
{
  if (n < 0)
     return 0;

  long long Pn = P[n];

  if (Pn == 0)
  {
     long long k;
     for (k = 1; k <= n; k++)
     {
         // A little bit of recursion
         long long n1 = n - k * (3 * k - 1) / 2;
         long long n2 = n - k * (3 * k + 1) / 2;

         long long Pn1 = Calculate_Pn(n1)%mod;
         long long Pn2 = Calculate_Pn(n2)%mod;

         // elements are alternately added
         // and subtracted
         if (k % 2 == 1)
            Pn = ((Pn + Pn1)%mod + Pn2)%mod;
         else
              Pn = Pn - Pn1 - Pn2;
    }
       P[n]=Pn;
  }
  return Pn;
}


void dfs(Integer start,int k,Integer sum){

	if(sum>Max || size==k || (((num.size()-start-1)+k)<(size))){

		return;
	}
	for(int i=start;i<num.size();i++){
     Integer lsum=sum+num[i];
      if(lsum<Max)
      {
    	  dfs(start+1,k+1,sum+num[i]);
    	  if(lsum>globalmax){
    		  globalmax=lsum;

    	  }
     }
      dfs(start+1,k,sum);
	}
}

int main(){
	Integer n;
	scanf("%d%d%d",&n,&size,&Max);
	Integer t;
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		num.push_back(t);
	}
	dfs(0,0,0);
	printf("%d\n",globalmax);
    P[0]=1;
    printf("%ld",Calculate_Pn((long long)globalmax));
	return 0;
}


