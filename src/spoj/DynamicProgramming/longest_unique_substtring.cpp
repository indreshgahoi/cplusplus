#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    char a[30];
    int n;
    scanf("%s",a);

int flag[26]={0};
int current_len=0, pre_len=0;
    for(int i=0;a[i]!='\0';i++)
    {
      if(!flag[a[i]-'a'])
      {   flag[a[i]-'a']=1;
          current_len++;
      }
     else
     {
         if(current_len > pre_len)
          pre_len=current_len;
          current_len=0;
        for(int i=0;i< 26;i++)
          flag[i]=0;
     }
    }
    int len=0;
     if(current_len > pre_len)
           len=current_len;
     else
     len=pre_len;
           printf("len=%d",len);
              return 0;
}
