// again a wonderful level order traversal with stacks but in spiral order :)
#include<stdio.h>

typedef struct Node
{
	int info;
	struct Node *left;
	struct Node *right;
}Tree;

typedef struct node 
{
	Tree *item;
	struct node *next;
}Stack;
Stack top1=NULL;
Stack top2=NULL;

void LevelOrderSpiral(Tree *root )
{
	Tree *temp;
	if(!root)
		return;
	Push1(root);
	while(top1!=NULL||top2!=NULL)
	{
		while(top1!=NULL)
		{
			temp=Pop1();
			printf("%d",temp->info);
			if(temp->left)
				Push2(temp->left);
			if(temp->right)
				Push2(temp->right);
		}
		printf("\n");
		while(top2!=NULL)
		{
			temp=Pop2();
			printf("%d",temp->info);
			if(temp->right)
				Push2(temp->right);
			if(temp->left)
				Push(temp->right);
		}
		printf("\n");
	}
}
