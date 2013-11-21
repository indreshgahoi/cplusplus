/*
 * SegerateVowelNodes.cpp
 *
 *  Created on: Oct 30, 2013
 *      Author: Indresh Gahoi
 */
#include<iostream>
#include<cstdio>
#include<stdlib.h>


#define ARRAYSIZE(A)  (sizeof(A) / sizeof(A[0]))

struct ListNode{
	char ch;
	ListNode *next;
	ListNode(char x):ch(x),next(NULL){

	}
};

void push(ListNode **head_ref ,char new_data){
	ListNode *new_node=(ListNode *) malloc(sizeof(ListNode));
	new_node->ch=new_data;
	new_node->next=(*head_ref);
   *head_ref=new_node;
}

ListNode *getListFromArray(char *arr ,int size){
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
		printf("[%c]->",head_ref->ch);
		head_ref=head_ref->next;
	}
    printf("NULL\n");
}

void printNode(ListNode *node){
	if(!node) {printf("[NULL]\n"); }
	else{
		printf("(%x)[val=%c,next(%x)]\n",node,node->ch,node->next);
	}
}

/*
 * Given a linked list containing character in each node, segregate its nodes in
 *  such a way that all nodes containing a vowel are moved to the end of the linked list.
 *  We will have to maintain the order.
 */

ListNode* SegerateVowel(ListNode *head){
 ListNode *start ,*end , *current,*pre;
 start=end=NULL;
 current = head ;
 pre = NULL ;

 // Habdle empty list
 if(!head) return NULL ;

 while(current != NULL){
	 char ch = current->ch ;
	 if(ch== 'a' || ch== 'e' || ch== 'i' || ch=='o' || ch=='u'){
		 if(end==NULL)
		 {
			 start = current ;
		 }
		 else
		 {
		    end->next = current ;
		 }
			end = current ;

           if(pre == NULL){
        	   head = current->next;
        	   current = head ;
           }
           else
           {
        	   pre->next = current -> next;
        	   current = current -> next;
           }
           end->next = NULL ;
	 }
	 else
	 {
		 pre = current ;
		 current = current->next ;
	 }
 }

 if(pre!=NULL)
	 pre->next = start ;
 else
 {
	 /*Tricky case whel all the nodes all vowel then head of first list is null */
	 head = start ;
 }

 return head ;
}

/* all nodes are vowel
 * no nodes vowel
 * empty list
 *  one node
 *  two node
 *
 */

void test_0_SegerateVowel(){
	char arr[] = {'b'} ;
		ListNode *head = getListFromArray(arr,ARRAYSIZE(arr));
		printList(head);
		head = SegerateVowel(head);
		printList(head);
}
void test_1_SegerateVowel(){

	char arr[] = {'a','b','c','e','d','i','u','f'} ;
	ListNode *head = getListFromArray(arr,ARRAYSIZE(arr));
	printList(head);
	head = SegerateVowel(head);
	printList(head);
}

int main(){
	//test_1_SegerateVowel();
	test_0_SegerateVowel();

	return 0 ;
}
