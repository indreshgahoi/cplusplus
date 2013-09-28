// Diameter of the tree

#include<stddef.h>

struct node
{
	int data;
	struct	node *left;
	struct node *right;
};
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int Diameter(struct node *R,int *height)
{
	int ld=0;
	int rd=0;
	int rh=0;
	int lh=0;

	if(R==NULL)
	{
		*height=0;
		return 0;
	}
	ld=Diameter(R->left,&lh)+1;
	rd=Diameter(R->right,&rh)+1;
	*height=(lh>rh?lh:rh)+1;
	return(max(lh+rh+1,max(ld,rd)));
}

