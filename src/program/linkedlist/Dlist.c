#include<stdio.h>
typedef struct node
{
int item;
struct node *prev;
struct node *next;
}Dlist;
Dlist *head=NULL;
void insertion(int n);
void reverse();
void see();
//a doubly linked list reversal program:)
int main()
{
int ch,n;

while(1)
{
printf("what u wanna baby:)");
printf("\n1.insertion\n2.reversal");
printf("\n3.exit");
printf("\n4.see");
scanf("%d",&ch);
if(ch==3)
{
exit(0);
}
else if(ch==1)
{
printf("\nenter the value to insert in a dlist");
scanf("%d",&n);
insertion(n);
}
else if(ch==2)
{
reverse();
}
else
{
see();
}
}
return(0);
}

void insertion(int n)
{
Dlist *temp=(Dlist*)malloc(sizeof(Dlist));
temp->item=n;
temp->next=NULL;
if(head==NULL)
{
head=temp;
head->prev=NULL;
head->next=NULL;
}
else
{
Dlist *temp2;
temp2=head;
while(temp2->next!=NULL)
temp2=temp2->next;
temp2->next=temp;
temp->prev=temp2;
}
}

void reverse()
{
Dlist *temp=head;
Dlist *temp2,*temp3;
while(temp->next!=NULL)
{
temp2=temp;
temp=temp->next;
temp3=temp2->next;
temp2->next=temp2->prev;
temp2->prev=temp3;
}
temp3=temp->next;
temp->next=temp->prev;
temp->prev=temp3;

head=temp;
}
void see()
{
Dlist *temp=head;
while(temp!=NULL)
{
printf("%d\n",temp->item);
temp=temp->next;
}
return;
}
