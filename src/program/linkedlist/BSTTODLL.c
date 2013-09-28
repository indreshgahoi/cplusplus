
struct node {
	struct node *left;
	struct node *right;
};

void BSTTODLL(struct node *root,struct node **prev,struct node **head)
{
	struct node *right;
	if(!root)
		return;
	BSTTODLL(root->left,prev,head);
	root->left=*prev;
	if(*prev!=0)
		*prev->right=root;
	else
		*head=root;
	right=root->right;
	prev=root;
	BSTTODLL(root->right,prev,head);
}
