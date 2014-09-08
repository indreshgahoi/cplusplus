#include<iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
 void print_process()
 {
    int d,cnt=0,steps=0,fl=0;

    for(d=0;1<<d<=n;d++);


    for(int i=0;i<d-1;i++){

     for(int j=1;(j+(1<<(i+1))-1)<=n;j=j+(1<<(i+1)))
     {  steps++;
         break;
     }

   }
    for(int i=d-1;i>0;i--){

     for(int j=1<<i;j+(1<<(i-1))<=n;j=j+(1<<(i)))
      {
        steps++;
        break;
      }
}

  printf("%d\n",steps);


    //up phase

   for(int i=0;i<d-1;i++){
        cnt=0;
        for(int j=1;(j+(1<<(i+1))-1)<=n;j=j+(1<<(i+1)))
      {
         cnt++;
      }
      if(cnt)
      printf("%d ",cnt);
     for(int j=1;(j+(1<<(i+1))-1)<=n;j=j+(1<<(i+1)))
      {
         printf("%d+%d=%d ",(j+(1<<i)-1),(j+(1<<(i+1))-1),(j+(1<<(i+1))-1));
      }
       if(cnt)
      printf("\n");
    }

    //down phase


    for(int i=d-1;i>0;i--){

        cnt=0;
        for(int j=1<<i;j+(1<<(i-1))<=n;j=j+(1<<(i)))
      {
         cnt++;
      }
      if(cnt)
      printf("%d ",cnt);

     for(int j=1<<i;j+(1<<(i-1))<=n;j=j+(1<<(i)))
      {
         printf("%d+%d=%d ",(j),(j+(1<<(i-1))),(j+(1<<(i-1))));
      }
       if(cnt)
      printf("\n");
    }





 }

 int main()
 {
     scanf("%d",&n);
     print_process();

     return 0;
 }
