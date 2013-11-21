/*
 * CloneGraph.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/graph/CloneGraph.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 18, 2013
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<climits>
#include<string>
#include <cstring>
#include<pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include<time.h>

using namespace std;

#define FOR(_i,a,b) for(int _i=a;_i<b;_i++)
#define REP(_i,n)    for(int _i=0;_i<n;_i++)

typedef int Integer ;

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


  //Definition for undirected graph.
  struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
  };

class Solution {
public:
	map<UndirectedGraphNode*,UndirectedGraphNode*> visited ;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {

        if(node==NULL) return NULL;

        if(visited[node]) return visited[node] ;

        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        visited[node]=new_node;

        for(vector<UndirectedGraphNode*>::iterator it=node->neighbors.begin();
        		it != node->neighbors.end();++it)
        {
        	new_node->neighbors.push_back(cloneGraph(*it));
        }

        return new_node ;
    }
};

void driver()
{
 
}
/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
