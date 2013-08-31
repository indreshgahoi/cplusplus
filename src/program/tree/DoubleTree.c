#include "stdio.h"
struct Node
 {
 int data;
 struct Node* left;    
 struct Node* right;
};
 void DoubleTree(struct Node *T)
{
 struct Node* temp;
  if(T==NULL)
   return;
  DoubleTree(T->left);
  DoubleTree(T->right);
  temp=(struct Node*)malloc(sizeof(struct Node));
  temp->data=T->data;
  temp->right=NULL;
  temp->left=T->left;
  T->left=temp;
}


void Printinorder(struct Node *start)
{
if(start==NULL)
 return;
 Printinorder(start->left);
 printf("%d\n",start->data);
 Printinorder(start->right);
}

struct Node* newnode(int data) 
{   struct Node* node = (struct Node*)malloc(sizeof(struct Node));   
node->data = data;   
node->left = NULL;   
node->right = NULL;     
return(node); 
}   


int main() 
{ 
struct Node *head,*prev;
struct Node* temp;
    struct Node *root = newnode(10);  
 root->left        = newnode(8);  
 root->right       = newnode(2);  
 root->left->left  = newnode(3);  
 root->left->right = newnode(5);  
 root->right->left = newnode(6);
 Printinorder(root);
  DoubleTree(root);
 printf("\n");
 Printinorder(root);
}

