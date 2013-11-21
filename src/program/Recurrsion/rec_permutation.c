#include<stdio.h>
#include<string.h>
#define STRING "11122"

static void swap(char* s,char* t){
	char temp;

	temp=*s;
	*s=*t;
	*t=temp;
}

static void rec_permutation(char *a,int start,int last){

	int j;
	char set[10]={0};
	if(start==last)
	{
		printf("%s\n",a);
	}
	else{

		for(j=start;j<=last;j++){


			if(!set[*(a+j)-'0']){
				set[*(a+j)-'0']=1;
				swap((a+start),(a+j));
				//   printf(" %s (%d ,%d)",a,start+1,j);

				rec_permutation(a,start+1,last);

				//   printf(" %s ",a);
				swap((a+start),(a+j));}
			//set[*(a+j)-'0']=0;}
			//    printf(" %s ",a);

		}
	}
}




int main()
{
	char str[]=STRING;

	rec_permutation(str,0,strlen(str)-1);
	// system("time");
	return 0;

}

