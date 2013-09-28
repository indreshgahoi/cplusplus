#include "tree.h"

void adduptox(struct node *tree,int c)
{
	static int A[100],x;
	if(tree)
	{
		adduptox(tree->left);
		if(tree->info>x)
			return;
		else
		{
			if(c==0)
			{
				A[c++]=tree->info;
			}
			else
			{
				int i;
				for(i=0;i<c && tree->info+A[i]<x;i++)
				{
					printf("(%d ,%d)",A[i],tree->info);
				}
				A[c++]=tree->info;
			}
		}
		adduptox(tree->right);
	}
}
