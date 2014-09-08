char *flag;
void pds(long long int N,long long int pd,long long int k)
{
	int g,i;
	if(N>=10000000)
		return;
	g=N*10+k;

	if(k==0){
		flag[g]=1;
		printf("%d\n",g);
	}
	pd=pd*k;
	// sum=sum+k;
	// if(pd%sum==0)
	//   flag[g]=1;

	for(i=0;i<=9;i++)
		pds(g,pd,i);

}
void pds1(long long int N,long long int pd,long long int sum)
{
	long long int g,i;
	long long int cd,sd;
	if(N>100000000)
		return;
	if(pd==0)
	{
		if(N*10<100000000)
			flag[N*10]=1;
		for(i=0;i<=9;i++)
		{
			pds(N*10+i,0,sum);

		}
	}
	else
	{
		for(i=0;i<=9;i++)
		{
			g=N*10+i;
			cd=pd*i;

			pds(g,cd,sd);
		}
	}
}


int main()
{
	long long int i;
	long long int n;
	char s[10000];
	flag=calloc(1000000000,1);
	for(i=1;i<=9;i++)
		pds(0,1,i);
	while(1)
	{  long long int count=0;
	gets(s);
	i=0;
	n=0;
	while(s[i])
	{
		n=n*10+s[i]-'0';
		i++;
	}
	//scanf("%d",&n);

	for(i=1;i<=1000000000;i++)
	{
		if(flag[i])
			count++;
		if(count==n)
			break;
	}
	printf("%lld\n",i);
	}

	return 0;
}
