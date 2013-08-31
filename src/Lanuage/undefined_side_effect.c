#include<stdio.h>
#include<time.h>
int main()
{

 int next,pre,i=0;
 int flag=0;
 int x=4,z;
  while(1){
  
  z=((++x)*(++x)*(++x));
  printf("x=%d,z=%d",x,z);


   if(flag)
  {  
      sleep(1);
     if(pre!=next)
     {
            printf("found unbehaviour result\n");
            exit(1);
           //return 0;
     }
   }
  else
  {
    flag=1;
  }

   pre=next;
   x=4; 
 }
return 0;

}
