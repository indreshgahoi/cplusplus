// find the level of a given node

//1. is for iterative procedure for the BST ONLY.

#include<stdio.h>

struct node
{
	int item;
	struct	node *left;
	struct node *right;
};

int getLevelI(struct node *T,int item)
{
	if(T)
	{
		int l=0;
		struct node *temp=T;
		while(temp->item!=item && temp!=0)
		{
			l++;
			if(temp->item>item)
				temp=temp->left;
			else
				temp=temp->right;
		}
		if(temp)
			return l;
		else
			return -1;
	}
	return -1;
}

//2. is for the recursive procedure.general problem means for the binary tree.
int getLevelR(struct node* T,int item)
{
	static int k=0;
	if(!T)
		return 0;
	k++;
	if(T->item==item)
		return k;

	return(getLevelR(T->left)|getLevelR(T->right));
}



