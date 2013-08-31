
#include<stdio.h>

struct node
{
 int data;
 struct	node *left;
 struct node *right;
};

int hasPathSum(struct node *R,int sum)
{
if(R==NULL)
return(sum==0);
return(hasPathSum(R->left,sum-R->data)||hasPathSum(R->right,sum-R->data));
}


