/*
 * PrePostFullBinary.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/PrePostFullBinary.cpp -o /usr/build/Main.o
 *
 *  Created on: Dec 31, 2013
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
Link :- http://www.geeksforgeeks.org/full-and-complete-binary-tree-from-given-preorder-and-postorder-traversals/

Given two arrays that represent preorder and postorder traversals of a full binary tree,
construct the binary tree.
A Full Binary Tree is a binary tree where every node has either 0 or 2 children

Following are examples of Full Trees.

        1
      /   \
    2       3
  /  \     /  \
 4    5   6    7


       1
     /   \
   2      3
        /   \
       4     5
           /   \
          6    7


          1
        /   \
      2       3
    /  \     /  \
   4    5   6    7
 /  \
8    9

It is not possible to construct a general Binary Tree from preorder and postorder traversals (See this).
 But if know that the Binary Tree is Full, we can construct the tree without ambiguity.
 Let us understand this with the help of following example.

Let us consider the two given arrays as
 pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7}
 post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
In pre[], the leftmost element is root of tree.
 Since the tree is full and array size is more than 1.
 The value next to 1 in pre[], must be left child of root.
 So we know 1 is root and 2 is left child.
 How to find the all nodes in left subtree?
 We know 2 is root of all nodes in left subtree.
 All nodes before 2 in post[] must be in left subtree.
 Now we know 1 is root, elements {8, 9, 4, 5, 2} are in left subtree,
  and the elements {6, 7, 3} are in right subtree.


                  1
                /   \
               /      \
     {8, 9, 4, 5, 2}     {6, 7, 3}

We recursively follow the above approach and get the following tree.

          1
        /   \
      2       3
    /  \     /  \
   4    5   6    7
  / \
 8   9


  
  
*/

typedef int KeyType ;

struct TreeNode
{
	KeyType key ;
	struct TreeNode *left ;
	struct TreeNode *right ;
	TreeNode(KeyType key_):key(key_),left(NULL),right(NULL){};
};


class Solution
{
	public :

	TreeNode* ConstructBinaryTreeUtil(KeyType pre[],int &preStart, KeyType post[],int low , int high, int n)
	{
		if(low > high || preStart>=n) return NULL;

		TreeNode *root = new TreeNode(pre[preStart]) ;
		preStart++ ;
       if(low==high) return root ;

		int postIndex ;
		for( postIndex = low ;preStart< n && postIndex < high ;++postIndex)
		{
			if(post[postIndex]==pre[preStart])
				break ;
		}
//		printf("\nRoot : %d",root->key);
//		printf("\nLeft : ") ;
//		for( int iter = low ; iter <n && iter <= postIndex ; ++iter)
//			printf("%d ",post[iter]) ;
//		printf("\nRight : ") ;
//		for( int iter = postIndex+1 ; iter<n && iter <high ; ++iter)
//			printf("%d ",post[iter]) ;

		root->left = ConstructBinaryTreeUtil(pre,preStart,post,low,postIndex-1,n);
		root->right = ConstructBinaryTreeUtil(pre,preStart,post,postIndex+1,high,n) ;
		return root ;
	}

	TreeNode* ConstructBT(KeyType pre[] ,KeyType post[],int n)
	{
	  int preStart = 0 ;
      return ConstructBinaryTreeUtil(pre,preStart,post,0,n-1,n);
	}
   
};

void levelOrder(TreeNode* root)
{
	if(!root) return ;
	queue<TreeNode*> Q ;
	int nodeInCurrentLevel ,nodeInNextLevel ;
	Q.push(root) ;
	nodeInCurrentLevel = 1 ;
	nodeInNextLevel = 0 ;
	while(!Q.empty())
	{
		TreeNode *currentNode = Q.front() ;
		Q.pop() ;
		printf("%d ",currentNode->key) ;
		nodeInCurrentLevel--;
		if(currentNode->left)
		{
			nodeInNextLevel++ ;
			Q.push(currentNode->left) ;
		}
		if(currentNode->right)
		{
			nodeInNextLevel++ ;
			Q.push(currentNode->right) ;
		}
		if(nodeInCurrentLevel==0)
		{
			nodeInCurrentLevel = nodeInNextLevel ;
			nodeInNextLevel = 0 ;
			printf("\n") ;
		}
	}
}


void postOrder(TreeNode* root)
{
	if(root)
	{
		postOrder(root->left) ;
		postOrder(root->right) ;
		printf(" %d",root->key);
	}
}

void preOrder(TreeNode* root)
{
	if(root)
	{
		printf(" %d",root->key) ;
		preOrder(root->left) ;
		preOrder(root->right) ;
	}
}

void driver()
{
  fstream fin("input.txt");	
  Solution solver ;
  int n , elem ;
  int *pre ;
  int *post ;
  fin >> n ;
  pre = new int[n] ;
  post = new int[n] ;
  int iter = 0 ;
  while(iter < n)
  {
	  fin >> elem ;
	  pre[iter] = elem ;
	  iter++;
  }
  iter = 0 ;
  while(iter < n)
  {
	  fin >> elem ;
 	  post[iter] = elem ;
 	  iter++;
  }
   TreeNode *root = solver.ConstructBT(pre,post,n) ;

   preOrder(root) ;
   printf("\n") ;
   postOrder(root) ;
   printf("\n") ;
   levelOrder(root) ;

}
/*
 input.txt 
 3
 1 2 3
 2 3 1

 9
 1 2 4 8 9 5 3 6 7
 8 9 4 5 2 6 7 3 1


*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
