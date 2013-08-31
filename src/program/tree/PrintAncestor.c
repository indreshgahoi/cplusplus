//Print Ancestors of a given node in Binary Tree

struct node
{
int item;
struct node *left;
struct node *right;
}*root=0;
void PrintAncestor(struct node *root,int target)
{
if(root)
{
struct node *temp;
temp=root;
while(temp->item!=target)
{
printf("%d",temp->item);
if(target<temp->item)
temp=temp->left;
else
temp=temp->right;
}

}
return;
}
