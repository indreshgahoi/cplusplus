/*
 * SerializationAndDeSerialization.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/SerializationAndDeSerialization.cpp -o /usr/build/Main.o
 *
 *  Created on: Feb 10, 2014
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

template <typename T>
struct TreeNode
{
	T key ;
	TreeNode *left , *right ;
	TreeNode(T k):key(k),left(0),right(0)
	{

	}
};

class Solution
{
	public :
   
	void write(TreeNode<int> *root , ostream &out)
	{
          if(!root)
          {
        	  out<<"# ";
          }
          else
          {
        	  out<<root->key<<" ";
        	  write(root->left,out);
        	  write(root->right,out);
          }
	}

	void read(TreeNode<int> *&root,ifstream &fin)
	{
		int token ;
		bool isNumber ;
		string str ;
		if((fin>>str))
		{
			if(str[0]!='#')
			{
				token = atoi(&str[0]) ;
				root = new TreeNode<int> (token);
				read(root->left,fin);
				read(root->right,fin);
			}
			else
			{
				root = 0;
			}
		}

	}
};


void printInorder(TreeNode<int> *root)
{
	if(root)
	{
		printInorder(root->left);
		printf("%d ",root->key);
		printInorder(root->right);
	}
}



void driver()
{
  ifstream fin("output.txt");
  //ofstream  fout("output.txt");
  Solution solver ;
  TreeNode<int> *root = new TreeNode<int>(20) ;
  root->left = new TreeNode<int>(10) ;
  root->right  = new TreeNode<int>(30) ;
  root->left->left = new TreeNode<int>(8) ;
  root->left->right = new TreeNode<int>(9) ;
  root->right->left = new TreeNode<int>(25) ;
  printInorder(root);
  //solver.write(root,fout);
  TreeNode<int> *backRoot = NULL ;
  solver.read(backRoot,fin);
  printf("\n");
  printInorder(backRoot);
}




/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
