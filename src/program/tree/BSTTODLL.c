// this program basically convert a bst into the Doubly Linked List
// in sorted manner Inorder Traversal-- very simple.
//convert a binary tree into the Doubly linked list:)

#include "stdio.h"
struct Node
 {int data;   
 struct Node* left;    
struct Node* right; 
};


void BSTTODLL(struct Node *root,struct Node **prev,struct Node **head)
{
struct Node *right;
if(!root)
return;
BSTTODLL(root->left,prev,head);
root->left=*prev;
if(*prev!=NULL)
(*prev)->right=root;
else
*head=root;
right=root->right;
*prev=root;
BSTTODLL(root->right,prev,head);
}

struct Node* newnode(int data) 
{   struct Node* node = (struct Node*)malloc(sizeof(struct Node));   
node->data = data;   
node->left = NULL;   
node->right = NULL;     
return(node); }   
int main() 
{ 
struct Node *head,*prev;
struct Node* temp;
    struct Node *root = newnode(10);  
 root->left        = newnode(8);  
 root->right       = newnode(2);  
 root->left->left  = newnode(3);  
 root->left->right = newnode(5);  
 root->right->left = newnode(2);    
head=NULL;
prev=NULL;
BSTTODLL(root,&prev,&head);

temp=head;
while(temp->right!=NULL)
{
printf("%d  ",temp->data);
temp=temp->right;
}
printf("%d  \n",temp->data);
while(temp!=NULL)
{
printf("%d  ",temp->data);
temp=temp->left;
}
 return 0; 
} 
