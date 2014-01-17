/*
 * getLevelDiff.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/getLevelDiff.cpp -o /usr/build/Main.o
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
  
 The problem can also be solved using simple recursive traversal.
  We can recursively calculate the required difference as,
  value of root’s data subtracted by the difference for subtree under left child
  and the difference for subtree under right child.
  Following is C implementation of this approach.



Difference between sums of odd level and even level nodes of a Binary Tree

Given a a Binary Tree, find the difference between the sum of nodes at odd level and the sum of nodes at even level. Consider root as level 1, left and right children of root as level 2 and so on.

For example, in the following tree, sum of nodes at odd level is (5 + 1 + 4 + 8) which is 18. And sum of nodes at even level is (2 + 6 + 3 + 7 + 9) which is 27. The output for following tree should be 18 – 27 which is -9.

      5
    /   \
   2     6
 /  \     \
1    4     8
    /     / \
   3     7   9

A straightforward method is to use level order traversal.
 In the traversal, check level of current node, if it is odd,
 increment odd sum by data of current node, otherwise increment even sum.
  Finally return difference between odd sum and even sum.
  See following for implementation of this approach .
  
*/




typedef int KeyType ;

struct TreeNode
{
   KeyType key ;
   TreeNode *left ;
   TreeNode *right ;
};

int LevelDiff(TreeNode *root)
{
	if(!root) return 0 ;

	return root->key - LevelDiff(root->left)-LevelDiff(root->right) ;
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
