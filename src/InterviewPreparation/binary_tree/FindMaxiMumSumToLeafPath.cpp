/*
 * FindMaxiMumSumToLeafPath.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/binary_tree/FindMaxiMumSumToLeafPath.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 8, 2013
 *      Author: Indresh Gahoi
 */

/* Question :-
 *
Find the maximum sum leaf to root path in a Binary Tree
April 6, 2012

Given a Binary Tree, find the maximum sum path from a leaf to root. For example, in the following tree,
 there are three leaf to root paths 8->-2->10, -4->-2->10 and 7->10. The sums of these three paths are
 16, 4 and 17 respectively. The maximum of them is 17 and the path for maximum is 7->10.

                  10
               /      \
	     -2        7
           /   \
	 8     -4

Solution
1) First find the leaf node that is on the maximum sum path. In the following code getTargetLeaf() does this by
assigning the result to *target_leaf_ref.
2) Once we have the target leaf node, we can print the maximum sum path by traversing the tree.
In the following code, printPath() does this.

The main function is maxSumPath() that uses above two functions to get the complete solution.
 *
 *
 *
 *
 */

#include<iostream>
#include<cstdio>
#include<limits.h>

using namespace std ;

struct TreeNode {
	int val ;
	struct TreeNode *left ;
	struct TreeNode *right ;
	TreeNode(int x):val(x),left(NULL),right(NULL)
	{

	}
};



bool printRootToLeafPathInBinaryTree(TreeNode *root , TreeNode *target)
{
	if(root==NULL)
		return false ;

	if(root==target || printRootToLeafPathInBinaryTree(root->left,target)
			||printRootToLeafPathInBinaryTree(root->right,target))
	{
		printf(" %d ",root->val);
		return true ;
	}
	return false ;
}



void maxSumPathUtil(TreeNode* root ,int currSum, int &maxSum ,TreeNode* &targetLeaf)
{
   if(root==NULL)
	   return ;
   currSum = currSum + root->val ;

   if(root->left==NULL && root->right==NULL)
   {
	   if(maxSum < currSum)
	   {
		   targetLeaf = root ;
		   maxSum = currSum;
	   }

   }

   maxSumPathUtil(root->left,currSum,maxSum,targetLeaf);
   maxSumPathUtil(root->right,currSum,maxSum,targetLeaf);

}





int maxSumPath(TreeNode *root)
{
	if(root==NULL) return 0 ;

	TreeNode *targetLeaf ;

	int maxSum = INT_MIN ;

	return maxSum ;
}



























