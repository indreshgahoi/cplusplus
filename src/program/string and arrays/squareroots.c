// find the square root of a given number
// a better way to implement the Newton Raphson method
// for this
// we know x1=x0-f(x0)/f'(x0)
// for squrae roots
// let x^2=n
// f(x)=x^2-n;
// 

#include<stdio.h>
#include<stdlib.h>
float getsquareroots(float num)
{
float x1;
float x2=0;
float prev;
x1=num/2;
if(x1*x1==num)
return x1;
prev=x1;
while(x1!=x2)
{
x1=prev;
x2=x1-(x1*x1-num)/(2*x1);
if(x2*x2==num)
return x2;
prev=x2;
}
return x2;
}
int main(void)
{
float sqroot;
float num;
puts("enter the number for squareroot");
scanf("%f",&num);
sqroot=getsquareroots(num);
printf("the square root is %f",sqroot);
return 0;

}