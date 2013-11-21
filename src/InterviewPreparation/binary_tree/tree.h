/*
 * tree.h
 * run command
 * g++ /Algorithm/src/InterviewPreparation/binary_tree/tree.h -o /usr/build/Main.o
 *
 *  Created on: Nov 7, 2013
 *      Author: Indresh Gahoi
 */

#ifndef TREE_H_
#define TREE_H_
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




#endif /* TREE_H_ */
