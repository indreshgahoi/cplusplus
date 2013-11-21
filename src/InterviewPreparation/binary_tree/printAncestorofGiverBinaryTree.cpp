/*
 * printAncestorofGiverBinaryTree.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/binary_tree/printAncestorofGiverBinaryTree.cpp -o /usr/build/Main.o
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



bool printAncestor(TreeNode *node , int key)
{
	if(root==NULL)
		return false ;
	if(node->val == key)
		return true ;

	if(printAncestor(node->left,key) || printAncestor(node->right,key))
	{
		printf(" %d ",node->val);
		return true ;

	}
	return false ;
}

