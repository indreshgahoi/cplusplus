#include "tree.h"

struct node * inOrderSuccessor(struct node *root, struct node *n)
{
    if( n->right != NULL )
        return minValue(n->right);
    struct node *succ=NULL;
    while(root)
    {
        if(n->info < root->info)
        {
            succ=root;
            root=root->left;
        }
        else if(n->info > root->info)
            root=root->right;
        else
           break;
    }
    return succ;
}
