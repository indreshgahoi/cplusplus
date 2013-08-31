//this is a question specially for printing all possible paths from the root to the leaves.:)
//Binary Search Tree.
#include "stdio.h"
struct Node {    int data;    struct Node* left;    struct Node* right; };
void RootLeavesP(struct Node *r,int Paths[],int Plen)
{int i;
if(!r)
return;
if(r->left==NULL && r->right==NULL)
{
for(i=0;i<Plen;i++)
{
printf("%d  ",Paths[i]);
}
printf("%d\n",r->data);
return;
}
Paths[Plen]=r->data;
Plen++;
RootLeavesP(r->left,Paths,Plen);
RootLeavesP(r->right,Paths,Plen);
}

void PrintPaths(struct Node *r)
{
int Paths[100000]={0};
if(!r)
return;
else
RootLeavesP(r,Paths,0);
}
struct Node* newnode(int data) 
{   struct Node* node = (struct Node*)malloc(sizeof(struct Node));   
node->data = data;   
node->left = NULL;   
node->right = NULL;     
return(node); }   
int main() 
{          
 struct Node *root = newnode(10);  
 root->left        = newnode(8);  
 root->right       = newnode(2);  
 root->left->left  = newnode(3);  
 root->left->right = newnode(5);  
 root->right->left = newnode(2);    
 PrintPaths(root);    
 return 0; } 
