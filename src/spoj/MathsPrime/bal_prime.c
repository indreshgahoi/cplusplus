#include <stdio.h>
#include <math.h>
typedef int BOOLEAN;
int k=1,cg=0;
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
	if(n==2){
		return 3;
	}
	if(n==3){
		cg=2;
		k=5;
	}

	while(cg!=n)
	{
		if(IsPrime(k))
		{
			cg++;
		}
		k=k+2;
	}
	return (k-2);
}

int main( void )
{
	int i=2;
	int t,n,m,count=0,a,b,c,fl=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		// count=0;

		//a=nth_prime(i);
		if(fl==0){
			c=nth_prime(i);
			b=nth_prime(i+1);fl=1;}
		while(n!=count)
		{
			//a=nth_prime(i);
			//c=nth_prime(i+1);
			a=c;
			c=b;
			b=nth_prime(i+2);
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
