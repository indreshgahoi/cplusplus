#include<stdio.h>
#define FOR(a,b,i) for(i=a;i<=b;i++)

int lis(int a[10],int s[10])
{   int max=1,i,j,index;
    s[0]=1;
    FOR(1,9,i)
      s[i]=1;
    FOR(1,9,i)
    {
        FOR(0,i-1,j)
        {
            if(a[i]>a[j] && s[j]+1>s[i])
              s[i]=s[j]+1;
        }
    }
    FOR(0,9,i)
    {
        if(s[i]>=max)
        {
            max=s[i];
            index=i;
        }

    }
    FOR(0,9,i)
    {
       printf("a[%d]=%d  s[%d]=%d\n",i,a[i],i,s[i]);

    }
    printf("%d\n",index);
    return max;
}
int main()
{
    int a[10]={ 10, 22, 9, 33, 21, 50, 41, 60,25,45 };
    int s[10];
    printf("longest common seq=%d",lis(a,s));

}
