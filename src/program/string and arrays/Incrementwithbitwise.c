int inc(int n)
{
	int i=1;
	while(n&i)
	{
		n &= ~i;
		i <<= 1;
	}
	return (n|i);
}

int main()
{
	int num;
	scanf("%d",&num);
	printf("%d",inc(num));
	return 0;
}
