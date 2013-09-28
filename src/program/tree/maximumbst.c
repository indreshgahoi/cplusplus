
#include<stdio.h>

struct node
{
	int data;
	struct	node *left;
	struct node *right;
};


struct node * maximumBST(struct node *r,int *size)
{
	int ls,rs;
	struct node *le,re;
	if(!r)
	{
		*size=0;
		return r;
	}
	le=maximumBST(r->left,&ls);
	re=maximumBST(r->right,&rs);
	if(r->left!=le||r->right!=re)
	{
		if(ls>rs)
		{
			*size=ls;
			return(le);
		}
		else
		{
			*size=rs;
			return(re);
		}
	}
	else if(r->left->data <=r->data && r->right->data>r->data)
	{
		*size=ls+rs+1;
		return r;
	}
	else
	{
		if(ls>rs)
		{
			*size=ls;
			return le;
		}
		else
		{
			*size=rs;
			return re;
		}
	}
}
