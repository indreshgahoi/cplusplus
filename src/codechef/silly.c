#include<stdio.h>
#include<assert.h>


struct node {
 struct node *zero ,*one;
};

struct node *Tries;

void insert(int num)
{
    int i=30,dg,j;
    struct node *current;
    current=Tries;
    dg=(1 & num>>i);

    for(j=31;j>=1;j--)
    {

        if(Tries==NULL)
        {
            Tries=(struct node*)malloc(sizeof(struct node));
            if(dg==1)
            {
               Tries->one=(struct node*)malloc(sizeof(struct node));
               current=Tries->one;
               Tries->zero=NULL;
               Tries->one->one=NULL;
               Tries->one->zero=NULL;

            }
            else
            {
                Tries->zero=(struct node*)malloc(sizeof(struct node));
                current=Tries->zero;
                Tries->one=NULL;
                Tries->zero->one=NULL;
                Tries->zero->zero=NULL;

            }
        }
        else
        {

           if(dg==1)
            {
               if(current->one==NULL)
               {


                    current->one=(struct node*)malloc(sizeof(struct node));
                    current->one->one=NULL;
                    current->one->zero=NULL;

               }

               current=current->one;

            }
            else
            {
                if(current->zero==NULL)
                {

                     current->zero=(struct node*)malloc(sizeof(struct node));
                     current->zero->one=NULL;
                     current->zero->zero=NULL;
                }

                current=current->zero;

            }


        }
        i--;
        dg=(1 & num>> i);
       // printf("i=%d dg=%d\n",i,dg);
       }
}



void init(int N)
{
    int i ,num;
    for(i=1;i<=N;i++)
    {
        scanf("%d",&num);
        insert(num);
    }

}


int solve(int n)
{
    int res=0;
    int i=30,dg,j;
    struct node *current=Tries;
    dg=(1 & n>>i);

    //printf("dg=%d i=%d\n",dg,i);

    for(j=31;j>=1;j--)
    {
        if(dg==1)
        {
            if(current->zero==NULL)
            {
                assert(current !=NULL);
                current=current->one;

            }
            else
            {
                res=res|1<<i;
                assert(current !=NULL);
                current=current->zero;
            }
        }

        else
        {
             if(current->one==NULL)
            {
                assert(current !=NULL);
                current=current->zero;

            }
            else
            {
                res=res|1<<i;
                assert(current !=NULL);
                current=current->one;
            }
        }

        i--;
        dg=(1 & n>> i);
      // printf("dg=%d i=%d\n",dg,i);
    }

return res;
}



int main()
{
    int N,Q,i,n;
    Tries=NULL;



        scanf("%d",&N);
        init(N);
        scanf("%d",&Q);
        for(i=1;i<=Q;i++)
        {
            scanf("%d",&n);
            printf("%d\n",solve(n));
        }
  return 0;
}

