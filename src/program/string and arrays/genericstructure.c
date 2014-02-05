
#define NULL 0
struct node
{
	void *points;
	struct node *next;
}*top=NULL;

void push(void *p)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	if(!top)
	{
		top=temp;
		top->points=p;
		top->next=NULL;
	}
	else
	{
		temp->points=p;
		temp->next=top;
		top=temp;
	}
}

void *pop()
{
	void *p;
	struct node *temp;
	if(!top)
		return NULL;

	temp=top;
	top=top->next;
	p=temp->points;
	free(temp);
	return p;
}



int main()
{
	int a,*b;
	float c,*e;
	char d,*f;
	a=8;
	c=9.89f;
	d='a';
	printf("%c",d);

	push(&c);
	push(&d);
	push(&a);
	b=pop();
	f=pop();
	e=pop();

	printf("%c %d %f",*f,*b,*e);
	return 0;



}
