/*
 * FlatterBinaryTreetoLinkTree.cpp
 *
 *  Created on: Mar 10, 2013
 *      Author: indresh
 */

#include<iostream>

class TreeNode{
	int val;
	TreeNode *left,*right;
};


/* Question :-
 *  Given a binary tree. Modify it in such a way that after modification you can have
 *   a preorder traversal of it using only right pointers. During modification you
 *   can use right as well as left pointers. Write complete code and dry run it for
 *   some test cases.
 *
 *	If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

 *
 */

void flatten(TreeNode *tree) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if(!tree) return;
	TreeNode *left=tree->left,*right=tree->right;

	tree->left=NULL;
	tree->right=left;

	TreeNode *rightmost=left;
	if(left)
	{
		while(rightmost->right)rightmost=rightmost->right;
	}
	if(rightmost)
		rightmost->right=right;
	else
		tree->right=right;
	flatten(tree->right);
}




