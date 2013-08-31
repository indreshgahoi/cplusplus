#include<stdio.h>
#include<math.h>
struct numbers
{
  int integer;
  int times;
};
void quick(struct numbers *b,int s,int e)
{        int q;
	if(s<e)
	{
		q=partition(b,s,e);
		quick(b,s,q-1);
		quick(b,q+1,e);
	}

}
 int partition(struct numbers *c,int p,int r)
{
	 int i=p-1,temp,j,temp1;
	 int x=(c+r)->integer;
	for(j=p;j<=r;j++)
	{
		if((c+j)->integer>=x)
	       {
			i++;
			temp=(c+i)->integer;
			temp1=(c+i)->times;
			(c+i)->integer=(c+j)->integer;
			(c+i)->times=(c+j)->times;
			(c+j)->integer=temp;
			(c+j)->times=temp1;
	       }
	}
	return(i);

}
 int noOfdig( int num)
{  int i=0;
while(num)
{
i++;
num=num/10;
}
return(i);
}
 int leftcon(int nl,int nr)
{
   int nd=noOfdig(nr);
   return(nl*pow(10,nd)+nr);


}
 int rightcon(int nr, int nl)
{
	 int nd=noOfdig(nl);
   return(nr*pow(10,nd)+nl);
}

int main(void)
{

int cho,n,i,j,temp,k,flag=0;
 int count=0;
struct numbers *array,array1[10];

printf("Enter the no in array as u want");
scanf("%d",&n);
array=(struct numbers*)malloc(n*sizeof(struct numbers));
for(i=0;i<n;i++)
{
 array[i].times=0;
 array[i].integer=0;
 }
 printf("enter the no");
 i=0;
 while(i<n)
 { flag=0;
   scanf("%d",&temp);
   for(j=0;j<i;j++)
   { if(array[j].integer==temp)
     {   flag =1;
	array[j].times++;

	break;
     }

   }
   if(flag==0)
   {
   array[count].integer=temp;
   array[count].times++;
   count++;
 }
i++;

 }
 quick(array,0,count-1);
 printf("\n Enter the no. of elements as  u choose");
 scanf("%d",&cho);
 temp=array[0].integer;
for(i=cho-n+array[0].times;i>1;i--)
 {
    temp= leftcon(temp,array[0].integer);
}
array[0].integer=temp;
 i=1;
 while(i<count)
 {
   temp=array[i].integer;
   for(k=array[i].times;k>1;k--)
 {
    temp= leftcon(temp,array[i].integer);
 }
 array[i].integer=temp;
   i++;

 }



 i=0;
 while(i<count)
 {
   printf("\n %d   %d",array[i].integer,array[i].times);
   i++;
 }


   for(i=0;i<10;i++)
   {
    array1[i].integer=0;
   }
   for(i=0;i<count;i++)
   {
     temp=noOfdig(array[i].integer);
     temp=array[i].integer/pow(10,temp-1);
     if(array1[temp].integer==0)
     {array1[temp].integer=array[i].integer;
     }
     else if(leftcon(array1[temp].integer,array[i].integer)>leftcon(array[i].integer,array1[temp].integer))
	   {
	   array1[temp].integer=leftcon(array1[temp].integer,array[i].integer);
	   }
	   else
	   array1[temp].integer=leftcon(array[i].integer,array1[temp].integer);
	   }


  printf("\n \n   the nois: ");

 i=9;
 while(i>=0)
 { if(array1[i].integer!=0)
   printf("%d",array1[i].integer);
   i--;
 }
	

 return(0);
}
