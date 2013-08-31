#include<stdio.h>
int main(void){
long int n,t;
scanf("%ld",&t);
if(t>=1 && t<=10000){
while(t--){
scanf("%ld",&n);
if(n>=1 && n<=1000000000){
if((n%2)==0){
printf("Alice\n");
}
else{
printf("Bob\n");
}
}
}
}
return 0;
}

