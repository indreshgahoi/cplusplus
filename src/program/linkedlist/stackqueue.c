// implementing the queue with the 2 stacks
// stack1 and stck2
// 1. enquee operation o(1) because we just need to push the data into the stack1
// 2.dequee operation takes time actuaally we have to copy all the data from the stack 1 to stack 2
// and the the last operation that is pop from the stack 2
#include<stdio.h>
//#define NULL 0
struct node
{
	int data;
	struct node *next;
};

void push(struct node **s,int x)
{
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new->data=x;
	new->next=*s;
	*s=new;
}

int pop(struct node **s)
{
	int x;
	struct node *temp;
	if(!*s)
		return -1;
	temp=*s;
	*s=(*s)->next;
	x=temp->data;
	free(temp);
	return x;
}

struct queue
{
	struct node *stack1;
	struct node *stack2;
};
void enquee(struct queue *q,int x)
{
	push(&q->stack1,x);
}

int dequeue(struct queue *q)
{
	int x;
	if(q->stack1==NULL && q->stack2==NULL)
	{
		fprintf(stdout,"the queue is empty");
		return -1;
	}
	if(q->stack2==NULL)
	{
		while(q->stack1)
		{
			x=pop(&(q->stack1));
			push(&(q->stack2),x);
		}
	}
	x=pop(&q->stack2);

	return x;
}

int main(void)
{
	int n,ch;
	struct queue *q = (struct queue*)malloc(sizeof(struct queue));
	q->stack1 = NULL;
	q->stack2 = NULL;

	while(1)
	{
		printf("1 for enquee \n2for dequee \n3 for exit\n");
		scanf("%d",&ch);
		if(ch==3)
			exit(0);
		if(ch==1)
		{
			scanf("%d",&n);
			enquee(q,n);
		}
		else
		{int x;
		x=dequeue(q);
		printf("%d",x);
		}

	}



}
