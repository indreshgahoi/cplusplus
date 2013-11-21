#include<iostream>
#include<cstdio>
using namespace std;


int main()
{
    int a[30]={0};
    int b[30];
    int n;
    scanf("%d",&n);
    for(int i =0;i<n;i++)
      scanf("%d",b+i);

    for(int i=0;i<n;i++){
     a[i]=1;
        for(int j=0;j<i;j++)
         if(b[i]> b[j] && a[j]+1 > a[i])
          a[i]=a[j]+1;
    }
    int max=0;
    for(int i=0;i<n;i++)
      if(a[i]>max)
           max=a[i];

           printf("%d",max);
   return 0;
}
