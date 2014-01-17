/*
 * PostFromInPre.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/PostFromInPre.cpp -o /usr/build/Main.o
 *
 *  Created on: Dec 30, 2013
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


Print Postorder traversal from given Inorder and Preorder traversals

Given Inorder and Preorder traversals of a binary tree, print Postorder traversal.

Example:

Input:
Inorder traversal in[] = {4, 2, 5, 1, 3, 6}
Preorder traversal pre[] = {1, 2, 4, 5, 3, 6}

Output:
Postorder traversal is {4, 5, 2, 6, 3, 1}

Trversals in the above example represents following tree

         1
      /     \
     2       3
   /   \      \
  4     5      6

A naive method is to first construct the tree, then use simple recursive method to print postorder traversal
of the constructed tree.

We can print postorder traversal without constructing the tree.
 The idea is, root is always the first item in preorder traversal and
 it must be the last item in postorder traversal. We first recursively print left subtree,
  then recursively print right subtree. Finally, print root.
To find boundaries of left and right subtrees in pre[] and in[],
   we search root in in[], all elements before root in in[] are elements of left subtree and all elements after
    root are elements of right subtree. In pre[],
     all elements after index of root in in[] are elements of right subtree.
      And elements before index (including the element at index and excluding the first element)
      are elements of left subtree.
  
*/
class Solution
{
	public :
   
};

/*
 *  print postorder from inorder and preorder without buildind tree
 *
 *
 */

int search(int arr[] ,int size , int key)
{
	int iter = 0 ;
	for( iter = 0 ; iter < size ; ++iter)
	{
		if(arr[iter]==key)
			break ;
	}
	return iter ;
}
void printPostOrder(int in[] , int pre[] , int size)
{

    int root = pre[0] ;
    int posInInord = search(in,size,root) ;
    if(posInInord != 0)
    	printPostOrder(in,pre+1,posInInord) ;
    if(posInInord != size-1)
    	printPostOrder(in+posInInord+1,pre+posInInord+1,size-posInInord-1) ;
	printf("%d ",root) ;
}




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
