// word sorting is just similar to as common sorting but
// complexity O(n^2m) where m is size of string because it takes linear time to compare two words by strcmp



#include<stdio.h>
#include<string.h>
void insertionSorting(char *strings[],int n)
{

	int i,j;
	char *key;
	for(i=1;i<=n-1;i++)
	{
		key=strings[i];
		for(j=i-1;j>=0 && strcmp(strings[j],key)>0;j--)
			strings[j+1]=strings[j];

		strings[j+1]=key;
	}
	return;
}



int main(int argc,char **argv)
{
	int i,j,key;
	char *strings[]={"ankur","shukla","my","fool","beautiful","solicitor","militry","forth"};
	insertionSorting(strings,8);
	for(i=0;i<=7;i++)
		puts(strings[i]);


	return 0;
}
