//iterartive way to traverse the binary tree
// 1.preorder
// 2. inorder
//3.postorder traversal 
//based on the depth first serch algorithms.
//1.

#include<stdio.h>
#include "tree.h"

typedef struct stack stack;
push(stack,struct node*);

void PreorderIt(struct node *root)
{
	struct node *temp;
	Push(root);
	while(top!=NULL)
	{
		temp=Pop();
		printf("%d",temp->info);
		if(temp->right!=NULL)
			Push(temp->right);
		if(temp->left!=NULL)
			Push(temp->left);
	}
}
//2.
void Inorder(struct node *root)
{
	struct node *temp=root;
	while(temp!=NULL ||top!=NULL )
	{
		if(temp!=NULL)
		{
			Push(temp);
			temp=temp->left;
		}
		else
		{
			temp=Pop();
			printf("%d",temp->info);
			temp=temp->right;
		}
	}
}






//3.PostOrder Traversal
void PostOrderTraversal(struct node *root)
{
	stack s1,s2;
	if(!root)
		return;
	push(s1,root);
	while(!isEmpty(s1))
	{
		struct node *temp;
		temp=pop(s1);

		if(temp->left)
			push(s1,temp->left);

		if(temp->right)
			push(s1,temp->right);
	}

	while(!isEmpty(s2))
	{
		printf("%d ",pop(s2));
	}

}






