 
// ultimate algorithm loved it :) because this function wont need any other help of the function beautiful algorithm.
int kthMin(NODEPTR T,int *k)
{
int x;
if(T==0)
return INT_MAX;
x=kthMin(T->left,k);
if(x!=INT_MAX) 
//very much punch line of this question
retrun x;
(*k)--;
if(*k==0)
return(T->data);
retrun(kthMin(T->right,k));
}

//2.this algorithm uses the use of other function.

int countNodes(struct node *T)
{
if(T==0)
return 0;
else
return(1+countNodes(T->left)+countNodes(T->right));
}
/*
int kthMin(struct node* T,int k)
{
int left
if(T==0)
return -90;
left=countNodes(T->left)
if(left+1==k)
return(T->info);
if(left>k)
return(kthMin(T->left,k));
else
return(kthMin(T->right,k-left-1)); 
}*/