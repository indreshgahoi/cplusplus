/*
 * BoundaryTraversal.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/BoundaryTraversal.cpp -o /usr/build/Main.o
 *
 *  Created on: Dec 25, 2013
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
Link :-  http://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
Question :-
 Given a binary tree, print boundary nodes of the binary tree Anti-Clockwise starting
 from the root. For example, boundary traversal of the following tree is
 “20 8 4 10 14 25 22


  
To solve the problem we first break the problem into three part
1 -> print left boundary in preorder manner
2 -> print leafs node in inorder manner
3 -> print right node in postorder manner


Note : print root separately other wise it prints twice .


*/


struct TreeNode
{
	int val ;
	struct TreeNode *left ;
	struct TreeNode *right ;
	TreeNode(int val_):val(val_),left(0),right(0){

	};
};
class Solution
{
	public :
	// pre order manner
    void printf_left_boundary(TreeNode *root)
    {
    	if(root)
    	{
    		if((root->left || root->right))
    			printf("%d ",root->val);
    		if(root->left)
    		{
    		   printf_left_boundary(root->left) ;
    		}
    		else
    		{
    			printf_left_boundary(root->right) ;
    		}
    	}

    }
	// inOrder fashion
    void print_leafs_leftToRight(TreeNode *root)
    {
         if(root)
         {
        	 print_leafs_leftToRight(root->left);
        	 if(root->left==0 && root->right==0)
        		 printf("%d ",root->val);
        	 print_leafs_leftToRight(root->right);
         }
    }
    // post Order fashion
    void print_right_boundary(TreeNode* root)
    {
    	if(root)
    	{
    		if(root->right)
    		{
    		 print_right_boundary(root->right);
    		}
    		else
    		{
    			print_right_boundary(root->left) ;
    		}
    		if(root->left || root->right)
    			printf("%d ",root->val);
    	}
    }
	void print_boundary(TreeNode* root)
	{
		if(!root) return ;

		printf_left_boundary(root->left) ;
		print_leafs_leftToRight(root->left) ;
		print_leafs_leftToRight(root->right) ;
		print_right_boundary(root->right) ;
		printf("%d ",root->val) ;


	}
};
void driver()
{
  fstream fin("input.txt");	


    /*          10
  	 *       7       14
  	 *     6   8   13   15
  	 *       18
  	 */
  TreeNode *root = new TreeNode(10);
  	root->left = new TreeNode(7);
  	root->right = new TreeNode(14);
  	root->right->left = new TreeNode(13);
  	root->right->right = new TreeNode(15);
  	root->left->left = new TreeNode(6);
  	root->left->right = new TreeNode(8);
  	root->left->left->right = new TreeNode(18);
  Solution solver ;
  solver.print_boundary(root);
}
/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
