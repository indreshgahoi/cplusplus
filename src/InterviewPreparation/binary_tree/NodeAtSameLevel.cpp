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
#define debug(x) cout<<#x<<"="<<x<<" ";
#define nl cout<<"\n";
#define tab cout<<"	 ";
class Solution {
public:

	bool isLeafAtSameLevelUtil(TreeNode* root ,int &preLeafLevel ,bool &isSameLevel , int l)
	{
		if(root==0)
		{

			return true ;
		}
		if(root->left==0 && root->right==0)
		{
			if(preLeafLevel==-1)
			{
				preLeafLevel = l ;
				isSameLevel = true ;
				return true ;
			}


			isSameLevel = isSameLevel && (preLeafLevel==l);

			return isSameLevel ;
		}
		if(isSameLevel)
		{
			return isLeafAtSameLevelUtil(root->left,preLeafLevel,isSameLevel,l+1)&&
					isLeafAtSameLevelUtil(root->right,preLeafLevel,isSameLevel,l+1);
		}
		return false ;
	}

	bool isLeafAtSameLevel(TreeNode* root)
	{
		bool x = true ;
		int pre = -1 ;
		return isLeafAtSameLevelUtil(root,pre,x,0);
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
	//root->left->left = new TreeNode(6);
	//root->left->right = new TreeNode(8);
	//root->left->left->right = new TreeNode(18);
	Solution sl ;
	if(sl.isLeafAtSameLevel(root))
	{
		cout<<"Ya at Same Level" ;
	}
	else
	{
		cout <<"Oh No they Are not At SameLevel" ;
	}
}


int main()
{
	test();
	cout<<std::endl;
	return 0 ;
}
