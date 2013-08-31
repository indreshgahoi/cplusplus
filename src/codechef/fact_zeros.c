#include<stdio.h>
#define get(in) scanf("%d",&in);
#define put(op) printf("%d\n",op);
int main()
{
    int t,num,zero=0;
    get(t);
    while(t--){
       zero=0;
       get(num);
       for(;num>4;)
           num=num/5,zero+=num;
       put(zero);
    }
    return 0;
}
