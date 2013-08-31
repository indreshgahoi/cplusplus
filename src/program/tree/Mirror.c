
#include<stdio.h>

struct node
{
 int data;
 struct	node *left;
 struct node *right;
};

void Mirror(struct node *r)
{
struct Node *temp;
if(!r)
return;
Mirror(r->left);
Mirror(r->right);
temp=r->left;
r->left=r->right;
r->right=temp;
}
