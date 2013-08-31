#include <stdio.h>
#include<stdlib.h>
#include <malloc.h>

void all_prime(int l , int r)
{
    int *a,i,j,id;
 a=(int *)malloc(sizeof(int)*(r+1));

//printf("\n%d",sizeof(int)*(r+1));

    for(i=0;i<=r;i++){
        //printf("\ni:%d",i);
       a[i]=1;
    }
    a[0]=a[1]=0;

      for(i=2;i<=r/2;i++)
    {   //printf("\ni:%d ",i);
        if(a[i])
           for(j=2,id=2*i;j<=r/2 && id<=r;)
           {
             if(id<=r){
                      //printf("\nid:%d ",id);
                      a[id]=0;
                      }
             j++;
             id=i*j;
           }

    }
    for(i=l;i<=r;i++)
    {
        //printf("\ni:%d ",i);
             if(a[i])
        {
            printf("%d\n",i);
        }
    }
    free(a);
  printf("\n\n");
}

int main()
{
int t,n,m;
scanf("%d",&t);
while(t--){
scanf("%d%d",&n,&m);
all_prime(n,m);
}
return(0);
} /*--main( )-----*/
