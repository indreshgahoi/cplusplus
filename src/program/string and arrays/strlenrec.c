int strlenrec(char *str)
{
if(*str=='\0')
return 0;
else
return(1+strlenrec(++str));
}

int main(void)
{
char s[100];
int n;
puts("enter the string for getting its length");
gets(s);
n=strlenrec(s);
printf("the length of the string is-- %d",n);
return 0;
}