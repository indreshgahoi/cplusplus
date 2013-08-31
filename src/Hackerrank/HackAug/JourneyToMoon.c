#include<stdio.h>

struct set
{
	long long rank;
	long long size;
	long long parent;
};

struct set sets[100001];

inline void make_set(long long limit)
{
	long long iter=0;
  
  for(iter=0;iter<limit;++iter)
  {
    sets[iter].parent=iter;
    sets[iter].rank=0;
    sets[iter].size=1;
  }
}


inline long long find_set(long long x)
{
    while(sets[x].parent!=x)
	{
        sets[x].parent=sets[sets[x].parent].parent;
		x=sets[x].parent;
	}

	return sets[x].parent;
}

inline void union_set(long long x,long long y)
{
  x=find_set(x);
  y=find_set(y);
  int size=0;
 if(x!=y)
 {
  if(sets[x].rank>sets[y].rank)
  {
	//size=sets[x].size;
   // sets[sets[y].parent].size-=size;
	sets[y].parent=x;
    sets[x].size+=sets[y].size;

  }
  else
  {
	//size=sets[x].size;
	//sets[sets[x].parent].size-=size;
    sets[x].parent=y;
    sets[y].size+=sets[x].size;

  }
  if(sets[x].rank==sets[y].rank)
	  sets[x].rank++;
 }
}


 
 
 int main()
 {
	 int  n,k1,iter,c1,c2,cnt=0;
	 long long s[100001];
	 long long prefixSum[100001];
	 long long ans,pre,t;

	   scanf("%d%d",&n,&k1);


       make_set(n);

	    for(iter=0;iter<k1;++iter)
	    {
	      scanf("%lld%lld",&c1,&c2);
	      union_set((long long)c1,(long long)c2);
	    }
	    for(iter=0;iter<n;++iter)
	    {
	 	 if(sets[iter].parent==iter)
	      {
	        s[cnt++]=sets[iter].size;
	        //printf("set no=%d size=%d\n",iter,s[cnt-1]);
	      }
	    }



	    for(iter=cnt-1;iter>=1;--iter)
	    {
	 	  if(iter==cnt-1){
	 		   prefixSum[iter]=s[iter];
	 		   continue;
	 	   }

	 	prefixSum[iter]=prefixSum[iter+1]+s[iter];
	    }
	    ans=0;
	    for(iter=0;iter<cnt-1;++iter)
	    {
	 	   ans+=s[iter]*prefixSum[iter+1];
	    }



	    printf("%lld",ans);
	    return 0;
 }
