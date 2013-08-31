#include<stdio.h>
int main()
{
 int h;
  int i,j,s;
 printf("Enter the hight:\n");
 scanf("%d",&h);
 
    j=1;
   while(j<=h){
      
          for(i=h;j<=i;i--)
           printf("%d",i);
        printf("\n");
        j++;
   } 


  j=1;
 while(j<=h){
       
         for(s=1;s<=h-j;s++)
            printf(" ");
         for(i=1;i<=j;i++)
           printf(" *");
 printf("\n");
     j++;
}

j=1;
while(j<=h){
    for(i=1;i<=j;i++)
     printf(" ");       
    for(s=1;s<=h-j;s++)
     printf(" *");
    printf("\n");


j++;
}


printf("%d%d",'A','a');
 return 0;
}
 
