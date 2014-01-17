/*
 * SumTree.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/SumTree.cpp -o /usr/build/Main.o
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

Convert a given tree to its Sum Tree

Given a Binary Tree where each node has positive and negative values.
Convert this to a tree where each node contains the sum of the left and right sub
trees in the original tree. The values of leaf nodes are changed to 0.

For example, the following tree

                  10
               /      \
	         -2        6
            /   \     /  \
	       8     -4    7    5

should be changed to

                 20(4-2+12+6)
               /      \
	        4(8-4)    12(7+5)
           /   \      /  \
	      0     0    0    0
  
  
*/

typedef int KeyType ;

struct TreeNode
{
	KeyType key ;
	TreeNode *left , *right ;
	TreeNode(KeyType key_):key(key_),left(0),right(0) {} ;
};

class Solution
{
	public :

	int ConvertSumTree(TreeNode *root)
	{
		if(!tree) return 0 ;
		int old_value = root->key ;

		root->key = ConvertSumTree(root->left) + ConvertSumTree(root->right) ;

		return old_value+root->key ;
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
