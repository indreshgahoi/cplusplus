/*
 * BTtoBST.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/BTtoBST.cpp -o /usr/build/Main.o
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
Link :-  
Question :-
  
Binary Tree to Binary Search Tree Conversion

Given a Binary Tree, convert it to a Binary Search Tree.
The conversion must be done in such a way that keeps the original structure of Binary
Tree.


Example 1
Input:
          10
         /  \
        2    7
       / \
      8   4
Output:
          8
         /  \
        4    10
       / \
      2   7


Example 2
Input:
          10
         /  \
        30   15
       /      \
      20       5
Output:
          15
         /  \
       10    20
       /      \
      5        30

  
*/

typedef int KeyType ;

struct TreeNode
{
	KeyType key ;
	struct TreeNode *left,*right ;
	TreeNode(KeyType key_):key(key_),left(NULL),right(NULL){}
};



struct KeyComparator
{
	int  operator ()(const KeyType &key1 , const KeyType &key2)
	{
		return key1 < key2 ;
	}
};

class Solution
{
	public :

   void inOrderTraversal(TreeNode *root)
   {
	   if(root)
	   {
		   inOrderTraversal(root->left) ;
		   cout<<" "<<root->key ;
		   inOrderTraversal(root->right) ;
	   }
   }
	void inOrderTraversal(TreeNode *root ,vector<KeyType> &tarversal)
	{
		if(root)
		{
			inOrderTraversal(root->left,tarversal) ;
			tarversal.push_back(root->key) ;
			inOrderTraversal(root->right,tarversal) ;
		}
	}

	void convert(TreeNode *root ,vector<KeyType> &sortOrder , int &currentRef)
	{
		if(root)
		{
			convert(root->left,sortOrder,currentRef) ;
			root->key = sortOrder.at(currentRef++) ;
			convert(root->right,sortOrder,currentRef) ;
		}
	}
	TreeNode* BTToBST(TreeNode *root)
	{
		vector<KeyType> inTraversalList ;
		inOrderTraversal(root,inTraversalList);
		cout<<"InOrder traversal = "<<inTraversalList <<"\n" ;
		std::sort(inTraversalList.begin(),inTraversalList.end(),KeyComparator()) ;
        int index = 0 ;
		convert(root,inTraversalList,index) ;
        inOrderTraversal(root) ;
		return root ;
	}


};
void driver()
{
  fstream fin("input.txt");	
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(30);
  root->right = new TreeNode(15);
  root->left->left =new  TreeNode(20);
  root->right->right = new TreeNode(5);
  Solution solver ;
  solver.BTToBST(root) ;
}
/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
