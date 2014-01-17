/*
 * RightNextKeyLevelOrder.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/binary_tree/RightNextKeyLevelOrder.cpp -o /usr/build/Main.o
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
  
Given a Binary tree and a key in the binary tree, find the node right to the given key.
If there is no node on right side, then return NULL.
Expected time complexity is O(n) where n is the number of nodes in the given binary tree

  
*/

struct TreeNode
{
	int key ;
	TreeNode *left ;
	TreeNode *right ;
};





// using Recurrsion
// pre Order Fashion

void getRightNodeInLevel(TreeNode *root ,int currLevel ,int &targetLevel ,int keyToFind , TreeNode * &keyNodeRef , TreeNode * &targetRightNodeRef)
{
	if(!root) return ;

	//
	if(keyNodeRef != NULL && currLevel == targetLevel)
	{
		targetRightNodeRef = root ;
		return ;
	}

	if(root->key == keyToFind)
	{
		targetLevel = currLevel ;
		keyNodeRef = root ;
		return ;
	}
	getRightNodeInLevel(root->left,currLevel+1,targetLevel,keyToFind,keyNodeRef,targetRightNodeRef);
	getRightNodeInLevel(root->right,currLevel+1,targetLevel,keyToFind,keyNodeRef,targetRightNodeRef);
}
// using Level Oredr Traversal
TreeNode* findNextRightOfKey(TreeNode *root , int targetKey)
{
	struct QueueEntry
	{
		TreeNode *nodePtr ;
		int nodeLevel;
	};

	queue<QueueEntry> queue;
	TreeNode *targetPtr = NULL ;
	int currentLevel = 0 ;
	if(root)
	{
	  QueueEntry qEntry ;
	  qEntry.nodePtr = root ;
	  qEntry.nodeLevel = currentLevel ;
	}

	while(!queue.empty())
	{
		QueueEntry nextEntry ;
		QueueEntry currentEntry = queue.front();
		queue.pop();
        currentLevel = currentEntry.nodeLevel ;
        nextEntry.nodeLevel = currentLevel + 1 ;
        // find target key
		if(currentEntry.nodePtr->key == targetKey)
		{
			if(queue.empty() || queue.front().nodeLevel != currentLevel)
			{
				return NULL ;
			}
			targetPtr = queue.front().nodePtr ;
			return targetPtr ;
		}

		if(currentEntry.nodePtr->left)
		{
			nextEntry.nodePtr = currentEntry.nodePtr->left ;
			queue.push(nextEntry) ;
		}
		if(currentEntry.nodePtr->right)
		{
			nextEntry.nodePtr = currentEntry.nodePtr->right ;
			queue.push(nextEntry) ;
		}
	}

	return targetPtr ;
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
