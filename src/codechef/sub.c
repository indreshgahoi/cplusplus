#include <stdio.h>
#include <math.h>
typedef int BOOLEAN;
BOOLEAN IsPrime( int n ) /* checks for prime */
{
  int i;
  BOOLEAN flag = ( n>1 );

     for( i=2 ; flag && i<=sqrt(n) ; ++i )
        flag = ( n%i );

  return( flag );
} /*--IsPrime( )--------*/

int nth_prime(int n)
{
  int i=1,c=0,num;

     while(c!=n)
    {
       if(IsPrime(i))
       {
           c++;
       }
       i=i+1;
    }
    return (i-1);
}

int main( void )
{
int i;
int t,n,m,count=0,a,b,c;
scanf("%d",&t);
while(t--)
{
  scanf("%d",&n);
  count=0;
  i=2;
  while(n!=count)
 {
      a=nth_prime(i);
      b=nth_prime(i+2);
      c=nth_prime(i+1);
     // printf("i:%d\n",i);
      //printf("a:%d\n",a);printf("b:%d\n",b);printf("c:%d\n",c);
      while(c!=((a+b)/2))
      {//printf("i:%d\n",i);
       i++;
       a=c;
       c=b;
       b=nth_prime(i+2);
       //printf("\n%d\ni:",i);
     // printf("a:%d\n",a);printf("b:%d\n",b);printf("c:%d\n",c);
     }
     //printf("%d\nb:",b);
    i++;
      count++;
  }
  printf("%d\n",c);
}
return(0);
} /*--main( )-----*/
