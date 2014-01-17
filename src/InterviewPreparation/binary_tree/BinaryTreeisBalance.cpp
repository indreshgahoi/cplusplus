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




bool isBalancedhelp(TreeNode *root,int &h) {

	if(!root)
	{
	  h=0;
	  return true;
	}
    int l=0,r=0;

    bool lb=isBalancedhelp(root->left,l);
	bool rb=isBalancedhelp(root->right,r);

	h=max(l,r)+1;

	if(abs(l-r)<=1)
	{
		return lb&&rb;
	}
	else
		return false ;
 }
 bool isBalanced(TreeNode *root) {
  int h=0;
   return isBalancedhelp(root,h);

 }




