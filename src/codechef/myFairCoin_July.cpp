#include<stdio.h>
#include<stdlib.h>
#define m 1000000007
typedef long long LL;
inline void nthpower(LL a[][2],LL k){
LL i,j,l,temp[3][3],mt[2][2]={{2,2},{1,0}};
if(k==0 ||k==1){
return;
}

nthpower(a,k>>1);
for(i=0;i<2;i++){
for(j=0;j<2;j++){
temp[i][j]=0;
for(l=0;l<2;l++){
temp[i][j]=(temp[i][j]+(a[i][l]*a[l][j]))%m;
}
}}
for(i=0;i<2;i++){
for(j=0;j<2;j++){
a[i][j]=temp[i][j];}}
if( k & 1){
for(i=0;i<2;i++){
for(j=0;j<2;j++){
temp[i][j]=0;
for(l=0;l<2;l++){
temp[i][j]=(temp[i][j]%m+(a[i][l]*mt[l][j])%m)%m;
}
}}
for(i=0;i<2;i++){
for(j=0;j<2;j++){
a[i][j]=temp[i][j];}}

}
}

inline LL ithsum(LL i){
LL k,l,j;
LL a[2][2]={ {2,2},{1,0}};
LL c[2][1]={{3},{1}},temp[2][1];

if(i<=2){
if(i==1 || i==0)
return 0;
if(i==2)
return 1;
}
else{
k=i-2;
nthpower(a,k);
for(i=0;i<2;i++){
for(j=0;j<1;j++){
temp[i][j]=0;
for(l=0;l<2;l++){
temp[i][j]=((temp[i][j]%m+(a[i][l]*c[l][j])%m))%m;
}
}}
}
return temp[0][0];
}
int main()
{
LL T,n,d,sum;
scanf("%lld",&T);
while(T--)
{
scanf("%lld",&n);
if(n==1){
 printf("1\n");
  continue;}
if(n==2){
 printf("3\n");
 continue;}
sum=ithsum(n)%m;
printf("%lld\n",sum);
}
return 0;
}
