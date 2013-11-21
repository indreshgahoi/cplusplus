/*
 * AddTwoNumbersRepresentInLinkedList.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/list/AddTwoNumbersRepresentInLinkedList.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 5, 2013
 *      Author: Indresh Gahoi
 */


/*
Add two numbers represented by linked lists | Set 2
October 20, 2012

Given two numbers represented by two linked lists, write a function that returns sum list. The sum list is
linked list representation of addition of two input numbers. It is not allowed to modify the lists. Also, not
 allowed to use explicit extra space (Hint: Use Recursion).

Example

Input:
  First List: 5->6->3  // represents number 563
  Second List: 8->4->2 //  represents number 842
Output
  Resultant list: 1->4->0->5  // represents number 1405
 *
 *
 */


/*
 *  Solution :-
 *   Following are the steps.
1) Calculate sizes of given two linked lists.
2) If sizes are same, then calculate sum using recursion. Hold all nodes in recursion call stack till the
 	 rightmost node, calculate sum of rightmost nodes and forward carry to left side.
3) If size is not same, then follow below steps:
….a) Calculate difference of sizes of two linked lists. Let the difference be diff
….b) Move diff nodes ahead in the bigger linked list. Now use step 2 to calculate sum of smaller list and right
	sub-list (of same size) of larger list. Also, store the carry of this sum.
….c) Calculate sum of the carry (calculated in previous step) with the remaining left sub-list of larger list.
 	 Nodes of this sum are added at the beginning of sum list obtained previous step
 */


#include<stdio.h>

#define abs(a) (((a)< 0) ? -(a) : (a))

struct node {
	int data ;
	struct node *next ;
	node(int x):data(x),next(NULL){};
};


void push(struct node **headRef, int x){

	struct node *new_node = new node(x);
	new_node->next = *headRef ;
	*headRef = new_node ;
}



void printList(struct node *head){

	while(head){
		printf("[ %d ]-->",head->data);
		head = head->next ;
	}
	printf("NULL\n");
}


void swap(struct node ** a , struct node **b){
	struct node *temp = *a ;
	*a = *b ;
	*b = temp;
}

int getSize(struct node *head){
	int size = 0;
	while(head){
		size++;
		head = head->next ;
	}
	return size ;
}


struct node* addListSameSize(struct node *l1 ,struct node *l2 ,int *carry){

	if(!l1)
		return NULL ;

	struct node *result = new node(0);

	result->next = addListSameSize(l1->next,l2->next,carry);

	int sum = l1->data + l2->data + *carry ;
	*carry = sum / 10 ;
	sum = sum % 10 ;
	result->data = sum ;
	return result ;
}



void carryToRemainingList(struct node *head , struct node *last , int *carry , struct node **resultRef){

   if(head != last){
	   carryToRemainingList(head->next ,last,carry,resultRef);
	   int sum = head->data + *carry ;

	   * carry = sum / 10 ;
	   sum = sum % 10 ;
	   push(resultRef , sum);
   }
}


struct node* addTwoList(struct node *l1 , struct node *l2 ){
  struct node *result = NULL ;
  int size1 = getSize(l1);
  int size2  = getSize(l2);
  int carry = 0 ;
  if(size1==size2){
	  result = addListSameSize(l1,l2,&carry);
  }
  else
  {
	  if(size1 < size2)
	  {
		  swap(&l1,&l2);
	  }
	  int diff = abs(size1-size2);
	  struct node *cur = l1;
	  while(diff--){
         cur = cur->next ;
	  }

	  result = addListSameSize(cur,l2,&carry);

	  carryToRemainingList(l1,cur,&carry,&result);

  }
  if(carry)
	  push(&result,carry);
  return result ;
}

#define ARRAYSIZE(A)   (sizeof(A)/sizeof(A[0]))
struct node* createListFromArray(int *arr , int size){
	struct node *list = NULL ;
	for(int i = size-1 ; i>=0 ; --i){
		push(&list,arr[i]);
	}
	return list ;
}

void test_0_addList(){
	int arr2[] = {9,9,3,4,5} ;
	int arr1[] ={8,9,1} ;
	struct node *l1 = createListFromArray(arr1 , ARRAYSIZE(arr1));
	struct node *l2 = createListFromArray(arr2 , ARRAYSIZE(arr2));
	struct node *result = addTwoList(l1,l2);
	printf("l1 = \n");
	printList(l1);
	printf("l2 = \n");
	printList(l2);
	printf("sum = \n");
	printList(result);
}

int main(){

	test_0_addList();
	return 0 ;
}






