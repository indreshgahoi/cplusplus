
    #include<stdio.h>
    #include<math.h>


    long int solve(long int mul)
    { long int i,j,ans;
      long int sqrt_n=(long int)sqrt(mul + .0);

    for(i=2;i<=sqrt_n;i++)
     if(mul%i==0){
       while(mul%i==0)
       {
           mul/=i;
       }
       ans=i;
    }
    if(mul==1)
      return ans;
    else return mul;
    }

    int main()
    {
    long int t,N,mul,num,i,j,key,flag;
    scanf("%ld",&j);

    for(t=1;t<=j;t++)
    { mul=1;
    scanf("%ld",&N);
    for(i=1;i<=N;i++)
    {
    scanf("%ld",&num);
    mul*=num;
    }
    mul++;
    printf("Case #%d: %d\n",t,solve(mul));

    }

    return 0;
    }
