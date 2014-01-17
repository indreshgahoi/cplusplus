/*
 * BtSubBTodAnother.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/BtSubBTodAnother.cpp -o /usr/build/Main.o
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
Link :-  http://www.geeksforgeeks.org/check-if-a-binary-tree-is-subtree-of-another-binary-tree/
Question :-
 Given two binary trees, check if the first tree is subtree of the second one.
 A subtree of a tree T is a tree S consisting of a node in T and
 all of its descendants in T. The subtree corresponding to the root node is the entire tree;
 the subtree corresponding to any other node is called a proper subtree.

For example, in the following case, tree S is a subtree of tree T.

        Tree S
          10
        /    \
      4       6
       \
        30


        Tree T
              26
            /   \
          10     3
        /    \     \
      4       6      3
       \
        30

Solution: Traverse the tree T in preorder fashion. For every visited node in the traversal, see if the subtree rooted with this node is identical to S
  
*/


typedef int KeyType;

struct TreeNode
{
	KeyType key ;
	struct TreeNode *left , *right ;
	TreeNode(KeyType key_):key(key_),left(NULL),right(NULL){};
};

bool areIdentical(TreeNode *t1 , TreeNode *t2)
{
		if(t1==NULL && t2==NULL)
			return true ;
		if(t1==0 || t2==0) return false ;

		return t1->key == t2->key && areIdentical(t1->left,t2->left) && areIdentical(t1->right,t2->right);
}

class BinaryTree
{
	const TreeNode getRoot()
	{
		return root ;
	}


	bool hasSubTree(BinaryTree bTree)
	{
		TreeNode binaryTree = bTree.getRoot() ;
      return hasSubTreeUtil(&root,&binaryTree) ;
	}
private :
	bool hasSubTreeUtil(TreeNode *t1, TreeNode *st)
	{
		if(st==0) return true ;
		if(t1==0) return false ;

		if(areIdentical(t1,st))
		return true ;

		return areIdentical(t1->left,st) || areIdentical(t1->right,st);
	}
	TreeNode root ;
};


class Solution
{
	public :




   
};
void driver()
{
  fstream fin("input.txt");	
  Solution solver ;
}
/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
