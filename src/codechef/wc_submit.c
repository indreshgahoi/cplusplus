#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

long B=1000000007; /* Working base */
long LB=9;    /* Log10(base)  */
long MaxDiv=450;  /* about sqrt(2^31/B) */
char ch[125];
long fact[11]={1,1,2,6,24,120,720,5040,40320,362880,3628800};
long st,mt;

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
    y[i]  = q;
    mt++;

  }
}

/*void Div1 (long n, long *x, long d, long *y) {
  long carry=0, xi, q, i;
  for (i=n-st; i<n; i++) {
    xi    = x[i]+carry*B;
    q     = xi/d;
    carry = xi-q*d;
  }
  printf("%ld\n",carry);
}*/

int main () {
char ch1[521];
long NbDigits=1000000007;
long size=1+NbDigits/LB,fl=1;
long *x      = (long *)malloc(size*sizeof(long));
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
    x[size-1]=1;

    for(j=2;j<=i;j++)
    {
        Mul(size,x,j);
    }
   for(i='a',j='A';i<='z' && j<='Z';i++,j++)
   {   if(!(ch[i]==0 || ch[i]==1))
         Div(size,x,fact[ch[i]],x);
     if(!(ch[j]==0 || ch[j]==1))
         Div(size,x,fact[ch[j]],x);
    }

   // Div1(size,x,1000000007,x);
    printf("%ld\n",x[mt-1]);

}
return 0;
}
