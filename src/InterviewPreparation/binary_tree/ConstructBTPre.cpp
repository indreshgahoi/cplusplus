/*
 * ConstructBTPre.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/ConstructBTPre.cpp -o /usr/build/Main.o
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
Link :-  http://www.geeksforgeeks.org/construct-a-special-tree-from-given-preorder-traversal/
Question :-

Given an array ‘pre[]‘ that represents Preorder traversal of a spacial binary tree
where every node has either 0 or 2 children.
One more array ‘preLN[]‘ is given which has only two possible values ‘L’ and ‘N’.
The value ‘L’ in ‘preLN[]‘ indicates that the corresponding node in Binary Tree is
a leaf node and value ‘N’ indicates that the corresponding node is non-leaf node.
Write a function to construct the tree from the given two arrays.

Input:  pre[] = {10, 30, 20, 5, 15},  preLN[] = {'N', 'N', 'L', 'L', 'L'}
Output: Root of following tree
          10
         /  \
        30   15
       /  \
      20   5

The first element in pre[] will always be root. So we can easily figure out root.
If left subtree is empty, the right subtree must also be empty and preLN[] entry
for root must be ‘L’. We can simply create a node and return it.
If left and right subtrees are not empty, then recursively call for left and right subtrees and link the returned nodes to root.

  
*/
typedef int KeyType ;

struct TreeNode
{
	KeyType key ;
	struct TreeNode *left , *right ;
	TreeNode(KeyType key_):key(key_),left(NULL),right(NULL){}
};
class Solution
{
	public :

	TreeNode* ConstructBinaryTree(int *pre , char *nodeType , int size , int &start)
	{
		if(start==size)
		{
			return 0 ;
		}
		TreeNode *parentNode = new TreeNode (pre[start]) ;
		start++ ;
		if(nodeType[start-1]=='N')
		{
			parentNode->left = ConstructBinaryTree(pre,nodeType,size,start) ;
			parentNode->right = ConstructBinaryTree(pre,nodeType,size,start) ;
		}
		return root ;
	}
   
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
