/*
 * PopulatingNextRightPointerToEachNode.cpp
 *
 *  Created on: Jan 20, 2013
 *      Author: indresh
 */

/*
 *
 *  Question :-
 *   Connect the node at the same level
 *
 *
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


/*
 *  Perfect Binary Tree
 *
 *  Are leafs node are at the same level ;
 *  ans every parent has two children ;
 *
 * Do ii pre-order fashion
 */

class Solution1{


public :
void connect1(TreeLinkNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if(!root)
		return;


	if(root->left && root->right) // node is non-leaf
	{
		root->left->next=root->right;
		if(root->next)
			root->right->next=root->next->left;
		else
			root->right->next=NULL;
	}
	connect1(root->left);
	connect1(root->right);

 }
};

// Solution when it's any Binary Tree

class Solution2{

public :
TreeLinkNode* getNext(TreeLinkNode* root){
	TreeLinkNode	*current=root->next;
	while(current)
	{
		if(current->left)
		{
			return current->left;
		}
		if(current->right)
		{
			return current->right;
		}
		current=current->next;
	}
	return NULL ;
}

void connect(TreeLinkNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if(!root)
		return;
	if(root->next !=NULL)
	{
    	  connect(root->next) ;
	}

	if(root->left)
	{
		if(root->right){
			root->left->next=root->right;
			root->right->next = getNext(root);
		}
		else
		{
			root->left->next = getNext(root);
		}
		connect(root->left);
	}
	else if(root->right)
	{
		root->right->next=getNext(root);
		connect(root->right);
	}
	else
	{
	 connect(getNext(root));
	}
}


} ;


/*
 * constant space solution
 *  Only for complete binary tree
 */

class Solution {
	void connect(TreeLinkNode *root) {

		TreeLinkNode *leftWall = root;
		while (leftWall != 0) {

			TreeLinkNode *across = leftWall;
			while (across != 0) {
				if (across->left != 0) {
					across->left->next = across->right;
				}

				if (across->right != 0 && across->next != 0) {
					across->right->next = across->next->left;
				}

				across = across->next;
			}
			leftWall = leftWall->left;
		}
	}
};




class Solution3 {
	// that code work for all binary tree
	void connect(TreeLinkNode *root)
	{
		TreeLinkNode *current = root ;
		while(current){
			TreeLinkNode *pre = NULL ;
			TreeLinkNode *next = NULL ;
			while(current){
				if(!next) next = current->left ? current->left : current->right ;

				if(current->left)
				{
					if(pre) pre->next = current->left ;
					pre = current->left ;
				}
				if(current->right)
				{
					if(pre) pre->next = current->right ;
					pre = current->right ;
				}
				current = current->next ;
			}
			current = next ;
		}
	}
};



