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



void inOrderTraversalWithOutRecurrsion(TreeNode *root){

  stack<TreeNode*> st ;
  bool done = false ;
  TreeNode *current = root ;
  while(!done)
  {
	 if(current != NULL){
		 st.push(current);
		 current = current->left ;
	 }
	 else
	 {
           if(!st.empty()){
        	   printf(" %d ",st.top()->val) ;
        	   st.pop();
        	   current = current->right;
           }
           else
           {
        	   done = true ;
           }
	 }

  }

}



