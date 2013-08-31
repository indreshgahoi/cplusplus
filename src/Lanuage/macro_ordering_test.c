#include<stdio.h>

#define MAX 10

void func();
void func()
{

  int max=MAX;

   #define MAX 20


   printf("max in%s =%d",__FUNCTION__,max);

}
int main()
{

   int max=MAX;
   
   printf("max in %s=%d ",__FUNCTION__,max); 

    func();

 return 0;
}




