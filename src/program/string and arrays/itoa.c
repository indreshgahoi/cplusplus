char *itoa(int n)
{
	static char s[100];
	char temp;
	int i=0,k,p;
	while(n)
	{
		s[i++]=n%10+'0';
		n=n/10;
	}
	s[i]='\0';
	i--;
	for(k=0,p=i;k<p;k++,p--)
	{
		temp=s[k];
		s[k]=s[p];
		s[p]=temp;
	}
	return s;
}
int main(void)
{
	int n;
	char *p;
	scanf("%d",&n);
	p=itoa(n);
	puts(p);
}

