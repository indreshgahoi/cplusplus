/*
 * ChexkBinaryTreeComplete.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/ChexkBinaryTreeComplete.cpp -o /usr/build/Main.o
 *
 *  Created on: Jan 4, 2014
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<climits>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>

using namespace std;

#define FOR(_i,a,b) for(int _i=a;_i<b;_i++)
#define REP(_i,n)    for(int _i=0;_i<n;_i++)
#define debug(x) cout<<#x" "<<x;
#define nl cout<<"\n";
#define tab cout<<"		";
void driver();
void printArray(int A[],size_t size){
	printf("values= [");
   for(int i=0;i<size-1;i++)
	   printf("%d ,",A[i]);
   printf("%d]\n",A[size-1]);
}
template<class T>
ostream& operator<<(ostream &out,const vector<T>& V){
	out<<"[";
	for(typename vector<T>::const_iterator it=V.begin();it!=V.end();it++){
	 out<<" "<<*it;
	}
	out<<"]"<<endl;
	return out;
}
void getInput(vector<int> &v)
{
#define ARRAYSIZE(A) sizeof(A)/sizeof(A[0])
	int arr[] = {-1,-1,-1,1,1};
	int size = ARRAYSIZE(arr) ;
	for(int iter = 0 ; iter < size ; ++iter)
	{
		v.push_back(arr[iter]);
	}
}
/*
Link :-  
Question :-
  Check Wheather Binary Tree is Complete or not .
  
  Given a Binary Tree, write a function to check whether the given Binary Tree is
  Complete Binary Tree or not.

A complete binary tree is a binary tree in which every level,
except possibly the last, is completely filled, and all nodes are
 as far left as possible. See following examples.

The following trees are examples of Complete Binary Trees
    1
  /   \
 2     3

       1
    /    \
   2       3
  /
 4

       1
    /    \
   2      3
  /  \    /
 4    5  6




*/


typedef int KeyType ;

struct TreeNode
{
	KeyType key ;
	TreeNode *left , *right ;
	TreeNode(KeyType key_):key(key_),left(0),right(0){};
};



class Solution
{
	public :

	bool isComplete(TreeNode *root)
	{
		if(!root) return true ;
		queue<TreeNode*> Q ;
		bool flag = false ;
		Q.push(root) ;
		while(!Q.empty())
		{
		   TreeNode *currNode = Q.front() ;
		   Q.pop();
		   if(currNode->left)
		   {
			   if(flag) return false ;
			   Q.push(currNode->left) ;
		   }
		   else
			   flag = true ;

		   if(currNode->right)
		   {
			   if(flag) return false ;
			   Q.push(currNode->right) ;
		   }
		   else
		      flag = true ;

		}
		return true ;
	}
   
};
void driver()
{
  fstream fin("input.txt");	
  TreeNode *root = new TreeNode(10);
    	root->left = new TreeNode(7);
    	root->right = new TreeNode(14);
    	root->right->left = new TreeNode(13);
    	root->right->right = new TreeNode(15);
    	root->left->left = new TreeNode(6);
    	root->left->right = new TreeNode(8);
    	root->left->left->left = new TreeNode(18);
      Solution solver ;
      (solver.isComplete(root)) ? cout<<" Complete" : cout<<"Not Complete" ;
}
/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
