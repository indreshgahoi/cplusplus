/*
 * InOrderSuccessor.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/binary_tree/InOrderSuccessor.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 7, 2013
 *      Author: Indresh Gahoi
 */


#include<iostream>
#include<cstdio>
#include<stack>


using namespace std ;



struct TreeNode {
	int val ;
	struct TreeNode *left ;
	struct TreeNode *right ;
	TreeNode(int x):val(x),left(NULL),right(NULL)
	{

	}
};

TreeNode* minimum(TreeNode *root) ;

TreeNode* inOrderSuccessor(TreeNode *root , TreeNode *n)
{
	if(n->right != NULL){
		return minimum(n->right);
	}
	TreeNode *succ = NULL ;
	while(root)
	{
		if(n->val < root->val)
		{
			succ = root ;
			root = root->left ;
		}
		else if(n->val > root->val)
		{
			root = root->right ;
		}
		else
			break ;
	}
	return succ ;
}



