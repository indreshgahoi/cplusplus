/*
 * ConverBinaryTreeToSumTree.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/binary_tree/ConverBinaryTreeToSumTree.cpp -o /usr/build/Main.o
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
/*
 * Link:- http://www.geeksforgeeks.org/convert-an-arbitrary-binary-tree-to-a-tree-that-holds-children-sum-property/
 *
 *
 * Question:-
 * 	Question: Given an arbitrary binary tree, convert it to a binary tree that holds
 * 	Children Sum Property. You can only increment data values in any node
 * 	(You cannot change structure of tree and cannot decrement value of any node).
 *
 *
 *
 *
 */

void increment(TreeNode *root , int val)
{

  if(root->left){
	  root->left->val+=val;
	  increment(root->left , val);
  }
  else if(root->right)
  {
        root->right->val+= val ;
        increment(root->right,val);
  }

}

void converToSumTree(TreeNode *root){

	// Base Case
   if(root==NULL || (root->left==NULL && root->right==NULL))
	   return ;
   int lValue = 0 , rValue = 0 ;

   converToSumTree(root->left);
   converToSumTree(root->right);
   if(root->left)
	   lValue = root->left->val ;
   if(root->right)
	   rValue = root->right->val ;

   int diff = (lValue+rValue)-root->val ;

   if(diff > 0 )
	   root->val += diff ;
   else if(diff < 0){
      increment(root,-diff);
   }

}


