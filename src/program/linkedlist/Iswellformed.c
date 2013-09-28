#define NULL 0
struct node
{
	char s;
	struct node *next;
};
struct node *top=NULL;
void push(char c)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->s=c;
	if(!top)
	{
		top=temp;
		top->next=NULL;
		return;
	}
	temp->next=top;
	top=temp;
}
char pop()
{
	struct node *temp;
	if(!top)
		return('0');
	else
		temp=top;
	top=top->next;
	return(temp->s);
}
int isempty()
{
	if(!top)
		return 1;
	else
		return 0;

}


int IswellFormed(char str[])
{
	int n;
	int i;
	char c;
	n=strlen(str);
	for(i=0;i<=n-1;i++)
	{
		if(str[i]=='(')
			push(str[i]);
		if(str[i]==')')
			c=pop();
		if(c=='0')
		{
			printf("not well formed" );
			return 0;
		}
	}
	if(isempty())
	{
		printf("well formed");
	}
	else
		printf("not well formed");
	return 0;
}
int main(void)
{
	char str[100];
	gets(str);
	IswellFormed(str);
	return 0;
}
