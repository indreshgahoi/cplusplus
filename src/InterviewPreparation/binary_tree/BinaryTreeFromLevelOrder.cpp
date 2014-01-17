/*
 * BinaryTreeFromLevelOrder.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/BinaryTreeFromLevelOrder.cpp -o /usr/build/Main.o
 *
 *  Created on: Jan 1, 2014
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

typedef int KeyType ;

struct TreeNode
{
	KeyType key ;
	struct TreeNode *left ;
	struct TreeNode *right ;
	TreeNode(int key_):key(key_),left(NULL),right(NULL){}
};

class A
{
public :
	TreeNode *root ;
	A()
	{
		TreeNode *root1 = new TreeNode(5);
		printf("root1 %p \n",root1) ;
        root = root1 ;
        TreeNode &myRoot = (*root1) ;
        printf("myRoot %p \n",&myRoot);
	}
};
class Solution
{
	public :

	TreeNode* getRoot(const vector<int> &V)
	{
		TreeNode *result = NULL ;
	   return result ;
	}
};
void driver()
{
  fstream fin("input.txt");
   A a;
   printf("\n a val %d %p",a.root->key,a.root);
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
