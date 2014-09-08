/*
 * twoSumInBST.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/twoSumInBST.cpp -o /usr/build/Main.o
 *
 *  Created on: Feb 6, 2014
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
template<typename T>
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

    bool getTwoSum(TreeNode *root , int target)
	{
		stack<TreeNode*> iter ;
		stack<TreeNode*> riter ;
		TreeNode<int> *iCurr = root ;
		TreeNode<int> *rCurr = root ;
		int lval ;
		int rval ;
		bool iEnd = true ;
		bool rEnd = true ;
		while(true)
		{
			while(iEnd)
			{
                 if(iCurr)
                 {
                	 iter.push(iCurr) ;
                	 iCurr = iCurr->left ;
                 }
                 else
                 {
                	 if(iter.empty())
                	 {
                		 iEnd = false ;
                	 }
                	 else
                	 {
                       iCurr = iter.top();
                       lval = iCurr->key ;
                       iter.pop();
                       iCurr = iCurr->right ;
                       iEnd = false ;
                	 }
                 }
			}
		   while(rEnd)
		   {
			   if(rCurr)
			   {
				   riter.push(rCurr);
				   rCurr = rCurr->right ;
			   }
			   else
			   {
				   if(riter.empty())
				   {
					   rEnd = false ;
				   }
				   else
				   {
					   rCurr = riter.top();
					   rval = rCurr->key ;
					   riter.pop();
					   rCurr = rCurr->left ;
					   rEnd = false ;
				   }
			   }
		   }

		   if(lval!=rval && (lval+rval)==target)
		   {
			   printf("%d %d %d",lval,rval,target);
			   return true ;
		   }
		   if((lval+rval)<target)
		   {
			   iEnd = true ;
		   }
		   else if((lval+rval)>target)
		   {
			   rEnd = true ;
		   }
		   if(lval>=rval)
			   return false ;
		}
		return false ;
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
