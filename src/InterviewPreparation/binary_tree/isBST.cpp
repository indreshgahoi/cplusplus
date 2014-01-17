/*
 * isBST.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/isBST.cpp -o /usr/build/Main.o
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


 */
struct TreeNode
{
	int val ;
	TreeNode *left ;
	TreeNode *right ;
};

class Solution
{
public :

	bool isValidBSTUtil(TreeNode *root , int min ,int max)
	{
		if(!root) return true ;
		if((root->val < min) || (root->val > max) ) return false ;

		return isValidBSTUtil(root->left,min,root->val-1) && isValidBSTUtil(root->right,(root->val)+1,max);
	}

	bool isValidBSTUtil(TreeNode *root , TreeNode *&pre)
	{
		if(!root) return true ;

		if(isValidBSTUtil(root->left,pre) && (!pre || (pre->val < root->val)))
		{   pre = root ;
		return  isValidBSTUtil(root->right,pre) ;
		}
		return false ;
	}



	bool isValidBST(TreeNode *root) {
		//TreeNode *pre = NULL;
		return isValidBSTUtil(root,INT_MIN,INT_MAX);
		// return isValidBSTUtil(root,pre);
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
