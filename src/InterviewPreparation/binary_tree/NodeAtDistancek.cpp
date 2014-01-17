/*
 * NodeAtDistancek.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/NodeAtDistancek.cpp -o /usr/build/Main.o
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
	TreeNode(KeyType key_):key(key),left(0),right(0){} ;
};


class Solution
{
	public :
   
	void printNodesAtDistanceK(TreeNode *root , int distance)
	{
		if(!root) return ;

		if(distance==0)
		{
			printf(" %d ",root->key) ;
		}
		else
		{
			printNodesAtDistanceK(root->left,distance-1);
			printNodesAtDistanceK(root->right,distance-1);
		}
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
