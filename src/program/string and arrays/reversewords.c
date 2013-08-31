#include<stdio.h>
void reverse(char *begin, char *end)
{
  char temp;
  while (begin < end)
  {
    temp = *begin;
    *begin++ = *end;
    *end-- = temp;
  }
}

void reversewords(char *s)
{
int i,j,end,begin;
int len=strlen(s);
for(i=0;i<len;)
{
begin=i;
end=i;
while(s[end]!=' '&& end<len)
end++;
i=end+1;
end--;
reverse(s+begin,s+end);
}
reverse(s,s+len-1);
}

int main()
{
char str[200];
gets(str);
reversewords(str);
puts(str);
return 0;

}