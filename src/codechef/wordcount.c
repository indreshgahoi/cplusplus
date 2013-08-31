#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

long B=1000000; /* Working base */
long LB=6;    /* Log10(base)  */
long MaxDiv=450;  /* about sqrt(2^31/B) */
char ch[125];
long fact[11]={1,1,2,6,24,120,720,5040,40320,362880,3628800};
long st,mt;

void SetToInteger (long n, long *x, long Integer) {
  long i;
  for (i=0; i<n; i++) x[i] = 0;
  x[n-1] = Integer;
}


void Mul (long n, long *x, long q) {
  long carry=0, xi, i;
  for (i=n-1; i>=n-st; i--) {
    xi  = x[i]*q;
    xi += carry;
    if (xi>=B) {
         st++;
      carry = xi/B;
      xi -= (carry*B);

    }
    else
      carry = 0;
    x[i] = xi;
	}
}


void Div (long n, long *x, long d, long *y) {
  long carry=0, xi, q, i;
  mt=n-st;
  for (i=n-st; i<n; i++) {
    xi    = x[i]+carry*B;
    q     = xi/d;
    carry = xi-q*d;
    //puts("Div");
    y[i]  = q;
    mt++;
   // printf("%ld %ld %ld %ld\n",n,y[i],i,d);
  }
}

void Div1 (long n, long *x, long d, long *y) {
  long carry=0, xi, q, i;
 // mt=n-st;
  for (i=n-st; i<n; i++) {
    xi    = x[i]+carry*B;
    q     = xi/d;
    carry = xi-q*d;
    //puts("Div");
    //y[i]  = q;
    //mt++;
   // printf("%ld %ld %ld %ld\n",n,y[i],i,d);
  }
  printf("%ld",carry);
}

int main () {
char ch1[501];
long NbDigits=1000000;
long size=1+NbDigits/LB,fl=1;
long *x      = (long *)malloc(size*sizeof(long));
//long *y  = (long *)malloc(size*sizeof(long));
//long *q = (long *)malloc(size*sizeof(long));
long i,t,j,k,zero=0,zt;
scanf("%ld",&t);
while(t--)
{   memset(ch,0,125*sizeof(char));
    memset(x,0,size*sizeof(long));
    scanf("%s",ch1);
    i=0;
    st=0;
    while(ch1[i]!='\0')
    {
        ch[ch1[i]]++;
        i++;
    }st++;
    SetToInteger(size,x,1);

    for(j=2;j<=i;j++)
    {
        Mul(size,x,j);
    }
   // for(j=size-st;j<size;j++)
   // { if(fl && x[j]==0)
    //{
        //continue;
   // }else{ fl=0;
     //   printf("%ld %ld\n",x[j],j);}

    for(i='a',j='A';i<='z' && j<='Z';i++,j++)
   {   if(!(ch[i]==0 || ch[i]==1))
         Div(size,x,fact[ch[i]],x);
       //  fl=1;
      //  for(k=0;k<size;k++)
   // { if(fl && x[j]==0)
   // {
     //   continue;
   // }else{ fl=0;
    //    printf("%ld %ld",x[k],k);}
  //  } printf("\n");
       if(!(ch[j]==0 || ch[j]==1))
         Div(size,x,fact[ch[j]],x);
       // fl=1;
   //     for(j=0;j<size;j++)
  //  { if(fl && x[j]==0)
  //  {
      //  continue;
   // }else{ fl=0;
   //     printf("%ld ",x[j]);}
   // }printf("\n");

    }
   // fl=1;

     /* fl=1;
        for(j=size-st;j<mt;j++)
         {          if(fl && x[j]==0)
                    {
                         continue;
                    }                 else{break; }
         }


       printf("%ld",x[j]);
        for(k=j+1;k<mt;k++)
    {   zt=B/10;
        while(x[k]<zt)
        {  zt=zt/10;
            printf("%ld",zero);
        }
        printf("%ld",x[k]);
    } printf("\n");*/
    Div1(size,x,1000000007,x);
   /*  fl=1;
        for(j=0;j<size;j++)
    { if(fl && x[j]==0)
    {
        continue;
   }else{ fl=0;
        printf("%ld %ld",x[j],j);}
    }printf("\n");
     printf("%ld %ld",size-st,size-mt);*/
  //printf("%ld",1000000007);
}
return 0;
}
