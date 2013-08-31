#include<stdio.h>

struct node{
        int item;
        struct node *left;
        struct node	*right;
    };
	

int main()
{
  
  
  
   pushA(root); 
  while(!(topA==0 && topB==0))
  {
   tempA=0
   while(tpoA!=0){
    t_node=popA();
    tempA= tempA+t_node->item;
    pushB(t_node->left);
    pushB(t_node->right);
   }
   list_add(tempA);
     tempB=0   
    while(tpoB!=0){
    t_node=popB();
    tempB= tempB+t_node->item;
    pushA(t_node->left);
    pushA(t_node->right);
   }
   list_add(tempB);
}