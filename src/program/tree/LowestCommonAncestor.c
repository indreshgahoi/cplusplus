
#include<stdio.h>

typedef struct node 
{
	int info;
	struct node *left;
	struct node *right;
}Tree;

Tree *root=NULL;
Tree * LowestCommonAncestor(Tree *root,Tree *A,Tree *B)
{
	Tree *l,*r;
	l=NULL;
	r=NULL;
	if(!root)
		return(root);
	if(root->left==A||root->right==A||root->left==B||root->right==B)
	{
		return root;
	}
	l=LowestCommonAncestor(root->left,A,B);
	r=LowestCommonAncestor(root->right,A,B);
	if(l!=NULL && r!=NULL)
		return(root);
	l=l==NULL?r:l;
	return(l);
}
