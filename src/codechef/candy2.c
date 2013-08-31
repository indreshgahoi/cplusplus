#include<stdio.h>
#define puti(i) printf("%ld\n",i)
int a[100001];
int main()
{
    long long int sum=0;
    int re,num,t=0,tc;
   int id=0;
    scanf("%d",&tc);
   while(tc--)
    {

        sum=0;
        id=0;
        scanf("%d",&num);
        t=num;
        while(num-- )
        {
            scanf("%d",(a+id));
            //if(num==-1)
              //break;
           sum+=a[id++];
           }
          re= (int)(sum%(long long int)t);
         if(re==0){
        printf("YES\n");
        }
        else{
        printf("NO\n");}printf("\n");

    }
  return 0;
}
