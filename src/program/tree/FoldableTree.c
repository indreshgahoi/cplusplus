// A function which basically tells u weather a binary tee is foldable
//or not.


#include<stdio.h>

struct node
{
 int data;
 struct	node *left;
 struct node *right;
};

int isFoldable(struct node *r,struct node *l)
{
  if((!r && l)||(r && !l))
   return 0;
  else if(!r && !l)
   return 1;
   else
   return(isFoldable(r->left,l->right) && isFoldable(r->right,l->left));
}

int testFoldable(struct node *root)
{
if(!root)
return 1;

return(isFoldable(root->left,root->right));
}

