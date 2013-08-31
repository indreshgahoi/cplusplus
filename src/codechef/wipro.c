#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void Reverse();
void GCD();
void Prime();
void LCM();
 int main()
{
 int no;
 do
 {
 printf("1.Reverse of a number 2.GCD 3. LCM 4. Prime 5. Exit ");
 printf("Enter Ur choice");
 scanf("%d",&no);

 switch(no)
 {
	case 1:  Reverse();
		 break;
       case 2:  GCD();
		 break;
       case 3:  LCM();
           break;
	case 4:  Prime();
		 break;
	default: exit(0);
 }
 }while(1);
 return 0;
 }
 void Reverse()
 {
	char num[20];
	int len,i;
	printf("Enter any number");
	scanf("%s",num);
	len=strlen(num);

	printf("Reverse of a given no=");
	 for(i=len-1;i>=0;i--)
	 {
	     printf("%c",num[i]);
	 }
 }


 void GCD()
 {
	int a,b,c,d;
	printf("Enter 2 nos");
	scanf("%d %d",&a,&b);
	c=a;
	d=b;
	while(a!=b)
       {
		if(a>b)
		a=a-b;
		else
		b=b-a;
	}
	printf("GCD of %d and %d =%d",c,d,a);
}

 void LCM()
 {
	int a,b,c,d;
	int prod,lcm;
	printf("Enter 2 nos");
	scanf("%d %d",&a,&b);
	prod=a*b;
	c=a;
	d=b;
	while(a!=b)
	{
		if(a>b)
		a=a-b;
		else
		b=b-a;
	}
	printf("GCD of %d and %d =%d",c,d,a);
	lcm=prod/a;
	printf("LCM of %d and %d =%d",c,d,lcm);

}

void Prime()
{
	int numb, i=2,c=1;
	printf("Enter a number");
	scanf("%d",&numb);
	while(numb>=i*i)
	{
		  if((numb%i)==0)
		  {
			printf("numb %d is not a prime no",numb);
			c=0;
			break;
		  }
		  i++;
	}
	if(c)
	{
		printf("The numb %d is a prime number",numb);
	}


}
