#include<stdio.h>
#include<string.h>

int main()
{ char str[100000]; 
  unsigned int num1,num2,num3,rem,flag;
  int t,i;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%s",str);
	num1=0;
    for(i=0;i<=31;i++)
     {
	   if(str[i]=='1')
		 num1=num1<<1;
		else
          num1=(num1<<1)+1;		
     }
	 num2=0;
    for(i=32;i<=47;i++)
     {
	   if(str[i]=='1')
		 num2=num2<<1;
		else
          num2=(num2<<1)+1;		
     }
	  rem=0;
	  num3=0;
	 for(i=48;i<=47+num2;i++)
	  {  
	     if(str[i]=='1')
		 num3=num3<<1;
		else
          num3=(num3<<1)+1;
        
        if(num3>=num1)
         {
		   num3=num3-num1;
         }		 
      }
    
     
	 flag=1;
    for(i=31;i>=0;i--)
      {
         if(flag && !(num3>>i & 1))
		  continue;
		flag=0;
        printf("%u",!(num3>>i & 1)); 		
		    
	  }
     printf("\n");	  
    //printf("%u",num1);
   // printf("\n%u",num2);
   // printf("\n%u",num3);	
  }
  return 0;
}
