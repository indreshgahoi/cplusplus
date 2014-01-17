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
	struct TreeNode *parent ;
	TreeNode(int x):val(x),left(NULL),right(NULL),parent(NULL)
	{

	}
};

TreeNode* minimum(TreeNode *root) ;

/*
 *
 *  Iterative Solution
 *
 */

class Solution1
{


public :

	TreeNode* inOrderSuccessor(TreeNode *root , TreeNode *n)
	{
		if(n->right != NULL)
		{
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

} ;
/*
 *
 * Tree Having Parent Pointer
 *
 */

class Solution2
{
public :
 TreeNode* inOrderSuccessor(TreeNode *root , TreeNode *node)
 {
	 TreeNode *succ = NULL ;
	 if(node->right != 0)
	 {
		 succ = minimum(node->right) ;
	 }
	 else
	 {
		 TreeNode *parent = node->parent ;
		 while(parent != 0 && node==parent->right)
		 {
			 node = parent ;
			 parent = parent->parent ;
		 }
		 succ = parent ;
	 }
	 return succ ;
 }
};
