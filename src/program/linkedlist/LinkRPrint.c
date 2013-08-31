#include<stdio.h>
struct Node
{
int item;
struct Node* next;
}*start;struct Node *temp;

void insert(int i);
void printReverse(struct Node* star);
int main()
{
int i;

for(i=1;i<=5;i++)
{
insert(i);
}
printReverse(start);

return(0);}

void insert(int i)
{struct Node *temp;
if(i==1)
{
start=(struct Node*)malloc(sizeof(struct Node));
start->item=i;
temp=start;
}
else
{
temp->next=(struct Node*)malloc(sizeof(struct Node));
temp=temp->next;
temp->item=i;
temp->next=NULL;
}
}
void printReverse(struct Node* star)
{
if(star==NULL)
return;
else
{
printReverse(star->next);
printf("\n%d",star->item);
}
}



