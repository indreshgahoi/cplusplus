/*print the bst tree nodes in given range of k1 and k2.*/
#include<stdio.h>
typedef struct node
{
 int item;
 struct node* left;
 struct node *right;
}BST;
BST *root=0;
//not confuse with it it is not working like the integer zero else it is for initializing the special type of pointe*/

void PrintBst(BST *root,int k1,int k2)
{
 if(root)
 {
 PrintBst(root->left,k1,k2);
 if(root->item>k1 && root->item<k2)
 printf("%d",root->item);
 PrintBst(root->right,k1,k2);

}
return;}
