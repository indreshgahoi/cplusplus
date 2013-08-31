// this is a question to check weather a a given tree is a subtree of other
// just a simple question :)

int isSubtree(struct node t1,struct node t2)
{int k;
if(t1==NULL)
return 0;
if(t2==NULL)
return 1;
if(t1.data==t2.data)
int k=similar(t1,t2);
return (k||isSubtree(t1->left,t2)||(t1->right,t2));
}


int similar(struct node *t1,struct node *t2)
{
if(t1==NULL && t2==NULL)
return 1;
else if(t1==NULL || t2==NULL)
return 0;
else
return(t1->data==t2->data && similar(t1->left,t2,left) && similar(t1->right,t2->right));
}
