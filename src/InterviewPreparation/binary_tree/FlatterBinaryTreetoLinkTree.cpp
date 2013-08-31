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


void flatten(TreeNode *tree) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!tree) return;
    TreeNode *left=tree->left,*right=tree->right;

	tree->left=NULL;
	tree->right=left;

	TreeNode *rightmost=left;
	if(left){
	while(rightmost->right)rightmost=rightmost->right;


	}
    if(rightmost)
    rightmost->right=right;
    else
    tree->right=right;
	flatten(tree->right);
    }




