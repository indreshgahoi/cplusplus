void removeduplicates(char s[])
{
	static int flag[256];
	int i,j;
	for(i=0;s[i]!='\0';i++)
		flag[s[i]]=1;
	for(i=0,j=0;s[i]!='\0';i++)
	{
		if(flag[s[i]]==1)
		{
			s[j++]=s[i];
			flag[s[i]]=0;
		}


	}
	s[j]='\0';
}
int main(int argc,char *argv[])
{
	char s[100];
	gets(s);
	removeduplicates(s);
	puts(s);
	return 0;

}
