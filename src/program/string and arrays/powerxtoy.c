// power of x to n that is x^n in lgn time its really cool
// trick and very efficient at all :)
int powerxton(int x,int y)
{
	int temp;
	if(y==0)
		return 1;
	temp=powerton(x,y/2);
	if(y%2==0)
		return temp*temp;
	else
		return x*temp*temp;
}
int main(void)
{
	int x,y;
	scanf("%d%d",&x,&y);
	x=powerxtoy(x,y);
	printf("%d",x);


}
