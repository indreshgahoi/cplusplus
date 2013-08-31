void BSTTODLL(struct node *root,struct node **prev,struct node **head)
{
struct node *right;
if(!root)
return;
BSTODLL(root->left,prev,head);
root->left=*prev;
if(*prev!=NULL)
*prev->right=root;
else
*head=root;
right=root->right;
prev=root;
BSTDLL(root->right,prev,head);
}