// a O(n) algorithm to check weather the two strings are anagrams of each other or not
//:)

#include<stdio.h>
#include<string.h>
flag[255];
int isAnagram(char *st1,char *st2)
{int min=32766;
int max=-32600;
int i;
for(i=0;st1[i]!='\0';i++)
{flag[st1[i]]++;
if(min>st1[i])
min=st1[i];
if(max<st2[i])
max=st2[i];
}
for(i=0;st2[i]!='\0';i++)
{flag[st2[i]]--;
if(min>st2[i])
min=st2[i];
if(max<st2[i])
max=st2[i];
}
for(i=min;i<=max;i++)
{
if(flag[i]!=0)
return 0;
}
return 1;
}
int main(void)
{
char s1[100],s2[100];
int c;
puts("enter the two string for check");
gets(s1);
gets(s2);
c=isAnagram(s1,s2);
if(c==0)
puts("NOT ANAGRAMS");
else
puts("ANAGRAMS");
return 0;


}