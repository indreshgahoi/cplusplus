/*
 * LCAofBST.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/binary_tree/LCAofBST.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 7, 2013
 *      Author: Indresh Gahoi
 */



#include<iostream>


struct node {
	int val ;
	struct node *left ;
	struct node *right ;
};


/* constraint :-
 *  The above functions assume that n1 and n2 both are in BST. If n1 and n2 are not present,
 *  then they may return incorrect result. Extend the above solutions to return NULL if n1 or n2 or both not
 *  present in BST.

   Please write comments if you find anything incorrect, or you want to share more information about the
   topic discussed above
 *
 */

struct node *LCARecur(struct node *root , int n1 , int n2){

  if(root==NULL) return NULL ;

  if(root->val < n1 && root->val < n2)
	  return LCARecur(root->left,n1,n2);
  if(root->val > n1 && root->val > n2)
	  return LCARecur(root->right,n1,n2);
  return root ;
}

struct node *LCAIterative(struct node *root , int n1 , int n2){

   while(root){
	 if(root->val > n1 && root->val > n2){
		 root = root->right ;
	 }
	 else if(root->val < n1 && root->val < n2 )
	 {
		 root = root->left ;
	 }
	 else
		 break ;
   }
  return root ;
}
