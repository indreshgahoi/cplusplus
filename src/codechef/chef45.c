#include<stdio.h>
int main()
{
int t,n,i,m;
scanf("%d",&t);
while(t--)
{
scanf("%d",&n);
if((n-1)%4==0)
{
printf("ALICE\n");
}
else{
printf("BOB\n");

}
}
return(0);
}
