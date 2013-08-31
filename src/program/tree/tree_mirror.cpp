#include<iostream>
#include<cstdio>
using namespace std;


typedef struct node *NodePointer;
typedef struct node{
  struct node *left,*right;
  int data;
}node;

NodePointer makeTree(int data)
{
    NodePointer p;
    p=new node;
    p->data=data;
    p->left=p->right=NULL;
    return p;
}

bool isFoldableUtil(NodePointer l , NodePointer r)
  {
     if(l==NULL && r==NULL)
      return true;

     if(l==NULL || r==NULL)
      return false;

     return(isFoldableUtil(l->left,r->right)&& isFoldableUtil(l->right,r->left));
  }


bool isFoldable(NodePointer root)
{
  if(root==NULL)
    return true;

 return(isFoldableUtil(root->left,root->right));
}
void printTree(NodePointer root)
{
    if(root)
    {
        printTree(root->left);
        cout<<root->data<<"\n"<<endl;
        printTree(root->right);
    }
}

int main()
{
    bool b;
    NodePointer Tree;
    Tree=makeTree(10);
    Tree->left=makeTree(7);
    Tree->right=makeTree(13);
    Tree->left->right=makeTree(9);
    Tree->right->left=makeTree(15);
    printTree(Tree);
    b=isFoldable(Tree);
    cout<<b<<"\n"<<endl;
    return 0;
}


