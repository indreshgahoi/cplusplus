/*This programme will do these operations ARRAY sorting,ARRAY display,TOTAL ARRAY OPERATION,
TWO D ARRAY*/

/*Wipro Technologies*/
#include <stdio.h>
#include <stdlib.h>

int array[] = { 3,8,25,28, 30, 33,36,49,80,90 };

void ARRAY()
{
	int a[3], i;
	printf(" Enter three numbers : ");
	for(i=0; i<3; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("Numbers are : ");
	for(i=0; i<3; i++)
	{
		printf("%d", a[i]);
	}
}
int getIntArray(int a[], int nmax, int sentinel)
{
   int n = 0;
   int temp;

   do {
     printf("Enter integer [%d to terminate] : ", sentinel);
     scanf("%d", &temp);
     if (temp==sentinel) break;
     if (n==nmax)
       printf("array is full");
     else
     a[n++] = temp;
   }while (1);
   return n;
}
void printIntArray(int a[], int n)
{
   int i;
   for (i=0; i<n;i++){
	     printf("%d ", a[i]);
   }
}
void intSwap(int *x, int *y)
{
   int temp = *x;
   *x = *y;
   *y = temp;
}

void reverseIntArray(int a[], int n)
{
   int i;
   for(i=0;i<n/2;i++)
	{
		intSwap(&a[i],&a[n-i-1]);
   	}
}


void TOTAL_ARRAY(void)
{
   int x[10];
   int hmny;

   hmny = getIntArray(x, 10, 0);
   printf("The array was: ");
   printIntArray(x,hmny);
   reverseIntArray(x,hmny);
   printf("after reverse it is:");
   printIntArray(x,hmny);
}


void ARRAY_TWOD()
{
	int a[3][3], i, j;
	printf("Enter matrix of 3*3 : ");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
		scanf("%d",&a[i][j]);
		}
	}
	printf(" Matrix is : ");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
		printf("%d",a[i][j]);
		}
	  // printf("");
	}

}
int main()
{
	int i,ch;



	while(1)
{
       printf("1 for ARRAY sorting...2 for ARRAY display...3 for TOTAL ARRAY OPERATION...4 for TWO D ARRAY5 for exit...");

       printf("Enter the correct choice...");
       scanf("%d",&ch);

       switch(ch)
       {
       case 1:
        	for (i=0; i<10; i++)
		printf("%d ", array[i]);
		break;
	case 2:
		ARRAY();
		break;
	case 3:
		TOTAL_ARRAY();
		break;
	case 4:
		ARRAY_TWOD();
		break;
	case 5:
		exit(1);
	default:
		printf("Wrong entry: Try again...");

	}
}

return 0;
}




