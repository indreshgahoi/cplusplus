//Finding the Minimum Window in S which Contains All Elements from T.
// ver very efficient question by being having O(n) complexity
// very smart question :)
int MinWindow(const char*s,const char *t,int *minbegin,int *minend)
{
int slen=strlen(s);
int tlen=strlen(t);
int minwin=32768;
int i,j;
int winlen;
static int needtofind[256];
static int hasfound[256];
for(i=0;i<=strlen(t);i++)
{
needtofind[t[i]]++;
}
int begin=0;
int end=0;
for(end=0;end<slen;end++)
{
if(needtofind[s[end]]==0)
continue;
hasfound[s[end]]++;
if(needtofind[s[end]]>hasfound[s[end]])
{
count++
}
if(count==tlen)
{
while(needtofind[s[begin]]==0||hasfound[s[begin]]>needtofind[s[begin]])
{
if(hasfound[s[begin]]>needtofind[s[beging]])
hasfound[s[begin]]--;
begin++;
}
winlen=end-begin+1;
if(minwin>winlen)
{
*minbegin=begin;
*minend=end;
}

}

}
return(count==tlen);
}
int main()
{
char s[100],t[100];
int minbegin=0;
int minend=0,i;
gets(s);
gets(t);
i=MinWindow(s,t,&minbegin,&minend);
for(i=0;i<strlen(s);i++)
{
if(i>=minbegin && i<=minend)
printf("%c",s[i]);
}
return(0);
}