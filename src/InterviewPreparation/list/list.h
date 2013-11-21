/*
 * list.h
 *
 *  Created on: Oct 31, 2013
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



