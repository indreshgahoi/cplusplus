/*
 * PopulateInorderSuccessorOfAllNodes.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/binary_tree/PopulateInorderSuccessorOfAllNodes.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 7, 2013
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<cstdio>

using namespace std ;


struct TreeNode {
	int val ;
	TreeNode *left ;
	TreeNode *right ;
	TreeNode *next ;
};

/* Question :-
 *
 *  Given a Binary Tree where each node has following structure, write a function to populate next pointer
 *  for all nodes. The next pointer for every node should be set to point to inorder successor.
 *
 *
 * Solution :-
 *  Solution (Use Reverse Inorder Traversal)
   Traverse the given tree in reverse inorder traversal and keep track of previously visited node.
   When a node is being visited, assign previously visited node as next
 *
 *
 */

 void populateInorderSuccessorInnextUtil(TreeNode *root , TreeNode **preRef)
 {
	 if(root)
	 {
		 populateInorderSuccessorInnextUtil(root->right,preRef);
		 root->next = *preRef ;
		 preRef = &root ;
		 populateInorderSuccessorInnextUtil(root->right,preRef);
	 }
 }

 void populateInorderSuccessorInnext(TreeNode *root)
 {
	 TreeNode *pre = NULL ;
	 populateInorderSuccessorInnextUtil(root,&pre);

 }



