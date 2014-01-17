/*
 * KthSmallestAndLargest.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/KthSmallestAndLargest.cpp -o /usr/build/Main.o
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
	TreeNode(KeyType key_):key(key_),left(0),right(0){} ;
};





class InorderIterator
{
  public :
	 InorderIterator(const TreeNode *tree)
	 {
		 _currentPtr = 0 ;
         _nextPtr = tree ;
		 next();

	 }

	 bool hasNext()
	 {
		 return !_parentStack.empty() || _currentPtr!=0 ;
	 }
     TreeNode* get()
     {
    	 return _currentPtr ;
     }

     TreeNode* next()
     {
    	 _currentPtr = _nextPtr ;
    	 while(hasNext())
    	 {
             if(_nextPtr != 0)
             {
                 _parentStack.push(_nextPtr);
                 _nextPtr = _nextPtr->left ;
             }
             else
             {
            	 _currentPtr = _parentStack.top();
            	 _parentStack.pop() ;
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

/*
 *  Recurr Solution
 *
 */
class Solution
{

public :
	TreeNode* kthSmallest(TreeNode *root, int &k)
	{
		TreeNode *result = 0 ;
		if(root)
		{
			result = kthSmallest(root->left,k) ;
			if(k != 0)
			{
				k-- ;
				if(k==0)
					return root ;
				return kthSmallest(root->right,k) ;
			}

		}
		return  result ;
	}
};

class Solution1
{
	public :

	TreeNode* kthSmallest(TreeNode *root ,int k)
	{
       InorderIterator inIterator(root) ;

        while(inIterator.hasNext() && k--)
        {
        	inIterator.next() ;
        }

        return  inIterator.get() ;
	}

};

void driver()
{
  fstream fin("input.txt");	

   TreeNode *root = new TreeNode(20) ;
    root->left = new TreeNode(10) ;
    root->right  = new TreeNode(30) ;
    root->left->left = new TreeNode(8) ;
    root->left->right = new TreeNode(9) ;
    root->right->left = new TreeNode(25) ;

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
