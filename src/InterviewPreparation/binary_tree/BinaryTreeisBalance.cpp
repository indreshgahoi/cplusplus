/*
 * BinaryTreeisBalance.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/binary_tree/BinaryTreeisBalance.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 7, 2013
 *      Author: Indresh Gahoi
 */


#include<iostream>
#include<cstdio>

using namespace std ;

struct TreeNode {
	int val ;
	struct TreeNode *left ;
	struct TreeNode *right ;
	TreeNode(int x):val(x),left(NULL),right(NULL)
	{

	}
};

int height(TreeNode *root){
	if(!root) return 0 ;

	int lh = height(root->left);
}

bool





