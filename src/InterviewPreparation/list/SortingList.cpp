/*
 * SortingList.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/list/SortingList.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 20, 2013
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


 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {

	 ListNode* merge(ListNode * a ,ListNode *b)
	 {
	    if(a==0)
	    {
	    	return b ;
	    }
	    if(b==0)
	    {
	    	return a ;
	    }
	    ListNode *result ;
	    if(a->val <= b->val)
	    {
	    	result = a ;
	    	result->next = merge(a->next,b);
	    }
	    else
	    {
	    	result = b ;
	    	result->next = merge(b->next,a);
	    }
	    return result ;
	 }

	void split(ListNode*start,ListNode *&mid)
	{
	    if(start==0 || start->next==0) return ;
		ListNode  *fast ;
		mid=start;
		fast = start->next ;
		while(fast!=0 && fast->next != 0)
		{

			mid=mid->next ;
			fast=fast->next->next ;

		}
		ListNode *t= mid ;
		mid = mid->next ;
		t->next = 0 ;
	}
public:




    ListNode *sortList(ListNode *head) {

    	if(head==0 || head->next==0) return head ;
    	ListNode *mid=NULL ;
    	split(head,mid);
    	ListNode* a = sortList(head);
    	ListNode* b = sortList(mid);
    	return merge(a,b);
    }
};


/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
