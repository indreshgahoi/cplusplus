/*
 * PopulatingNextRightPointerToEachNode.cpp
 *
 *  Created on: Jan 20, 2013
 *      Author: indresh
 */

/*
 *  Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
 */
#include<iostream>
using namespace std;
struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
 };

//work Only if it's perfect Binary Tree
//Every node must have two children or none
void connect1(TreeLinkNode *root) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
   if(!root)
		return;

	if(root->left && root->right){

	root->left->next=root->right;
	if(root->next)
		root->right->next=root->next->left;
	else
		root->right->next=NULL;

}
	connect(root->left);
	connect(root->right);

  }
// Solution when it's any Binary Tree
void connect(TreeLinkNode *root) {
       // Start typing your C/C++ solution below
       // DO NOT write int main() function
	if(!root)
		return;
	if(root->left){
		if(root->right)
			root->left->next=root->right;
		else{
		TreeLinkNode	*current=root->next;
		 while(current){
			 if(current->left){
				 root->left->next=current->left;
				 break;
			 }
			 if(current->right){
			 				 root->left->next=current->right;
			 				 break;
			 			 }
			 current=current->next;
		 }
		}

	}
	if(root->right){
		TreeLinkNode	*current=root->next;
				 while(current){
					 if(current->left){
						 root->right->next=current->left;
						 break;
					 }
					 if(current->right){
					 				 root->right->next=current->right;
					 				 break;
					 			 }
					 current=current->next;
				 }
	}

	connect(root->left);
	connect(root->right);
}




