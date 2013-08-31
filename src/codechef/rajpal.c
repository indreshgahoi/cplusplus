#include<stdio.h>


int main(){
int i=4,j=4,a,b;
a=++i + ++i;
b=++j+ ++j+ ++j;

printf("%d %d",a,b);
return 0;
}