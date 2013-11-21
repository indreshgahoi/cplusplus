/*
 * LinkedListSwapInPatternK.cpp
 *
 *  Created on: Oct 30, 2013
 *      Author: Indresh Gahoi
 */

/* Question :-
 *  You are given a linked list and a parameter k. You will have to swap values in a certain fashion, swap value
 *  of node 1 with node k, then node (k+1) with node 2k and go on doing this in the similar fashion
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

void swap(int *a , int *b){
	int temp = *a ;
	*a = *b ;
	*b = temp ;
}

void PatternSwap(ListNode *head , int k){

	ListNode *x ,*y;
	int count;
	if(!head) return ;
	x = y = head ;
	count = 1;
	while(y->next != NULL)
	{
      y = y->next ;
      count++ ;
      if(k==count){
        swap(&x->val,&y->val);
        if(y->next != NULL ){
        	x=y=y->next;
        	count = 1;
        }

      }

	}
}

void test_0_PatternSwap(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
   int k = 2;
   ListNode *head = getListFromArray(arr,ARRAYSIZE(arr));
   printf("k=%d  ",k); printList(head);
   PatternSwap(head,k);
   printList(head);


}

void test_1_PatternSwap(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	   int k = 3;
	   ListNode *head = getListFromArray(arr,ARRAYSIZE(arr));
	   printf("k=%d  ",k);printList(head);
	   PatternSwap(head,k);
	   printList(head);

}
void test_2_PatternSwap(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	   int k = 4;
	   ListNode *head = getListFromArray(arr,ARRAYSIZE(arr));
	   printf("k=%d  ",k); printList(head);
	   PatternSwap(head,k);
	   printList(head);
}
int main(){
	test_0_PatternSwap();
	test_1_PatternSwap();
	test_2_PatternSwap();
	return 0 ;
}
