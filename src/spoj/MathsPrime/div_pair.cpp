#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int T;
	long long int k,n,m;;
	scanf("%d",&T);
	while(T--)
	{

		scanf("%lld%lld",&n,&m);
		if(n==1 || n<(m>>1))
		{
			printf("0\n");
		}
		else
		{
			long long int q1=n/m;
			long long int q2=((n<<1)-1)/m;

			if(m & 1)
			{
				k=(((m*(q1)*(q1+1))-(((q1>>1)<<2)+((q1>>1)<<1)))>>2)
		+((((n*(q2-q1))<<2)-(m*(q2-q1)*(q2+q1+1))+((q2-q1)+1))>>2);


			}
			else
			{
				k=(((m*(q1)*(q1+1))-(((q1)<<2)))>>2)
		-((m*(q2-q1)*(q2+q1+1))>>2)
		+(n*(q2-q1));

			}

			printf("%lld\n",k);


		}
	}
	return 0;
}
