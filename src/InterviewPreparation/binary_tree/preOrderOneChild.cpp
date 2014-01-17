/*
 * preOrderOneChile.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/preOrderOneChile.cpp -o /usr/build/Main.o
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
Link :-  
Question :-


Given Preorder traversal of a BST, check if each non-leaf node has only one child.
Assume that the BST contains unique entries.

Examples

Input: pre[] = {20, 10, 11, 13, 12}
Output: Yes
The give array represents following BST. In the following BST, every internal
node has exactly 1 child. Therefor, the output is true.
        20
       /
      10
       \
        11
          \
           13
           /
         12

In Preorder traversal, descendants (or Preorder successors) of every node appear after the node.
In the above example, 20 is the first node in preorder and all descendants of 20 appear after it.
All descendants of 20 are smaller than it. For 10, all descendants are greater than it.
In general, we can say, if all internal nodes have only one child in a BST,
then all the descendants of every node are either smaller or larger than the node.
The reason is simple, since the tree is BST and every node has only one child,
all descendants of a node will either be on left side or right side,
means all descendants will either be smaller or greater

Navie Approach
 Approach 1 (Naive)
This approach simply follows the above idea that all values on right side
are either smaller or larger. Use two loops, the outer loop picks an element one by one,
starting from the leftmost element.
The inner loop checks if all elements on the right side of the picked element are either smaller or greater.
The time complexity of this method will be O(n^2).

Approach 1 (Naive)
This approach simply follows the above idea that all values on right side are either smaller or larger.
Use two loops, the outer loop picks an element one by one,
starting from the leftmost element. The inner loop checks if all elements on the
right side of the picked element are either smaller or greater.
The time complexity of this method will be O(n^2).

  
*/

typedef int KeyType ;
struct TreeNode
{
	KeyType key ;
	struct TreeNode *left ,*right ;
};

class Solution
{
	public :
    bool preOrderHasOnlyOneChild(int *pre , int size)
    {
    		for(int iter= 0 ; iter<size-1 ; ++iter)
    		{
    			int next = pre[iter+1] ;
    			int last = pre[size-1] ;
    			if(next*last<0) return false ;
    		}
    		return true ;
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
