#include<stdio.h>

typedef struct node
{
	int item;
	struct node *left;
	struct node *right;
}Tree;
Tree *root=NULL;


int isSumTree(Tree *t)
{
	if(t==NULL||(t->left==NULL && t->right==NULL))
		return (1);
	if(isSumTree(t->left) && isSumTree(t->right))
	{
		int ls,rs;
		if(t->left==NULL)
			ls=0;
		else if(t->left->left==NULL && t->left->right==NULL)
			ls=t->left->item;
		else
			ls=2*t->left->item;
		if(t->right==NULL)
			rs=0;
		else if(t->right->right==NULL && t->right->left==NULL)
			rs=t->right->item;
		else
			rs=2*t->right->item;
		return(t->item == ls+rs);
	}
	return 0;
}
