#include<stdio.h>
#define min(a,b) (a<=b?a:b)
#define FOR(a,b,i) for(i=a;i<=b;i++)
char m[11]={0,0,0,0,0,0,0,0,0,0,0},w[11]={0,0,0,0,0,0,0,0,0,0,0};
int main(){
  int k1=10,k2=10,t,n,i,ht_sum=0,ct=0,mi=0,l;
  scanf("%d",&t);
  while(t--){
    FOR(0,10,i)
     w[i]=m[i]=0;
    k1=k2=10;mi=ht_sum=0;
   scanf("%d",&n);
    ct=n;
    FOR(1,n,i){
     scanf("%d",&l);
      m[l]++;}
    FOR(1,n,i){
     scanf("%d",&l);
     w[l]++;}

     while(1)
     {           mi=min(m[k1],w[k2]);
                  if(mi){
                  ht_sum+=k1*k2*mi;
                  m[k1]-=mi;w[k2]-=mi;
                  ct-=mi;
                  }
                  if(ct==0)
                    break;
                while(!m[k1])
                  k1--;
                while(!w[k2] )
                  k2--;

     }
    printf("%d\n",ht_sum);
  }
  return 0;
}

