/*
 * LeftView.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/LeftView.cpp -o /usr/build/Main.o
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
 *
 *
 *
 *
 *
Link :-  
Question :-

Print Left View of a Binary Tree

Given a Binary Tree, print left view of it.
Left view of a Binary Tree is set of nodes visible when tree is visited from left
side. Left view of following tree is 12, 10, 25.

          12
       /     \
     10       30
            /    \
          25      40

The left view contains all nodes that are first nodes in their levels.
 A simple solution is to do level order traversal and print the first node
 in every level


 Answer :-
  The problem can also be solved using simple recursive traversal.
We can keep track of level of a node by passing a parameter to all recursive calls
The idea is to keep track of maximum level also. Whenever we see a node whose level
 is more than maximum level so far, we print the node because this is the first node
  in its level (Note that we traverse the left subtree before right subtree).
   Following is C implementation of this approach
  
  
*/
class Solution
{
	public :
   
};


/*
 *  to attack this problem
 *  we pass the currentLevel and maxLevel we have seen so far ;
 *  if currentLevel is Greate than max Level upadte the maxLevel
 *  print the key ;
 *
 *  we are traversing the left view
 *
 */

typedef int KeyType ;
struct TreeNode
{
	KeyType key ;
	TreeNode *left ;
	TreeNode *right ;
};


void printLeftView(TreeNode *root ,int currentLevel, int &maxLevelsoFar)
{
	if(!root) return ;

	if(currentLevel > maxLevelsoFar)
	{
		maxLevelsoFar = currentLevel ;
		printf(" &d",root->key) ;
	}
	printLeftView(root->left , currentLevel +1 , maxLevelsoFar);
	printLeftView(root->right , currentLevel+1,maxLevelsoFar) ;
}

/*
 input.txt 

*/

void driver()
{
  TreeNode *root = NULL ;
  int currentLevel = 1 , maxLevelSoFar = 0;

  printLeftView(root,currentLevel,maxLevelSoFar) ;
}
int main(){
	driver();
	cout<<"\n";
	return 0;
}
