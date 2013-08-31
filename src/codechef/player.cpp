#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector < int > vi(11,0);
bool used1[101];
bool cmp(int a,int b)
{
  return a>b;
}

int comb(int n,int r)
{
  if(n==r)
  return 1;
  int t=1,mul1=1,mul2=1;

  for(int i=n;i>n-r;i--)
    mul1*=i;
  for(int i=1;i<=r;i++)
    mul2*=i;

  return (mul1/mul2);

}
int main()
{
    int T,k,mul=1,n,t,r,i,j;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<11;i++)
        scanf("%d",&vi[i]);
        sort(vi.begin(),vi.begin()+11,&cmp);

       mul=1;
       scanf("%d",&k);
       for(int i=0;i<=100;i++)
         used1[i]=true;
       for(int i=0;i<k;i++)
       {
           if(used1[vi[i]]){
        n=(int)count(vi.begin(),vi.begin()+11,vi[i]);
        r=(int)count(vi.begin(),vi.begin()+k,vi[i]);
        mul=mul*comb(n,r);
        used1[vi[i]]=false;}
       }
       printf("%d\n",mul);

    }
 return 0;
}
