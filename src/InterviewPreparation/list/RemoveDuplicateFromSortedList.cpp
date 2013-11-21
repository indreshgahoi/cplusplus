/*
 * RemoveDuplicateFromSortedList.cpp
 *
 *  Created on: Mar 23, 2013
 *      Author: indresh
 */
#include<iostream>
#include<cstdio>
#include<stdlib.h>


#define ARRAYSIZE(A)  (sizeof(A) / sizeof(A[0]))

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

 //Given 1->2->3->3->4->4->5, return 1->2->5.
 //Given 1->1->1->2->3, return 2->3.
void test_1_deleteDuplicatesii(){
	int arr [] = {1,2,3,3,4,4,5};
	ListNode *head = getListFromArray(arr, ARRAYSIZE(arr));
	printList(head);
	head=deleteDuplicatesii(head);
	printList(head);
}
void test_2_deleteDuplicatesii(){
	int arr [] = {1,1,1,2,3};
	ListNode *head = getListFromArray(arr, ARRAYSIZE(arr));
	printList(head);
	head=deleteDuplicatesii(head);
	printList(head);
}

// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.

 ListNode *deleteDuplicates(ListNode *head) {

	 if(!head || !head->next) return NULL;
	 ListNode *x=head,*y=head->next;

	 while(y){

		 if((x->val)==(y->val)){
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


 // Given 1->1->2, return 1->2.
 // Given 1->1->2->3->3, return 1->2->3.
 void test_1_deleteDuplicates(){
	 int arr [] = {1,1,2};
	 	ListNode *head = getListFromArray(arr, ARRAYSIZE(arr));
	 	printList(head);
	 	head=deleteDuplicates(head);
	 	printList(head);
 }

 void test_2_deleteDuplicates(){
	 int arr [] = {1,1,2,3,3};
	 	ListNode *head = getListFromArray(arr, ARRAYSIZE(arr));
	 	printList(head);
	 	head=deleteDuplicates(head);
	 	printList(head);
 }


 int main(){

    //test_1_deleteDuplicatesii();
    //test_2_deleteDuplicatesii();
	 test_1_deleteDuplicates();
	 test_2_deleteDuplicates();
	 return 0 ;
}

