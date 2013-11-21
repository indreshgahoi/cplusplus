/*
 * NodeAtSameLevel.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/binary_tree/NodeAtSameLevel.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 21, 2013
 *      Author: Indresh Gahoi
 */


#include<iostream>
#include<cstdio>
#include<stack>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std ;

template<class T>
ostream& operator<<(ostream &out,const vector<T>& V){
	out<<"[";
	for(typename vector<T>::const_iterator it=V.begin();it!=V.end();it++){
		out<<" "<<*it;

	}
	out<<"]"<<endl;
	return out;
}

struct TreeNode {
	int val ;
	struct TreeNode *left ;
	struct TreeNode *right ;
	TreeNode(int x):val(x),left(NULL),right(NULL)
	{

	}
};
/*
 *  Question :-
 *   In a binary tree, return true if all leaves are at same level and return false if all leaves are not at the
 *    same level.
 *
 *
 */
class Solution {
public:

};


void test()
{
	       /*          10
	        *       7       14
	        *     6   8   13   15
	        *       18
	        */

	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(7);
	root->right = new TreeNode(14);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(15);
	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(8);
	root->left->left->right = new TreeNode(18);
	Solution sl ;
	cout<<sl.levelOrder(root);
}


int main()
{
	test();
	cout<<std::endl;
	return 0 ;
}
