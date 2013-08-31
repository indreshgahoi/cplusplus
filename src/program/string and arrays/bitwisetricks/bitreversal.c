int bitReversal(int num)
{
int i;
int reverse=0;
for(i=0;i<=31;i++)
if(num & (1<<i))
  reverse|=1<<(31-i);

return(reverse);
}
int main()
{
int n;
scanf("%d",&n);
n=bitReversal(n);
printf("%d",n);

getch();
return 0;
}
