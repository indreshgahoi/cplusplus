// the number is given find the immediate greater number to it
// like 1897
//  given then from digits 1897 only find the nearest greater number :)
//1978 is the answer :)
// given 1321
// answer should be 2113
// algorithm is quite easy :)
// 1. conver first number into the char array
//2.iterate from the last index till u dont find such s[i]<s[i+1] if there is no such i then highset number not possible
// as u find i just sort i+1 to the n-1
// then swap the s[i] to that j in i+1 to n-1 such that s[j]>s[i] but !(s[j-1]>s[i)

#include"stdio.h"

void insertionsort(char *s,int n,int st)
{
	int i,j;
	int key;
	i=st+1;
	for(i=st+1;i<=st+n-1;i++)
	{
		key=s[i];
		for(j=i-1;j>=st &&s[j]>=s[i];j--)
			s[j+1]=s[j];
		s[j+1]=key;
	}
}

void ImmediateGreater(int num)
{
	static char s[100];
	int i,j;
	int c;
	char temp;
	sprintf(s,"%d",num);
	c=0;
	while(num)
	{
		num=num/10;
		c++;
	}
	s[c]='\0';
	for(i=c-2;i>=0 && s[i]>=s[i+1];i--);
	printf("%d\n",i);
	puts(s);
	if(i<0)
	{
		printf("this is itself the greatest number");
		return;
	}
	else
	{
		insertionsort(s+i+1,c-i-1,0);

		for(j=i+1;j<=c-1;j++)
		{
			if(s[i]<s[j])
				break;
		}
		temp=s[j];
		s[j]=s[i];
		s[i]=temp;
		num=atoi(s);
		fprintf(stdout,"%d",num);
	}
	return;
}

int main(void)
{
	int num;
	scanf("%d",&num);

	ImmediateGreater(num);
	return 0;

}
