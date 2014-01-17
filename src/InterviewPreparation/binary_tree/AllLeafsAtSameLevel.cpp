/*
 * AllLeafsAtSameLevel.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/AllLeafsAtSameLevel.cpp -o /usr/build/Main.o
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
#include<cassert>

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
  
  

Check if all leaves are at same level

Given a Binary Tree, check if all leaves are at same level or not.

          12
        /    \
      5       7
    /          \
   3            1
  Leaves are at same level

          12
        /    \
      5       7
    /
   3
   Leaves are Not at same level


          12
        /
      5
    /   \
   3     9
  /      /
 1      2
 Leaves are at same level

We strongly recommend you to minimize the browser and try this yourself first.

The idea is to first find level of the leftmost leaf and store it in a variable
leafLevel. Then compare level of all other leaves with leafLevel, if same,
return true, else return false. We traverse the given Binary Tree in Preorder fashion
. An argument leaflevel is passed to all calls.
The value of leafLevel is initialized as 0 to indicate that the first leaf is not
yet seen yet. The value is updated when we find first leaf.
 Level of subsequent leaves (in preorder) is compared with leafLevel.


*/

typedef int KeyType ;
struct TreeNode
{
	KeyType key ;
	TreeNode *left ;
	TreeNode *right ;
};

bool isLeaf(TreeNode *root)
{
	assert(root==NULL);
	return (!root->left && !root->right) ;
}


// Method 1

bool isAllLeafsAtSameLevel(TreeNode *root , int currentLevel , int &leafLavel)
{
	if(!root) return true;

	if(isLeaf(root))
	{
		if(leafLavel == 0)
		{
			leafLavel = currentLevel ;
			return true ;
		}
		return currentLevel == leafLavel ;
	}
    if(isAllLeafsAtSameLevel(root->left,currentLevel+1,leafLavel))
     return isAllLeafsAtSameLevel(root->right,currentLevel+1,leafLavel) ;
    return false;
}


// method 2
// In this method
// we return the level value
// and compare also right and left subTree
//

int checkUtil(TreeNode *root, int level)
{
    // Base case
    if (root == NULL)  return 1;

    // If a leaf node is encountered
    if (root->left == NULL && root->right == NULL)
        return (level+1);

    // If this node is not leaf, recursively check left and right subtrees
    return checkUtil(root->left, level+1) == checkUtil(root->right, level+1);
}

/* The main function to check if all leafs are at same level.
   It mainly uses checkUtil() */
bool check(TreeNode *root)
{
   int level = 0;
   return checkUtil(root, level);
}

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
