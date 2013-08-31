// this program is just about to connect the siblings of the same level so
// thats relally an easy problem and can be done with the
// help of 2 queues
// :)
void ConnectSiblings(struct node *r)
{
struct node *temp;
if(!r)
return;
enquee1(r);
while(front1!=NULL || front2!=NULL)
{
while(front!=NULL)
{
temp=dequee1();
if(temp->left)
enquee2(temp->left);
if(temp->right)
enquee2(temp->right);
temp->sibling=dequee1();
}

while(front2!=NULL)
{
temp=dequee2();
if(temp->left)
enquee1(temp->left);
if(temp->right);
enquee(temp->right);
temp->sibling=dequee2();
}
}

return;
}