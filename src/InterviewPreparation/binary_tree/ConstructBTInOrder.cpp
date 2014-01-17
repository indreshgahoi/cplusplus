/*
 * ConstructBTInOrder.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/ConstructBTInOrder.cpp -o /usr/build/Main.o
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
Link :-  http://www.geeksforgeeks.org/construct-binary-tree-from-inorder-traversal/
Question :-


Construct Special Binary Tree from given Inorder traversal

Given Inorder Traversal of a Special Binary Tree in which key of every node is greater than keys in left and right children, construct the Binary Tree and return root.

Examples:

Input: inorder[] = {5, 10, 40, 30, 28}
Output: root of following tree
         40
       /   \
      10     30
     /         \
    5          28

The idea used in Construction of Tree from given Inorder and Preorder traversals can be used here.
Let the given array is {1, 5, 10, 40, 30, 15, 28, 20}. The maximum element in given array must be root.
The elements on left side of the maximum element are in left subtree and elements on right side are in right
subtree.

         40
      /       \
   {1,5,10}   {30,15,28,20}

We recursively follow above step for left and right subtrees, and finally get the following tree.

          40
        /   \
       10     30
      /         \
     5          28
    /          /  \
   1         15    20


Construct Special Binary Tree from given Inorder traversal

Given Inorder Traversal of a Special Binary Tree in which key of every node is greater
than keys in left and right children, construct the Binary Tree and return root
  
  
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
   


	 int find_root(KeyType *in , int start, int end)
	 {
		 int iter = start ;
		 int maxIndex = start ;

		 for( iter = start ; iter < end ; ++iter)
		 {
			 if(in[maxIndex] < in[iter])
			 {
				 maxIndex = iter ;
			 }
		 }
		 return maxIndex ;
	 }



	TreeNode* ConstructBinaryTree(KeyType *in , int start , int end)
	{
		if(start>end)
			return 0 ;
		int parentIndex = find_root(in,start,end) ;
		TreeNode *parentNode = new TreeNode(in[parentIndex]) ;
		parentNode->left = ConstructBinaryTree(in,start,parentIndex-1) ;
		parentNode->right = ConstructBinaryTree(in,parentIndex+1,end) ;
		return parentNode ;
	}

};

void printInorder(TreeNode *root)
{
	if(root)
	{
		printInorder(root->left) ;
		printf(" %d ",root->key) ;
		printInorder(root->right) ;
	}
}

void driver()
{
  fstream fin("input.txt");	
  int A[1000] ;
  int len = 0 ;
  int elem ;
  while(fin>>elem)
  {
	  A[len++]= elem ;
  }
  Solution solver ;
  TreeNode *root = solver.ConstructBinaryTree(A,0,len-1);
  printInorder(root) ;
}
/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
