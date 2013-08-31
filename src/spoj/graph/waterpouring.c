#include<stdio.h>


int main()
{
    int c,k1,k2,c1,c2,t,q,r,temp,diff,step=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&c1,&c2,&c);
        step=0;
        if(c1>c2)
        {
            temp=c2;
            c2=c1;
            c1=temp;
        }
        k1=c1;
        k2=c2;
        diff=k2-k1;
        if(c>c2 )
        {
            printf("-1\n");
        }
        else if(k1==c || k2==c)
        {
           step=1;
           printf("%d\n",step);
        }
        else if(diff==c || c==k1+k2)
        {
           step=2;
           printf("%d\n",step);
        }
        else if(c==k2+diff)
        {
            step=5;
            printf("%d\n",step);
        }
        else if(c==k1+diff)
        {
          step=1;
          printf("%d\n",step);
        }
        else if(k2<=c && c%k1==0)
        {
            step=2*(c/k1);
            printf("%d\n",step);
        }
        else
            {
                q=k2/k1;
                k2=c2;
                k1=r=q*k1-k2;
                if(r== c)
                {
                    step=2*q;
                    printf("%d\n",step);
                }
                else if(c==(c2-(c1-r)))
                {
                    step=2*q+1;
                    printf("%d\n",step);
                }
                else if(c>k2 && c==r+c2)
                {
                    step=2*q;
                    printf("%d\n",step);
                }
                else if(c==r+c1)
                {
                    step=2*q+3;
                    printf("%d\n",step);
                }
                else
                {
                    printf("-1\n");
                }
            }


    }
    return 0;
}
