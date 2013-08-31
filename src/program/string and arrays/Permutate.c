#include<stdio.h>
void permutate2( char str[], int index )
{char temp;
    int i = 0;
    static lastChar = 0;
    if( index == strlen(str) )
    { // We have a permutation so print it
        printf("%s",str);
        return;
    }
    for( i = index; i < strlen(str); i++ )
    {
        if( lastChar == str[i] ) {
            continue;
        } else {
            lastChar = str[i];
        }
        temp=str[index];
str[index]=str[i];
str[i]=temp;
        permutate2( str, index + 1 );
        temp=str[index];
str[index]=str[i];
str[i]=temp;
    }
}

void Permutate(char str[],int index)
{
int i;
char temp;
if(index==strlen(str))
{
printf("%s ",str);
return;}
for(i=index;i<=strlen(str);i++)
{
temp=str[index];
str[index]=str[i];
str[i]=temp;
Permutate(str,index+1);
temp=str[index];
str[index]=str[i];
str[i]=temp;
}
}
int main()
{
char str[20];
printf("enter the string for permutation");
fgets(str,3,stdin);
Permutate(str,0);
printf("\n");
permutate2(str,0);
return 0;

}