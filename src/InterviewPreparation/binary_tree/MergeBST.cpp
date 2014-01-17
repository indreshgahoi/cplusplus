/*
 * MergeBST.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/MergeBST.cpp -o /usr/build/Main.o
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
  
  
*/
typedef int KeyType ;

struct TreeNode
{
	KeyType key ;
	TreeNode *left , *right ;
	TreeNode(KeyType key_):key(key_),left(0),right(0){};
};


class InOrderIterator
{


public :
	InOrderIterator(const TreeNode *tree){
		_currentPtr = 0 ;
		_nextPtr = tree ;
        next();

	}

	bool hasNext()
	{
		return !_parentStack.empty() || _currentPtr!=NULL ;
	}
	const TreeNode* get()
	{
		return _currentPtr ;
	}

	const TreeNode* next()
	{

        _currentPtr = _nextPtr ;
		while(hasNext())
		{
			if(_nextPtr != NULL)
			{
				_parentStack.push(_nextPtr) ;
				_nextPtr = _nextPtr->left ;
			}
			else
			{
				_currentPtr = _parentStack.top() ;
				_parentStack.pop();
				_nextPtr = _currentPtr->right ;
				break ;
			}
		}
		return _currentPtr ;
	}

private:
	const TreeNode *_currentPtr ;
	const TreeNode *_nextPtr ;
	stack<const TreeNode*> _parentStack ;


};



class Solution
{
	public :

	vector<int> inorderTraversal(TreeNode *root) {
	        InOrderIterator iter(root) ;
	        vector<int> result ;
	        while(iter.hasNext())
	        {
	        	cout<<"val "<<iter.get()->key ;
	            result.push_back(iter.get()->key);
	            iter.next();
	        }
	        return result ;

	    }





	vector<KeyType> MergeTwoBST(TreeNode *t1 ,TreeNode *t2)
	{
      InOrderIterator iteratort1(t1) ;
      InOrderIterator iteratort2(t2) ;
      vector<KeyType> mergeList ;

      while(iteratort1.hasNext() && iteratort2.hasNext())
      {
         const TreeNode *t1Node = iteratort1.get();
         const TreeNode *t2Node = iteratort2.get() ;

         if(t1Node->key < t2Node->key)
         {
        	 mergeList.push_back(t1Node->key) ;
        	 iteratort1.next() ;
         }
         else
         {
        	 mergeList.push_back(t2Node->key) ;
        	 iteratort2.next() ;
         }
      }

      while(iteratort1.hasNext())
      {
    	  mergeList.push_back(iteratort1.get()->key) ;
    	  iteratort1.next() ;
      }

      while(iteratort2.hasNext())
      {
        	  mergeList.push_back(iteratort2.get()->key) ;
        	  iteratort2.next() ;
      }

       return mergeList ;
	}
   

};



void driver()
{
  fstream fin("input.txt");	
  Solution solver ;
  TreeNode *root1 = new TreeNode(3);
      root1->left = new TreeNode(1);
      root1->right = new TreeNode(5);

      /* Let us create the following tree as second tree
              4
            /  \
           2    6
       */
      TreeNode *root2 = new TreeNode(4);
      root2->left = new TreeNode(2);
      root2->right = new TreeNode(6);

   cout<<"Solution = "<<solver.MergeTwoBST(root1,root2) ;
}
/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
