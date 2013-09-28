// A program to check weather two strings are rotations of each other or not??
// we can do it O(n) complexity :)
// suppose s1 and s2 are given
// concatenate the s1 and s1 and store in the temp
// check if s2 is the substring of s1 or not with the KMP matcher :)
// great thing is that KMP here is implemented :)
#include<stdio.h>
#include<string.h>

void Prefix(char P[],int Pre[])
{
	int k=0,q;
	int m=strlen(P);
	Pre[0]=0;

	for(q=1;q<=m-1;q++)
	{
		while(k>0 && P[k]!=P[q])
			k=Pre[k];
		if(P[k]==P[q])
			k++;
		Pre[q]=k;
	}
}




int KMP(char T[],char P[])
{
	int n,m,i,j,k,q;
	int Pre[100]={0};
	q=0;
	n=strlen(T);
	m=strlen(P);
	Prefix(P,Pre);
	for(i=0;i<=n-1;i++)
	{
		while(q>0 && P[q]!=T[i])
			q=Pre[q];
		if(P[q]==T[i])
			q++;
		if(q==m)
			return 1;
	}
	return 0;
}

int IsRotations(char *s1,char *s2)
{
	char *temp,*temp2=s1;
	int k,n,i;
	n=strlen(s1);
	for(i=n;i<=2*n-1;i++)
	{
		*(s1+i)=*(temp2+i-n);}
	*(s1+i)='\0';
	puts(s1);
	k=KMP(s1,s2);
	return k;
}
int main(void)
{
	char s1[10],s2[10];
	int i;
	gets(s1);
	gets(s2);
	puts(s1);
	puts(s2);

	i=IsRotations(s1,s2);
	if(i==0)
		printf("NOT ROTATIONS");
	else
		printf("Rotations");
	return 0;



}

