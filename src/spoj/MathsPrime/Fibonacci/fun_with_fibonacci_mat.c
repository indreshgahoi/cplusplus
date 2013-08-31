#include<stdio.h>
#include<stdlib.h>
typedef long long  LL;

void nthpower(LL a[][3],LL k,LL m){
    LL i,j,l,temp[3][3],mt[3][3]={{1,1,0},{1,0,0},{1,1,1}};
    if(k==0 ||k==1){
        return;
    }

        nthpower(a,k>>1,m);
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

LL ithsum(LL i,LL f,LL s,LL m){
    LL an=f,an1=s,k,l,j;
    LL a[3][3]={ {1,1,0},{1,0,0},
                      {1,1,1}};
   LL c[3][1]={{an1},{an},{(f+s)}},temp[3][1];

    if(i<=2){
      if(i==1)
      return an;
      if(i==2)
      return (f+s)%m;
    }
    else{
        k=i-2;
        nthpower(a,k,m);
        for(i=0;i<3;i++){
         for(j=0;j<1;j++){
           temp[i][j]=0;
           for(l=0;l<3;l++){
              temp[i][j]=(temp[i][j]+(a[i][l]*c[l][j]))%m;
           }
         }}
      }
      return temp[2][0];
}
int main()
{
    LL T,a=1,b=2,n,m=3;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&n,&m);
        a=a%m;
        b=b%m;
       printf("%lld\n",ithsum(n,a,b,m));
    }
 return 0;
}



