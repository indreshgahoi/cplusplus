#include<stdio.h>
int main()
{  int T,P,res;
   scanf("%d",&T);

   while(T--)
   {
       scanf("%d",&P);
       printf("%d\n",(((P-1)>>1)+1));
   }

    return 0;
}
