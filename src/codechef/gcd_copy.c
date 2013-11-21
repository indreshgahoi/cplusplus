#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIGITS 5
#define BASE 100000

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main ()
{
	int nTest, i, x, count, len;
	unsigned long long a, temp;
	unsigned long long B[260];
	char pb[260];
	scanf("%d", &nTest);
	for (i=1; i<=nTest; i++)
	{
		scanf("%lld %s", &a, pb);
		if (a == 0)
		{
			printf("%s\n", pb);
			continue;
		}
		len=strlen(pb);
		for (x=len-DIGITS, count=0; x>=0; x-=DIGITS, count++)
		{
			B[count] = atol(pb + x);
			pb[x]='\0';
		}
		B[count] = atol(pb);
		count++;

		x=count-1;
		temp = B[x];
		while (x>=0)
		{
			if (temp < a)
			{
				x--;
				if (x<0)
					break;
				temp = temp * BASE + B[x];
			}
			temp = temp % a;
		}

		printf("%lld\n", gcd(a, temp));
	}
	return 0;
}
