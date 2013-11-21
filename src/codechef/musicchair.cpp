#include<iostream>
#include<cstdio>
#include<string>

/*
   long int joseph (long int n,long  int k) {
	 long int res = 0;
	 long int i;
	 for (i = 1; i <= n; ++i){
		 res = (res + k)% i;puts("hello");}
	 return res + 1;
 }

 long int joseph (long int n, long int k) {
	 return n> 1? (joseph (n - 1, k) + k - 1)% n + 1: 1;
 }*/

long int joseph (long int n, long  int k)
{
	if (n==1)
		return 0;
	if (k == 1)
		return n-1;
	if (k>n){ puts("hello");
	return (joseph(n-1,k)+k)%n;}
	long int cnt =n/k;
	puts("hello3");
	long int res =joseph(n-cnt,k);
	res=res-(n%k);
	if (res <0){
		res+=n;puts("hello3");}
	else
		res+=res/(k-1);
	return res;
}
int main()
{
	long  int n,m,res;

	while(1)
	{
		puts("hello");
		scanf("%ld%ld",&n,&m);
		if(n==0 && m==0)
			break;
		puts("hello2");
		res=joseph(n,m)+1;
		printf("%ld %ld %ld\n",n,m,res);
	}
	return 0;
}
