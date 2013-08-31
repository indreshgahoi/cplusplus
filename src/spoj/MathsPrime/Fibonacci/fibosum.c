#include<stdio.h>
#include<stdlib.h>
typedef long long  LL;
int m=1000000007;
void nthpower(LL a[][3],LL k){
    LL i,j,l,temp[3][3],mt[3][3]={{1,1,0},{1,0,0},{1,1,1}};
    if(k==0 ||k==1){
        return;
    }

        nthpower(a,k>>1);
        for(i=0;i<3;i++){
         for(j=0;j<3;j++){
           temp[i][j]=0;
           for(l=0;l<3;l++){
              temp[i][j]=(temp[i][j]+(a[i][l]*a[l][j]))%m;
           }
         }}
         for(i=0;i<3;i++){
         for(j=0;j<3;j++){
           a[i][j]=temp[i][j];}}
    if( k & 1){
        for(i=0;i<3;i++){
         for(j=0;j<3;j++){
           temp[i][j]=0;
           for(l=0;l<3;l++){
              temp[i][j]=(temp[i][j]+(a[i][l]*mt[l][j]))%m;
           }
         }}
         for(i=0;i<3;i++){
         for(j=0;j<3;j++){
           a[i][j]=temp[i][j];}}

    }
}

LL ithsum(LL i){
    LL k,l,j;
    LL a[3][3]={ {1,1,0},{1,0,0},
                      {1,1,1}};
   LL c[3][1]={{1},{0},{1}},temp[3][1];

    if(i<=2){
      if(i==1 || i==0)
      return 0;
      if(i==2)
      return 1;
    }
    else{
        k=i-2;
        nthpower(a,k);
        for(i=0;i<3;i++){
         for(j=0;j<1;j++){
           temp[i][j]=0;
           for(l=0;l<3;l++){
              temp[i][j]=((temp[i][j]+(a[i][l]*c[l][j])))%m;
           }
         }}
      }
      return temp[2][0];
}
int main()
{
    LL T,n,d,sum;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&d);
        sum=(ithsum(d+1)-ithsum(n)+m)%m;
        printf("%lld\n",sum);
    }
 return 0;
}



