/*
 * ReverseLinkList.cpp
 *
 *  Created on: Mar 16, 2013
 *      Author: indresh
 */
//Definition for singly-linked list.
#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };


ListNode *reverseBetween(ListNode *head, int m, int n) {
	if(m==n)
		return head;
    if(m>n){
	  swap(m,n);
    }
 ListNode *p=head;
 int cnt=0;
  while((m-2)>0&& cnt!=(m-2) && p){
	 p=p->next;
	 cnt++;
   }


  if(p){
        m=m-cnt;

  ListNode *x=((m==1)?head:(p->next)),*y=NULL,*z=NULL;

  while(x && cnt!=(n-m+1)){
	    z=y;
	    y=x;
	    x=x->next;
	    y->next=z;
	    cnt++;
  }


   if(m!=1){
     p->next->next=x;
     p->next=y;
   }
   else
   {
     head->next=x;
     head=y;
   }
 }
 return head;
}

void printList(ListNode *head){
	cout<<"[";
	while(head){
		if(head->next)
		 cout<<""<<head->val<<",";
		else{
			cout<<""<<head->val<<"]"<<endl;
			break;
		}
		head=head->next;
	}
 }





int main(){
	ListNode *head=new ListNode(1);
	ListNode *n2=new ListNode(2);
	ListNode *n3=new ListNode(3);
	ListNode *n4=new ListNode(4);
	ListNode *n5=new ListNode(5);
	n5->next=NULL;
	head->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;

	printList(head);
    printList(reverseBetween(head,3,4));
	return 0;
}

