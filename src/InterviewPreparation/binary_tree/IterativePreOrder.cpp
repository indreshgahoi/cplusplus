/*
 * IterativePostOrderTraversal.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/binary_tree/IterativePostOrderTraversal.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 14, 2013
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<cstdio>
#include<stack>
#include<algorithm>
#include<vector>
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

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {

          stack<TreeNode*> S ;
          vector<int> res ;
          if(root)
          {
        	  S.push(root);
        	  res.push_back(root->val);
          }
          while(!S.empty())
          {
        	  TreeNode *t    = S.top();
        	  S.pop();
        	  res.push_back(t->val);
        	  if(t->right)
        		  S.push(t->right);
        	  if(t->left)
        		  S.push(t->left);
          }
          return res ;
    }
};



void preOrder(TreeNode *root )
{
	if(root)
	{
		cout<<" "<<root->val ;
		preOrder(root->left);
		preOrder(root->right);

	}
}

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
	vector<int> res ;
	postOrderReverse(root,res); reverse(res.begin(),res.end()) ; cout<<res<<"\n";
	postOrder(root);cout<<"\n";
	Solution sl ;
	cout<<sl.preorderTraversal(root);
}


int main()
{
	test();
	cout<<std::endl;
	return 0 ;
}



