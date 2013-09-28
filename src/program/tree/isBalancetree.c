#include "tree.h"int isBalance(struct node *r,int *height){	int lh,rh;	if(r==NULL)		return 1;	c=isBalance(r->left,&lh);	p=isBalance(r->right,&rh);	mods=abs(lh-rh);	if(c==0||p==0)		return 0;	if(mods>1)		return 0;	return 1;}



