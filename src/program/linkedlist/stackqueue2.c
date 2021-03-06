
// implementation of queue using the one stack
// only and with the help of recursion we are actually creating the second stack
//a wonderful approach
// and a good question to ask in the interview :)
struct node
{
	int data;
	struct node *next;
};
void push(struct node **stack,int x)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	if(!stack)
	{
		*stack=temp;
		*stack->next=0;
	}
	temp->next=*stack->next;
	*stack=temp;
}


int pop(struct node **stack)
{
	int x;
	struct node *temp;
	if(!*stack)
	{
		printf("stack is empty");
		return -1;
	}
	temp=*stack;
	*stack=(*stack)->next;
	x=temp->data;
	free(temp);
	return x;
}

struct queue
{
	struct node stack;
};
void enquee(struct queue *q,int x)
{
	push(&q->stack,x);

}

int dequeue(struct queue *q)
{
	int res;
	if(&q->stack==0)
	{
		printf("the queue is empty");
		exit(0);// the whole program will terminate because this is the error
	}
	else if(&q->stack->next==0)
	{
		return(pop(&q->stack));
	}
	else
	{

		x=pop(&q->stack);
		res=dequeue(q);
		push(&q->stack);
	}
	return res;
}
