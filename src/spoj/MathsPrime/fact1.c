#include<stdio.h>
#include<stdlib.h>
#define For(a,b) for(i=a;i<=b;i++)
int main(){
int a[200];
int d,i,j,k,num,sum=1,mul,st,temp,carry,l=0,idx=0;
a[0]=1;
For(1,199)
a[i]=-1;
scanf("%d",&num);
for(j=1;j<=num;j++){
carry=0;idx=0;l=0;
  for(i=0;!(a[i]==-1&& (l<=999 && l>=0) && carry==0);i++){
    temp=a[i];
            st=0;d=3,k=1;
                  
          while(d<=3){
              if(a[i]==-1){
                  temp=0;
                } else{
                    temp=temp%10;
                    mul=temp*j;
                    temp=temp/10;
                     }      
              sum=mul+carry;
              l=sum%1000;
              st=(sum%10)*k+st;
              carry=sum/10;
              k=k*10;
              //temp=temp/10; 
           if(l<=999 && carry==0 )
            break;
          d--;
         }
       printf(" %d",a[i]);
       a[i]=st;
       idx++;
    }
printf("\n");
}
printf("\n\n");
for(i=idx-1;i>=0;i--)
{
printf("%d",a[i]);
}
printf("\n\n%d",idx);
return (0);
}

