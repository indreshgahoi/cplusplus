struct node * inOrderSuccessor(struct node *root, struct node *n)
{
    if( n->right != NULL )
        return minValue(n->right);
    struct node *succ=NULL;
    while(root)
    {
        if(n->data < root->data)
        {
            succ=root;
            root=root->left;
        }
        else if(n->data > root->data)
            root=root->right;
        else
           break;
    }
    return succ;
}