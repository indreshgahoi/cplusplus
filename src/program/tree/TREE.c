#include<stdio.h>
typedef struct Node
{
int item;
struct Node *left;
struct Node *right;
}Tree;Tree *root=NULL;
int insert(int n);
void Printinorder(Tree *start);

int main()
{
int ch,n;
while(1)
{
printf("what u wanna baby tell me :P");
printf("\n1.insertion in a tree\n2.deletion in a tree\n3.exit\n4.wanna see babes");
scanf("%d",&ch);
if(ch==3)
{
exit(0);
}
else if(ch==1)
{
printf("enter the value to insert");
scanf("%d",&n);
n=insert(n);
}
else if(ch==2)
{
printf("enter the velue for deletion");
}
else if(ch==4)
{
Printinorder(root);
}
}
return(0);
}
int insert(int n)
{
Tree *temp=(Tree*)malloc(sizeof(Tree));
temp->item=n;
temp->right=NULL;
temp->left=NULL;
if(root==NULL)
{
root=temp;
root->left=NULL;
root->right=NULL;
return(1);
}
else{
Tree *temp2=root;
while(1)
{
if(temp2->item>=temp->item)
{
if(temp2->left==NULL)
{
temp2->left=temp;
return(1);
}
else
{
temp2=temp2->left;
}
}
else
{
if(temp2->right==NULL)
{
temp2->right=temp;
return(1);
}
else
{
temp2=temp2->right;
}
}
}
}
}
void Printinorder(Tree *start)
{
if(start==NULL)
return;
Printinorder(start->left);
printf("%d\n",start->item);
Printinorder(start->right);
}
