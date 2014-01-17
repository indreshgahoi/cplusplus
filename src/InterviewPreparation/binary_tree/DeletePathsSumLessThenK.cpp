/*
 * DeletePathsSumLessThenK.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/binarySearch/DeletePathsSumLessThenK.cpp -o /usr/build/Main.o
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

#define trv(it,c) for(typeof (c).begin() it = (c).begin() ; it != c.end() ; ++it)
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
	~TreeNode()
	{
		cout<<" deleted Node = "<<val<<" \n";

	}
};
/*
Link :-  http://www.geeksforgeeks.org/amazon-interview-set-32/
Question :-
  In a binary tree, a complete path is defined as a path from root to a leaf. The sum of all nodes on that path
  is defined as the sum of that path. Given a number K, we have to remove (prune the tree) nodes from the tree
  which lie on a path having sum less than K.

Note: A node can be part of multiple paths. So we have to delete it only in case when all paths from it have
sum less than K.
  
  

  http://www.geeksforgeeks.org/remove-all-nodes-which-lie-on-a-path-having-sum-less-than-k/

*/

class Solution
{
	 void RootToLeafPath(TreeNode* root ,vector<int> &path)
	 {
		 if(root)
		 {
			 if(root->left == 0 && root->right==0)
			 {
				 path.push_back(root->val) ;
                 int sum = 0 ;
                 cout<<"[ ";
				 trv(it,path)
				 {
                	 cout<<" "<<*it;
                	 sum+=*it;
				 }
				 cout<<" ] ==> "<<sum<<"\n";
				 path.pop_back();
				 return ;
			 }

			 path.push_back(root->val);
			 RootToLeafPath(root->left,path);
			 path.pop_back();

			 path.push_back(root->val);
			 RootToLeafPath(root->right,path);
			 path.pop_back();
		 }
	 }



 public :
	TreeNode* deletePathsHavingSumLessThenKUtil(TreeNode* root ,int k , int &pathSum)
	{
		if(root==0)
		{
			return 0 ;
		}

        int leftSum = pathSum + root->val;
        int rightSum = leftSum ;

		root->left = deletePathsHavingSumLessThenKUtil(root->left , k  ,leftSum);
		root->right = deletePathsHavingSumLessThenKUtil(root->right , k , rightSum) ;

		pathSum = max (leftSum,rightSum);
		if(pathSum < k)
		{
			delete root ;
			return NULL ;
		}

		return root ;

	}

   void RemovePathsHaveSumLessThenK(TreeNode* root , int K)
   {
	   vector<int> path;
	   RootToLeafPath(root,path);
	   int sum = 0;
	   root=deletePathsHavingSumLessThenKUtil(root,K,sum);
	   path.clear();
	   cout<<"Solution-----\n";
	   RootToLeafPath(root,path);
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
	//root->left->left->right = new TreeNode(18);
	Solution sl ;
	sl.RemovePathsHaveSumLessThenK(root,26);
}


void driver()
{
 test();
}
/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
