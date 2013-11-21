#include<stdio.h>
/*

    Big endian machine: Stores data big-end first. When looking at multiple bytes,
                        the first byte (lowest address) is the biggest.
    Little endian machine: Stores data little-end first. When looking at multiple bytes,
                            the first byte is smallest.

*/

int main(){
 int x=1;
 char *ptr =(char *)&x;

 printf(" %p %d\n",ptr,*ptr++);
 printf(" %p %d\n",ptr,*ptr++);
 printf(" %p %d\n",ptr,*ptr++);
 printf(" %p %d\n",ptr,*ptr++);

 return 0;
}
