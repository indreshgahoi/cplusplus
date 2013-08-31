/*
 * RemoveDuplicateFromSortedList.cpp
 *
 *  Created on: Mar 23, 2013
 *      Author: indresh
 */
#include<iostream>
#include<cstdio>

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){

	}
};
//Given 1->2->3->3->4->4->5, return 1->2->5.
//Given 1->1->1->2->3, return 2->3.
 ListNode *deleteDuplicatesii(ListNode *head) {
 if(!head || !head->next) return head;
  ListNode *pre=NULL,*x=head,*y=head->next;
  while(y){
	  if((y->val)==(x->val)){
		  while(y && (y->val)==(x->val)){
		      ListNode *temp=y;
		      y=y->next;
		      x->next=y;
		      delete temp;
		  }
		  if(pre==NULL){
			  pre=NULL;
			  ListNode *temp=x;
             head=x->next;
             x=head;
             if(x)
            	 y=x->next;
             delete temp;
		  }
		  else{
			  ListNode *temp=x;
			  pre->next=x->next;
			  x=x->next;
			  if(x)
				  y=x->next;
			  delete temp;
		  }
	  }
	  else{
		  pre=x;
		  x=y;
		  y=y->next;
	  }

  }
  return head;
}

// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.

 ListNode *deleteDuplicates(ListNode *head) {

	 if(!head || !head->next) return NULL;
	 ListNode *x=head,*y=head->next;

	 while(y){

		 if((y->val)==(x->val)){
			 ListNode *temp=y;
			 x->next=y->next;
			 y=y->next;
			 delete temp;
		 }
		 else{
			 x=y;
			 y=y->next;
		 }
	 }
   return head;
 }

