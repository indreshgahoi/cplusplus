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
#include<cassert>
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

	/*
	 *  This Iterative Version is using two stack
	 *
	 */
	vector<int> postorderTraversal(TreeNode *root) {

		vector<int> res ;
		if(root==NULL)
			return res ;
		stack<TreeNode*> call;
		stack<int> R ;
		call.push(root);
        while(!call.empty())
        {
        	TreeNode *top = call.top();
        	call.pop();
        	R.push(top->val);
        	if(top->left)
        		call.push(top->left) ;
        	if(top->right)
        		call.push(top->right) ;
        }


		while(!R.empty())
		{
			res.push_back(R.top());
			R.pop();
		}
		return res ;
	}
};
typedef int ItemType ;






class Solution1 {
public:

	/*
	 *  This Iterative Version is using one Stack
	 *
	 */
	vector<int> postorderTraversal(TreeNode *root) {

			vector<int> traversalList ;
			stack<TreeNode*> parentStack ;

			do
			{
					while(root)
					{
						if(root->right)
							parentStack.push(root->right) ;
						parentStack.push(root) ;
						root = root->left ;
					}
                    assert(root==0) ;
					root = parentStack.top();
					assert(root!=0) ;
					parentStack.pop() ;
					if(root->right &&  !parentStack.empty() && parentStack.top()==root->right)
					{

						parentStack.pop();
						parentStack.push(root);
						root = root->right ;
					}
					else
					{
						printf(" %d ",root->val) ;
						traversalList.push_back(root->val) ;
						root = 0 ;
					}

			}while(!parentStack.empty()) ;

			return traversalList ;
	}
};

void postOrderReverse(TreeNode *root , vector<int> &R)
{
	if(root)
	{
		R.push_back(root->val) ;
		postOrderReverse(root->right,R);
		postOrderReverse(root->left,R);

	}
}


void postOrder(TreeNode *root )
{
	if(root)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout<<" "<<root->val ;
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
	Solution1 sl ;
	cout<<"\n "<<sl.postorderTraversal(root);
}


int main()
{
	test();
	cout<<std::endl;
	return 0 ;
}



