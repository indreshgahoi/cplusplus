/*
 * FindTheLargestSubTreeInGivenBinaryTree.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/binary_tree/FindTheLargestSubTreeInGivenBinaryTree.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 7, 2013
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<cstdio>
#include<limits>
#include<limits.h>

using namespace std ;


struct TreeNode {
	int val ;
	TreeNode *left ;
	TreeNode *right;
};


bool isValidBstUtil(TreeNode *root , int min , int max)
{
	if(root==NULL)
	{
		return true ;
	}

	/* if root val does not lie between min and max return false
	 *
	 */
	if(root->val < min || root->val > max)
		return false ;

	return isValidBstUtil(root->left,min,root->val) &&
			isValidBstUtil(root->right,root->val+1,max) ;
}

bool isValidBst(TreeNode *root)
{
	return isValidBstUtil(root,INT_MIN , INT_MAX);
}

int size(TreeNode *root){
	if(root==NULL) return 0 ;

	return size(root->left) + 1 +size(root->right) ;
}

int Max(int a , int b) { return a > b ? a : b ; }

/*  Time complexity of this method is o(n^2)
 *
 */

int LargestBst(TreeNode *root)
{
	if(root==NULL)
		return 0 ;
	if(isValidBST(root))
		return size(root);

	return Max(LargestBst(root->left),LargestBst(root->right));
}

/*
 *  We can solve this Problem in O(n) using bottam up manner
 *
 */
/* Theory :-  In method 1, we traverse the tree in top down manner and do BST test for every node.
 * If we traverse the tree in bottom up manner, then we can pass information about subtrees to the parent.
 * The passed information can be used by the parent to do BST test (for parent node) only in constant time
 *  (or O(1) time). A left subtree need to tell the parent whether it is BST or not and also need to pass
 *   maximum value in it. So that we can compare the maximum value with the parent’s data to check the BST
 *    property. Similarly, the right subtree need to pass the minimum value up the tree. The subtrees need to pass the following information up the tree for the finding the largest BST.

1) Whether the subtree itself is BST or not (In the following code, is_bst_ref is used for this purpose)
2) If the subtree is left subtree of its parent, then maximum value in it. And if it is right subtree then
	minimum value in it.
3) Size of this subtree if this subtree is BST (In the following code, return value of largestBSTtil() is used
	for this purpose)

max_ref is used for passing the maximum value up the tree and min_ptr is used for passing minimum value up the
 tree
 *
 *
 */

/*  min_value  minimum value in subtree
 *  max_value maximum value in subtree
 *  is_bst this subtree is bst or not
 *  size of the bst
 *  and method return the size of the bst
 */
/*
 *  think as single node
 *
 *   left subtree return max_value
 *   right subtree should return min_value value
 *
 *    if root->val > min_value && root->value  < max_value
 *    root belong to bst
 */

int Min (int x , int y) { return x < y ? x : y ; }

int LargestBstUtilOp(TreeNode *root ,int &min_valRef ,int &max_valRef ,bool &is_bstRef ,int &size)
{
	// base case
	if(root==NULL)
	{
		is_bstRef = true;
		return 0 ;
	}

	bool isLeftBst = false ;
	bool isRightBst = false ;
	int ls,rs;
	int min;
	max_valRef = INT_MIN ;

	ls = LargestBstUtilOp(root->left,min_valRef,max_valRef,is_bstRef,size);
	if(is_bstRef && root->val > max_valRef)
		isLeftBst = true ;

	min = min_valRef ;
	min_valRef = INT_MAX ;
	ls= LargestBstUtilOp(root->right,min_valRef,max_valRef,is_bstRef,size);

	if(is_bstRef && root->val < min_valRef)
		isRightBst = true ;

	// update min max value for parent in recurrsive call
	min_valRef = Min(min_valRef,Min(min,root->val));
	max_valRef = Max(max_valRef,root->val);

	if(isLeftBst && isRightBst)
	{
		size = Max(size,ls+rs+1);
		return ls+rs+1 ;
	}
	else
	{   is_bstRef = false ;
	return 0 ;
	}


}






int LargestBstOp(TreeNode *root)
{
	int min = INT_MAX ;
	int max = INT_MIN ;

	int size = 0 ;
	bool is_bst = false ;

	LargestBstUtilOp(root,min,max,is_bst,size);
	return size ;
}


class Solution
{
public :

	TreeNode* FindLargestBstUtil(TreeNode *tree , int &min , int &max , int &maxNodes , TreeNode *&largestBst)
	{
		if(!tree) return 0 ;

		bool isBst = true ;

		int leftSize = FindLargestBstUtil(tree->left,min,max,maxNodes,largestBst) ;

		if( leftSize==-1 || (leftSize!=0 && tree->val <= max))
		{
			isBst = false ;
		}
		int currMin = (leftSize==0)? tree->val : min ;


		int rightSize = FindLargestBstUtil(tree->right,min,max,maxNodes,largestBst) ;

		if(rightSize==-1 || (rightSize!=0 && tree->val >= min))
			isBst = false ;
		int currMax = (rightSize==0) ? tree->val : max;

		if(isBst)
		{
			min = currMin ;
			max = currMax ;
			int totalSize = leftSize + rightSize + 1 ;
			if(totalSize > maxNodes)
			{
				maxNodes = totalSize ;
				largestBst = root ;
			}
			return totalSize ;
		}
		else
		{
			return -1 ;
		}
	}



	TreeNode* FindLargestBSTSubTree(TreeNode *root)
	{
            int min , max ;
            TreeNode *largestBst = 0 ;
            int MaxNodes = INT_MIN ;

            FindLargestBstUtil(root,min,max,MaxNodes,largestBst) ;
            return largestBst ;
	}
};



