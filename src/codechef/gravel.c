#include<stdio.h>
#include<malloc.h>
int main()
{
 int n,m,k,i=0,u,v,c,p;
 int *a;
 char ch;

    scanf("%d",&n);
    a=(int*) malloc(sizeof(int)*n);
    scanf("%d%d",&m,&k);
while(n--){
a[i++]=k;
}
while(m--){
scanf("%c",&ch);
switch(ch)
{
 case 'S':
      scanf("%d%d%d",&u,&v,&c);
         --u;--v;
        while(u<=v){
         a[u]=a[u]+c;u++;}
        break;
 case 'Q':
          scanf("%d",&p);
          printf("%d\n",a[--p]);
          break;
 default :
    m++;
    break;
}
}
 }
