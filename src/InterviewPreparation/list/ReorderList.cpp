/*
 * ReorderList.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/list/ReorderList.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 25, 2013
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
Link :-  http://oj.leetcode.com/problems/reorder-list/
Question :-
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

 */
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){

	}
};

void push(ListNode **head_ref ,int new_data){
	ListNode *new_node=(ListNode *) malloc(sizeof(ListNode));
	new_node->val=new_data;
	new_node->next=(*head_ref);
	*head_ref=new_node;
}

ListNode *getListFromArray(int *arr ,int size){
	ListNode *head = NULL ;
	int i =0 ;
	for( i =size-1 ; i>=0 ; --i ){
		push(&head,arr[i]);
	}
	return head ;
}
void printList(ListNode *head_ref){

	printf("list=\n      ");
	while(head_ref){
		printf("[%d]->",head_ref->val);
		head_ref=head_ref->next;
	}
	printf("NULL\n");
}

void printNode(ListNode *node){
	if(!node) {printf("[NULL]\n"); }
	else{
		printf("(%x)[val=%d,next(%x)]\n",node,node->val,node->next);
	}
}

class Solution {

	ListNode *AlterNativeMerge(ListNode *a , ListNode *b)
	{
		ListNode dummy(-1) ,*pre ;
		pre = &dummy ;
		bool flag = true ;
		while(a!=0 && b!=0)
		{
			if(flag)
			{
				pre->next = a;
				a = a->next ;
			}
			else
			{
				pre->next = b ;
				b = b->next ;
			}
			pre = pre->next ;
			flag = !flag ;
		}
		while(a!=0)
		{
			pre->next = a ;
			pre = a ;
			a = a->next ;
		}
		while(b!=0)
		{
			pre->next = b ;
			pre = b ;
			b = b->next ;
		}
		return dummy.next ;
	}
	ListNode* reverse(ListNode* head)
	{
		ListNode *pre , *current , *next;
		pre = 0;
		current = head ;
		while(current)
		{
			next = current->next ;
			current->next = pre ;
			pre = current ;
			current = next ;
		}

		return pre ;
	}
public:
	ListNode* split(ListNode* head)
	{
		ListNode  *fast=0,*slow=0; ;
		if(head==0 || head->next==0)
			return slow ;
		fast = head->next ,slow=head ;
		while(fast != 0 && fast->next)
		{
			fast = fast->next ;
			slow = slow->next ;
			if(fast->next==0)
				break ;
			fast = fast->next ;
		}


			ListNode *t = slow ;
			slow = slow->next ;
			t->next = 0 ;

		return slow ;
	}

	void reorderList(ListNode *head) {
		if(head==0) return ;
		ListNode *l1 = head ;
		ListNode *l2 = split(head);
		l2= reverse(l2);
		AlterNativeMerge(l1,l2);
	}
};
void driver()
{
	fstream fin("input.txt");
	Solution solver ;
	ListNode *l=0 ;
	int x ;
	while(fin>>x)
	{
		push(&l,x);
	}
	solver.reorderList(l);
}
/*
 input.txt 

8 7 6 5 4 3 2 1
7 6 5 4 3 2 1
3 2 1
2 1
1

 */
int main(){
	driver();
	cout<<"\n";
	return 0;
}
