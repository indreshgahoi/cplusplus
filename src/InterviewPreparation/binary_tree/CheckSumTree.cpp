/*
 * CheckSumTree.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/CheckSumTree.cpp -o /usr/build/Main.o
 *
 *  Created on: Jan 5, 2014
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
Link :-  Check if a given Binary Tree is SumTree
Question :-
  Write a function that returns true if the given Binary Tree is SumTree else false.
 A SumTree is a Binary Tree where the value of a node is equal to sum of the nodes
 present in its left subtree and right subtree. An empty tree is SumTree and sum of
 an empty tree can be considered as 0. A leaf node is also considered as SumTree
  
  Following is an example of SumTree.

          26
        /   \
       10     3
     /    \     \
    4      6      3

*/

typedef int KeyType ;

struct TreeNode
{
	KeyType key ;
    TreeNode *left , *right ;
    TreeNode(KeyType key_):key(key_),left(0),right(0){} ;
};

class Solution1
{
	public :

	int sum(TreeNode *root)
	{
		if(!root) return 0 ;

		return sum(root->left) + root->key + sum(root->right) ;
	}

	bool isSumTree(TreeNode *tree)
	{
		if(!root) return 0 ;

		int ls = sum(tree->left) ;
		int rs = sum(tree->right) ;

		return (tree->key==(ls==rs) && isSumTree(tree->left) && isSumTree(tree->right)) ;
	}
   
};





class Solution2
{
	public :


	bool isSumTree(TreeNode *root)
	{
		if(!root) return 1 ;
        if(!root->left && !root->right) return 1 ;

		int ls = 0 , rs = 0  ;
		if(root->left)
		{
			// root->left is leaf
			if(!root->left->left && !root->left->right)
			{
				ls = root->left->key ;
			}
			else
			{
				ls = 2 * root->left->key ;
			}
		}
		if(root->right)
		{
			if(!root->right->left && !root->right->right)
			{
				rs = root->right->key ;
			}
			else
			{
				rs = 2 * root->right->key ;
			}
		}
       return (ls+rs)== root->key && isSumTree(root->left) && isSumTree(root->right) ;
	}

};


void driver()
{
  fstream fin("input.txt");	
  Solution1 solver ;
}
/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
