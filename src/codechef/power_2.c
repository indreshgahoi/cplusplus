#include<stdio.h>
#include<string.h>

char mul[603];

int main()
{
   int t,n;
   int sum,carry,result,i,j;
   scanf("%d",&t);
   while(t--)
   {
      memset(mul,0,sizeof(mul));
	  mul[602]=1;
	  scanf("%d",&n);
	  for(i=1;i<=n;i++)
	  {   carry=0;
	     for(j=602;j>=0;j--)
		 {
		    sum=carry+mul[j]*2;
			carry=sum/10;
			sum=sum%10;
			mul[j]=sum;
		 }
	  }
	  result=0;
	  for(i=0;i<=602;i++)
     	 result=result+(int)mul[i];
	 
		
	printf("%d\n",result);	  
    
   }
  return 0;
}
