#include <stdio.h>
#include <math.h>
typedef int BOOLEAN;
BOOLEAN IsPrime( int n ) /* checks for prime */
{
	int i;
	BOOLEAN flag = ( n>1 );
	for( i=2 ; flag && i<=sqrt(n/2) ; ++i )
		flag = ( n%i );
	return( flag );
} /*--IsPrime( )--------*/


int main( void )
{
	int i;
	int t,n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for( i=n ; i<=m ; ++i )
			if ( IsPrime(i) )
				printf( "%d\n" , i );
		printf("\n");
	}
	return(0);
} /*--main( )-----*/
