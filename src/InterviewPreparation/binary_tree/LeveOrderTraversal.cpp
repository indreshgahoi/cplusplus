/*
 * LeveOrderTraversal.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/binary_tree/LeveOrderTraversal.cpp -o /usr/build/Main.o
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
 *  This Question Can Also Ask
 *  populate Bfs Successor
 *  Iterative Binary Height
 *
 *
 */
class Solution {
public:
	vector<vector<int> > levelOrder(TreeNode *root) {

	  queue<TreeNode* > Q ;
	  int nodeInNextLevel = 0 ;
	  int nodeInCurrentLevel = 0 ;
	  vector< vector<int> > result ;
	  int level  = 0 ;
	  if(root)
	  {
		  Q.push(root);
		  nodeInCurrentLevel = 1 ;
		  result.push_back(vector<int>());
	  }
	  while(!Q.empty())
	  {
		  TreeNode *t = Q.front();
		  Q.pop();
		  nodeInCurrentLevel-- ;
		  result[level].push_back(t->val);
		  if(t->left)
		  {
			  nodeInNextLevel++;
			  Q.push(t->left);
		  }
		  if(t->right)
		  {
			  nodeInNextLevel++ ;
			  Q.push(t->right);
		  }
		  if(nodeInCurrentLevel==0)
		  {
			  if(nodeInNextLevel>0){
				  result.push_back(vector<int>());
			  }
			  nodeInCurrentLevel = nodeInNextLevel ;
			  nodeInNextLevel = 0 ;
			  level++;
		  }
	  }
	  return result ;
	}
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
