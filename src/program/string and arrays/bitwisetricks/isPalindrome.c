// this is something really a ultimate coding style
// just a way
// concept:
// just convert the given decimal digit number in the binary form but reversly


int isPalindrome(int n)
{
int tempval=n,reverse=0;
if(n&(n-1))
{
while(tempval!=0)
{
reverse=reverse*2+tempval%2;
tempval=tempval/2;
}
if(reverse==n)
{
printf("its palindrome");
return 1;
}
}
printf("not a palindrome");
return 0;

}
int main(void)
{
int n;
scanf("%d",&n);
isPalindrome(n);

return 0;
}
