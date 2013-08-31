#define NULL 0
typedef struct node
{
int item;
struct node *next;
}stack;
void push(stack* pus);
int pop();
stack *top=NULL;
int main()
{int ch,p,popped;
stack* temp;
while(1)
{
printf("what u want babes???");
printf("\n1.push\n2.pop\n3.exit");
scanf("%d",&ch);
if(ch==3)
{
exit(0);
}
else if(ch==1)
{
printf("enter the value");
scanf("%d",&p);
temp=(stack*)malloc(sizeof(stack));
temp->item=p;
push(temp);
printf("operation succes:)");
}
else
{
popped=pop();
if(popped==-1000)
{
printf("no item to popped :(plese push firset");
}
else
{
printf("\npopped item is:%d",popped);
}
}
}
}
void push(stack* pus)
{int t;
pus->next=top;
top=pus;
}
int pop()
{
if(top==NULL)
{
return(-1000);
}
else
{
int t;stack* temp;
t=top->item;
temp=top;
top=top->next;
free(temp);
return(t);
}
}



