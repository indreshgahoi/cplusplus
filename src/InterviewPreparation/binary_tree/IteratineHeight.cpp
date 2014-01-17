/*
 * IteratineHeight.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/IteratineHeight.cpp -o /usr/build/Main.o
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
 /*
  *
  *   use BFS Approach
  *  traversal  (level order Traversal)
  *
  */


struct TreeNode
{
	int val ;
	TreeNode *left ;
	TreeNode *right ;


};

int height(TreeNode *root )
{
	if(!root) return 0 ;

	queue<TreeNode *> Q ;
	int nodeIncurrentLevel , nodeInNextLevel ;
	int height = 0 ;

	Q.push(root) ;
	nodeIncurrentLevel = 1;
	nodeInNextLevel = 0 ;

	while(!Q.empty())
	{
		TreeNode *currenNode = Q.front() ;
		Q.pop() ;
		nodeIncurrentLevel-- ;
		if(currenNode->left)
		{
			Q.push(currenNode->left) ;
			nodeInNextLevel ++ ;
		}
		if(currenNode->right)
		{
			Q.push(currenNode->right) ;
			nodeInNextLevel ++ ;
		}
		if(nodeIncurrentLevel==0)
		{
			nodeIncurrentLevel = nodeInNextLevel ;
			nodeInNextLevel = 0 ;
			height ++ ;
		}
	}
	return height ;

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
