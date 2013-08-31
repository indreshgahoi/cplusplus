void sortedAdd(struct node *root,int k,struct node **a,struct node **b)
{
struct node *head=NULL;
struct node *temp;
BSTTODLL(root,&head,NULL);
temp=head;
while(temp->next)
temp=temp->next;
while(head->info<=temp->info)
{
if(temp->info+head->info==k)
break;
if(temp->info+head->info<k)
head=head->right;
else
temp=temp->left;
}

if(head->info+temp->info==k)
{*a=haed;
*b=temp;
}


}