/*#include<stdio.h>
#define N 1010
char str1[N],str2[N],concat[N];
int a[27],b[27],catlen;
char db[27][1]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o"
       ,"p","q","r","s","t","u","v","w","x","y","z"};
void conct(char *s,int i,int min)
{
    int j=catlen;
    while(min--){
       strcat(s,db[i]);
       j++;
    }
    catlen=j;
    concat[catlen+1]='\0';
}
int main()
{
   int i,j,k,t,min;
  // scanf("%d",&t);
   while(scanf("%s%s",str1,str2)!=EOF)
   {

     catlen=0;concat[catlen]='\0';
     //scanf("%s%s",str1,str2);
     for(i=0;i<strlen(str1);i++)a[str1[i]-'a']++;
     for(i=0;i<strlen(str2);i++)b[str2[i]-'a']++;
     for(i=0;i<26;i++)
     {
        min=(a[i]<b[i])?a[i]:b[i];
        if(min!=0)
        {
          conct(concat,i,min);
        }
        a[i]=0;b[i]=0;
    }
    printf("%s\n",concat);
   }
   return 0;
}*/
