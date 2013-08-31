#include<stdio.h>
void printnum(int a, int b ,int c){

printf("a=%d b=%d c=%d",a,b,c);

}
int main()
{
   int i=1;
   
   printnum(i,i++,++i);


return 0;
}
