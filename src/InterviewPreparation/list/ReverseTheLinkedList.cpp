/*
 * ReverseTheLinkedList.cpp
 *
 *  Created on: Mar 15, 2013
 *      Author: indresh
 */
#include<iostream>
#include<vector>
#include<cstdio>
#include<alloca.h>
#include <malloc.h>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}


};


void push(ListNode **head_ref ,int new_data){

	ListNode *new_node=(ListNode *) malloc(sizeof(ListNode));
	new_node->val=new_data;
	new_node->next=(*head_ref);
	*head_ref=new_node;
}

void printList(ListNode *head_ref){
	static int i=0;
 printf("G Test Case #%d\n",(++i));
	printf("list=[");
	while(head_ref){
		printf("%d ",head_ref->val);
		head_ref=head_ref->next;
	}
    printf("]\n");
}

void iterativeReverse(ListNode **head_ref){
	ListNode *pre=NULL;
	ListNode *current=(*head_ref);
	ListNode *next=NULL;

	while(current){
		 next=current->next;
		 current->next=pre;
		 pre=current;
		 current=next;
	}
	(*head_ref)=pre;
}

void recursiveReverse(ListNode **head_ref){
	//handle base case empty Case
	if(!(*head_ref)) return;
	ListNode *head=(*head_ref);
	ListNode *rest=head->next;
	// base case only the node in Linked List
	if(!rest) return;
	recursiveReverse(&rest);
	head->next->next=head;
	head->next=NULL;
	*head_ref=rest;
}

void group_reverse(ListNode **head_ref,int k){


	     ListNode *pre=NULL,*current=(*head_ref),*next=NULL;
         int cnt=k;
	     while(current && cnt ){
	    	 next=current->next;
	    	 current->next=pre;
	    	 pre=current;
	    	 current=next;
	    	 cnt--;
	     }

	     ListNode *pre_head=(*head_ref);
	     (*head_ref)=pre;
	     ListNode *temp=NULL;
	     if(current)
	    	 temp=current;

	     if(temp)
	       group_reverse(&temp,k);
	     pre_head->next=temp;
	     printList((*head_ref));
}

void modifi_group_reverse(ListNode **head_ref,int k){


	     ListNode *pre=NULL,*current=(*head_ref),*next=NULL;
         int cnt=k;
         while(current && cnt){
        	 cnt--;
        	 current=current->next;
         }
         if(cnt==0){
        	 current=(*head_ref);
        	 cnt=k;
	     while(current && cnt ){
	    	 next=current->next;
	    	 current->next=pre;
	    	 pre=current;
	    	 current=next;
	    	 cnt--;
	      }
	     ListNode *pre_head=(*head_ref);
	    	     (*head_ref)=pre;
	    	     ListNode *temp=NULL;
	    	     if(current)
	    	    	 temp=current;

	    	     if(temp)
	    	    	 modifi_group_reverse(&temp,k);
	    	     pre_head->next=temp;
         }


	     //printList((*head_ref));
}
ListNode *reverseKGroup(ListNode * head, int k) {

       if(head)group_reverse(&head,k);
        return head;
    }


void group_reverse_Test(){
	ListNode *head=NULL;
 //	push(&head,8);
//	push(&head,7);
//    push(&head,6);
//    push(&head,5);
//    push(&head,4);
//    push(&head,3);
//    push(&head,2);
//    push(&head,1);
    printf("Intial List=");
    printList(head);
    group_reverse(&head,3);
    printf("\n After Group Reverse List=");
    printList(head);
    printf("\n");
}




void recursiveTestCase(){

	ListNode *head_ref=NULL;

	    push(&head_ref,3);
	    printList(head_ref);
	    recursiveReverse(&head_ref);
	    printList(head_ref);
	    push(&head_ref,2);
	    push(&head_ref,1);
	    printList(head_ref);
	   recursiveReverse(&head_ref);
	    printList(head_ref);

}

void iterativeTest(){
	ListNode *head_ref=NULL;
//	ListNode *two=(ListNode *) malloc(sizeof(ListNode));
//	ListNode *three=(ListNode *) malloc(sizeof(ListNode));
//	ListNode *four=(ListNode *) malloc(sizeof(ListNode));
    push(&head_ref,3);
    printList(head_ref);
    iterativeReverse(&head_ref);
    printList(head_ref);
    push(&head_ref,2);
    push(&head_ref,1);
    printList(head_ref);
    iterativeReverse(&head_ref);
    printList(head_ref);
}

int main(){

	//iterativeTest();
	//recursiveTestCase();
	group_reverse_Test();
	return 0;
}
