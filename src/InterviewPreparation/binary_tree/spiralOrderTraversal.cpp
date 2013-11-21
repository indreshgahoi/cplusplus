/*
 * spiralOrderTraversal.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/binary_tree/spiralOrderTraversal.cpp -o /usr/build/Main.o
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


void spiralTraversal(TreeNode *root){

	stack<TreeNode*> s1;
	stack<TreeNode*> s2;

	s1.push(root);
	while(!s1.empty() || !s2.empty()){

		while(!s1.empty()){
			TreeNode *current = s1.top();
			s1.pop();
			printf(" %d ",current->val);
			if(current->right)
				s2.push(current->right);
			if(current->left)
				s2.push(current->left);
		}
        while(!s2.empty()){

        	TreeNode *current = s2.top();
        	s2.pop();
        	if(current->left)
        		s1.push(current->left);
        	if(current->right)
        		s1.push(current->right);
        }

	}


}

