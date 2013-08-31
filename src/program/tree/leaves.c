#include<stdio.h>
#include <GL/glu.h>

typedef struct node
{
int item;
struct node *left;
struct node *right;
}Tree;
Tree *root=NULL;
int insert(int n);
int countleaves(Tree *T);
int countnodes(Tree *T);
int main()
{
while(1)
{
int ch;
printf("\nwhat u want baby tell me:P");
printf("\n1.insertion\n2.count nodes\n3.count leaves\n4.exit\n");
scanf("%d",&ch);
if(ch==4)
{
exit(0);
}
else if(ch==3)
{
int n;
n=countleaves(root);
printf("\nthe number of leaves nodes are:%d",n);
}
else if(ch==2)
{
int n;
n=countnodes(root);
printf("\nthe number of nodes are:%d",n);
}
else
{
int n;
printf("enter the value to insert");
scanf("%d",&n);
n=insert(n);
}
}
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
int countleaves(Tree *T)
{
if(T==NULL)
return 0;
else if(T->left==NULL && T->right==NULL)
return 1;
return(countleaves(T->left)+countleaves(T->right));
}
int countnodes(Tree *T)
{
if(T==NULL)
return 0;
return(countnodes(T->left)+countnodes(T->right)+1);
}


