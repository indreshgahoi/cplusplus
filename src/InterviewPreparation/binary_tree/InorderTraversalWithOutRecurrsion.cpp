/*
 * InorderTraversalWithOutRecurrsion.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/binary_tree/InorderTraversalWithOutRecurrsion.cpp -o /usr/build/Main.o
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



class Solution
{
public :

	void inOrderTraversalWithOutRecurrsion(TreeNode *root)
	{
		stack<TreeNode*> st ;
		bool done = false ;
		TreeNode *current = root ;
		while(!done)
		{
			if(current != NULL)
			{
				st.push(current);
				current = current->left ;
			}
			else
			{
				if(!st.empty()){
					current = st.top() ;
					st.pop();
					printf(" %d",current->val) ;
					current = current->right;
				}
				else
				{
					done = true ;
				}
			}
		}
	}

	void inOrderTraversal(TreeNode* root)
	{
		if(root)
		{
			inOrderTraversal(root->left);
			printf(" %d",root->val) ;
			inOrderTraversal(root->right);
		}
	}
};



void test()
{
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(7);
	root->right = new TreeNode(14);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(15);
	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(8);
	root->left->left->right = new TreeNode(18);
	Solution sl ;
	sl.inOrderTraversalWithOutRecurrsion(root);
	cout <<" \n";
	sl.inOrderTraversal(root);
}
int main()
{
	test();
	cout<<"\n\n";
	return 0 ;
}


