#include<stdio.h>
#include<string.h>
#define FOR(a,b,i) for(i=a;i<=b;i++)


char mul[9][10003];
char mult[100000003];
int ln1,ln2;

void strrev(char *s1)
{
   int i=0,j=strlen(s1)-1;
    char temp;
     while(j>i)
    {   temp=s1[i];
        s1[i]=s1[j];
        s1[j]=temp;
        j--;i++;
            }
}
void putrs(char *s1)
{
    int len=strlen(s1)-1;
    while(s1[len]!='\0'){
      printf("%c",s1[len]);len--;}
    printf("\n");

}

void adds(char *s1 ,char *s2){
         char *p;
         int carry=0,i=0,sum=0,l;
         while(s1[i]!='\0' && s2[i]!='\0')
         {
             sum=carry+s1[i]-'0'+s2[i]-'0';
             l=sum%10;
             carry=sum/10;
             s1[i]='0'+l;
             i++;
         }
         sum=0;
         if(s1[i]=='\0'){
            p=s2;
            s1[i]='0';
            s1[i+1]='\0';}
          else
              p=s1;
          while(p[i]!='\0'){
               sum=carry+p[i]-'0';
               l=sum%10;
               carry=sum/10;
               s1[i]='0'+l;
               i++;
          }
          s1[i]='0';
          s1[i+1]='\0';
          sum=0;
          while(carry){
              sum=carry;
               l=sum%10;
               carry=sum/10;
               s1[i]='0'+l;
               i++;
         }
          s1[i]='\0';

       }



   int main()
   {
       char l1[10001],l2[10001],*s1,*s2;
       int i=0,t,ln2;
        scanf("%d",&t);
        while(t--){
         mult[0]='0';
        mult[1]='\0';
       scanf("%s",l1);
       strrev(l1);
       scanf("%s",l2);
       strrev(l2);
       if(strlen(l1)>=strlen(l2)){
          s1=l1;s2=l2;}
          else{
               s1=l2;
               s2=l1;
          }
          FOR(0,8,i){
             mul[i][0]='0';
             mul[i][1]='\0';}
          adds(mul[0],s1);
         FOR(1,8,i)
         {   adds(mul[i],s1);
             adds(mul[i],mul[i-1]);
             //putrs(mul[i]);
         }

       ln2=strlen(s2)-1;
       FOR(0,ln2,i)
       {
           if(s2[i]=='0'){
           mult[i]='0';
           mult[i+1]='\0';
           continue;}
           else
           {
               adds(mult+i,mul[(s2[i]-'1')]);
           }

       }

    putrs(mult);
}
return 0;
   }

