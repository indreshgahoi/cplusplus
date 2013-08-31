#include<stdio.h>
int main()
{
int cases,i;
int num;
char name[4];
scanf("%d",&cases);
for(i=0;i<cases;i++)
{
scanf("%s%d",name,&num);
if(num==1)
{
    if(name[0]=='S')
 printf("Pre\n");
 else
 printf("Sak\n");
}
else if(num%4==0 || (num-1)%2==0)
{
 printf("%s\n",name);
}
else
{
if(name[0]=='S')
 printf("Pre\n");
 else
 printf("Sak\n");
}
}
return (0);
}
