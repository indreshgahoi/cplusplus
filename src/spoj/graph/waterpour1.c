#include<stdio.h>
int main(){
int n;
int a,b,c;
int levela,levelb;
int i;
scanf("%d",&n);
int temp;
int ans;
int flag;
for(i=0;i<n;i++)
{
scanf("%d%d%d",&a,&b,&c);
flag=0;
ans=0;
levela=0;
levelb=0;
if(a==c||b==c)
printf("1\n");
else{
if(b>a)
{
temp=a;
a=b;
b=temp;
}
while(1){
if(levela==a&&levelb==b)
{
printf("-1\n");
break;
}
levelb=b;
ans++;
levela=levela+b;
ans++;
if(levela>a){
levelb=levela-a;
levela=a;
if(levelb==c)
{printf("%d\n",ans);
break;
}
levela=levelb;
ans+=2;
}
if(levela==c||(a-levela==c))
{
printf("%d\n",ans);
break;
}
}
}
}
return 0;
}
