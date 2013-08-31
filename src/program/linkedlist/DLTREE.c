#include<stdio.h>
struct node
{
int item;
struct node *next;
struct node *prev;
};
struct node *head=NULL;

void inorder(struct node *root);
struct node* DLTREE(struct node *head);void traversal();
int main()
{
struct node *temp;
struct node* root=NULL;
temp=(struct node*)malloc(sizeof(struct node));
temp->item=1;
head=temp;
head->prev=NULL;
head->next=(struct node*)malloc(sizeof(struct node));
head->next->item=2;
head->next->prev=head;
head->next->next=NULL;
temp=head->next;

temp->next=(struct node*)malloc(sizeof(struct node));
temp->next->item=3;
temp->next->prev=temp;
temp->next->next=NULL;
temp=temp->next;

temp->next=(struct node*)malloc(sizeof(struct node));
temp->next->item=4;
temp->next->prev=temp;
temp->next->next=NULL;
temp=temp->next;

temp->next=(struct node*)malloc(sizeof(struct node));
temp->next->item=5;
temp->next->prev=temp;
temp->next->next=NULL;
temp=temp->next;

temp->next=(struct node*)malloc(sizeof(struct node));
temp->next->item=6;
temp->next->prev=temp;
temp->next->next=NULL;
temp=temp->next;


temp->next=(struct node*)malloc(sizeof(struct node));
temp->next->item=7;
temp->next->prev=temp;
temp->next->next=NULL;
temp=temp->next;


temp->next=(struct node*)malloc(sizeof(struct node));
temp->next->item=8;
temp->next->prev=temp;
temp->next->next=NULL;
temp=temp->next;

temp->next=(struct node*)malloc(sizeof(struct node));
temp->next->item=9;
temp->next->prev=temp;
temp->next->next=NULL;
temp=temp->next;

temp->next=(struct node*)malloc(sizeof(struct node));
temp->next->item=10;
temp->next->prev=temp;
temp->next->next=NULL;
temp=temp->next;

root=DLTREE(head);
inorder(root);
return 0;
}


struct node* DLTREE(struct node *head)
{

struct node *x=NULL;
struct node *y=NULL;

if(head)
{

x=head;
y=head;
while(y->next!=NULL && y->next->next!=NULL)
{
y=y->next;
y=y->next;
x=x->next;
}

if(x->prev!=NULL)
{
x->prev->next=NULL;
x->prev=DLTREE(head);
}

if(x->next!=NULL)
x->next->prev=NULL;
x->next=DLTREE(x->next);
}

return(x);
}

void inorder(struct node *root)
{
if(root)
{
inorder(root->prev);
printf("%d",root->item);
inorder(root->next);
}

return;
}
void traversal()
{
struct node *temp=head;
while(temp!=NULL)
{
printf("%d",temp->item);
temp=temp->next;
}

}