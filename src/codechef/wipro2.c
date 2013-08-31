/* ****************************WIPRO TECHNOLOGIES******************************** */
/* Amenu Dreiven Program for Adding,Subtracting,Multiply and dividing the Complex numbers*/

#include <stdio.h>
#include <stdlib.h>

struct complex
{
    int real, img;
};

int main()
{
    int choice, temp1, temp2, temp3,temp4,temp5,temp6;
    struct complex a, b, c;

    while(1)
    {
        printf("Press 1 to add two complex numbers.Press 2 to subtract two complex numbers.Press 3 to multiply two complex numbers.Press 4 to divide two complex numbers.Press 5 to exit.Enter your choice ");
        scanf("%d",&choice);
     if(choice >= 1 && choice <= 4)
        {
            printf("Enter a and b where a + ib is the first complex number.a = ");
            scanf("%d", &a.real);
            printf("b = ");
            scanf("%d", &a.img);
            printf("Enter c and d where c + id is the second complex number.c = ");
            scanf("%d", &b.real);
            printf("d = ");
            scanf("%d", &b.img);
        }
        switch(choice){

        case 1:
            c.real = a.real + b.real;
            c.img = a.img - b.img;

            if ( c.img >= 0 )
                printf("Sum of two complex numbers = %d + %di",c.real,c.img);
            else
                printf("Sum of two complex numbers = %d %di",c.real,c.img);
            break ;
        case 2:
            c.real = a.real - b.real;
            c.img = a.img - b.img;

            if ( c.img >= 0 )
                printf("Difference of two complex numbers = %d + %di",c.real,c.img);
            else
                printf("Difference of two complex numbers = %d %di",c.real,c.img);
            break;

        case 3:
            c.real = a.real*b.real - a.img*b.img;
            c.img = a.img+b.real + a.real*b.img;

            if ( c.img >= 0 )
                printf("Multiplication of two complex numbers = %d + %di",c.real,c.img);
            else
                printf("Multiplication of two complex numbers = %d %di",c.real,c.img);
             break ;
          case 4:
         if ( b.real == 0 && b.img == 0 )
                printf("Division by 0 + 0i is not allowed.");
            else
            {
                temp1 = a.real*b.real + a.img*b.img;
                temp2 = a.img*b.real + a.real*b.img;
                temp3 = b.real*b.real + b.img*b.img;
                temp4 =temp1%temp3;
                temp5=temp2%temp3;
                if(temp4==0)
                {
                    printf("Division of two complex numbers = %d ",temp1/temp3);
                }
                else
                {
                  printf("Division of two complex numbers = %d/%d ",temp1,temp3);
                }
                if(temp5==0)
                {
                     temp6=temp2/temp3;
                    if ( temp6 >= 0)
                        printf("+ %di",temp6);
                    else
                        printf("%di",temp6);

                }
                else
                {
                   if ( temp2/temp3 >= 0)
                        printf("+ %d/%di",temp2,temp3);
                    else
                        printf("%d/%di",temp2,temp3);
                }


           }
           break ;

        case 5:
               exit(0);
       default:
            printf("Invalid choice.");
        }
       printf("Press any key to enter choice again...");
}
  return 0;
}
