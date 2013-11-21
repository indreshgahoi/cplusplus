/*
 * ConverTreeToSumTree.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/binary_tree/ConverTreeToSumTree.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 7, 2013
 *      Author: Indresh Gahoi
 */

/* Question :-
 * 	Given a Binary Tree where each node has positive and negative values. Convert
 * 	this to a tree where each node contains the sum of the left and right sub trees
 * 	in the original tree. The values of leaf nodes are changed to 0.

For example, the following tree

                  10
               /      \
	     -2        6
           /   \      /  \
	 8     -4    7    5

should be changed to

                 20(4-2+12+6)
               /      \
	   4(8-4)      12(7+5)
           /   \      /  \
	 0      0    0    0

Solution:
Do a traversal of the given tree. In the traversal, store the old value of the
current node, recursively call for left and right subtrees and change the value of
current node as sum of the values returned by the recursive calls. Finally return the sum of new value and value (which is sum of values in the subtree rooted with this node).
 *
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



class Solution{

	int toSumTree(TreeNode *root){

		if(root == NULL)
			return 0 ;
		int old_value = root->val ;

		root->val = toSumTree(root->left) + toSumTree(root->right);

		return old_value + root->val ;

	}

};






