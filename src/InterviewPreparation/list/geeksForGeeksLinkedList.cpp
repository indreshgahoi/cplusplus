/*
 * geeksForGeeksLinkedList.cpp
 *
 *  Created on: Apr 18, 2013
 *      Author: root
 */

#include<iostream>
#include<vector>
#include<cstdio>
#include<alloca.h>
#include <malloc.h>
#include <assert.h>
#include<string>
using namespace std;
typedef int Integer;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}


};

void      push(ListNode **head_ref ,int new_data);

void      printList(ListNode *head_ref);
void      deleteList(ListNode **haed_ref);

void      reverse(ListNode **head_ref);
void      insertIntoSortedList(ListNode **head_ref,Integer new_data);
void      removeDuplicates(ListNode* list);
void      removeDuplicatesFromUnsortedArrayI(ListNode* list);
void moveLastNodeToFront(ListNode** head_ref);
void pairwiseSwapElementsOfList(ListNode *head);
void deleteAlternative(ListNode *list);
ListNode* sortedMerge(ListNode* l1,ListNode* l2);
ListNode* intersectionInYShapedList(ListNode* list1,ListNode* list2);
ListNode* intersectionOfTwoSortedLinkedList(ListNode* list1,ListNode* list2);
ListNode* getNthNodeFromStart(ListNode *head,int index);
ListNode* getMiddleNodeI(ListNode *head);
ListNode* getMiddleNodeII(ListNode *head);
ListNode* getNthNodeFromLastI(ListNode *head,int n);
ListNode* getNthNodeFromLastII(ListNode *head,int n);
ListNode* getNode(int new_data);
ListNode* buildList(int method);
ListNode* buildListByString(string elements);
int countData(ListNode *head,int target);
int count(ListNode* head);
bool detectLoop(ListNode *list);
bool twoListAreIdentical(ListNode* list1,ListNode *list2);
bool isPalindrome(ListNode** left,ListNode *right );

template <typename T>
void swap(T *a,T *b){
	T temp=*a;
	*a=*b;
	*b=temp;
}


void push(ListNode **head_ref ,int new_data){
	ListNode *new_node=(ListNode *) malloc(sizeof(ListNode));
	new_node->val=new_data;
	new_node->next=(*head_ref);
   *head_ref=new_node;
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


int count(ListNode* head){
   int counter=0;
   for(;head;head=head->next)counter++;
   return counter;
}

ListNode* getNode(int new_data){
	ListNode* new_node=(ListNode*) malloc(sizeof(ListNode));
	new_node->val=new_data;
	new_node->next=NULL;
	return new_node;
}

ListNode* buildListByString(string elements){
ListNode* list=NULL;
int n=elements.size();
for(int i=n-1;i>=0;i--){
	push(&list,elements[i]-'0');

}
return list;
}

ListNode* buildList(int method){
	ListNode* list=NULL;
	switch (method) {
		case 1245: //sorted insert
			list=getNode(5);
				push(&list,4);
				push(&list,2);
				push(&list,1);
				return list;

			break;
		case 0:// empty list;
			list=NULL;
			break;
		case 1:
			list=getNode(1);
			break;
		case 12:
			list=getNode(2);
			push(&list,1);
			break;
		case 123:
			list=getNode(3);
			push(&list,2);
			push(&list,1);
			break;
		case 1234:
			list=getNode(4);
			push(&list,3);
			push(&list,2);
			push(&list,1);
			break;
		case 12345:
		    list=getNode(5);
		    push(&list,4);
		    push(&list,3);
			push(&list,2);
			push(&list,1);
			break;
		case 2345:
			list=getNode(5);
			push(&list,4);
			push(&list,3);
			push(&list,2);
			break;
		default:
			break;
	}
 return list;
}

void insertIntoSortedList(ListNode **head_ref, Integer new_data){

 ListNode **current=head_ref;

 while((*current)!=NULL && (*current)->val<new_data){
	 current= &((*current)->next);
 }
 ListNode *new_node=getNode(new_data);
 new_node->next=(*current);
 *current=new_node;

}



void reverse(ListNode **head_ref){
 ListNode *head=(*head_ref);
 // handle the baSE CASE EMPTY
 if(head==NULL) return;

 ListNode *rest=head->next;
 // HANDLE THE BASE CASE WHEN ONLY ONE NODE IN THE LIST
 if(!rest) return;
 reverse(&rest);

 head->next->next=head;
 head->next=NULL;
 (*head_ref)=rest;


}


void deleteList(ListNode **head_ref){

	ListNode *head=*head_ref;

	while(head){
	ListNode *temp=head;
		head=head->next;
	free(temp);
	}
	*head_ref=NULL;

}


void deleteAlternative(ListNode *list){

	if(!list || !list->next) return;

	while(list!=NULL && list->next!=NULL){
		ListNode *temp=list->next;
		list->next=list->next->next;
		free(temp);
		if(list)
		list=list->next;

	}

}



ListNode* getNthNodeFromStart(ListNode *head,int index){


	int counter=0;

	for(ListNode *iterator=head;iterator!=NULL;iterator=iterator->next,counter++)
		 if(counter==index) return iterator;
	 assert(0);
	ListNode *res=NULL;
	return res;

}


ListNode* getMiddleNodeI(ListNode *head){

	ListNode *fastNode=head;
	ListNode *slowNode=head;

	if(head!=NULL){
	while(fastNode->next!=NULL && fastNode->next->next!=NULL)
		fastNode=fastNode->next->next;
	    slowNode=slowNode->next;
	}
	return slowNode;

}

ListNode* getMiddleNodeII(ListNode *head){
	int counter=0;
	ListNode *mid=head;
	ListNode *current=head;

	while(current!=NULL){

		if(counter & 1)
			mid=mid->next;
		counter++;
		current=current->next;

	}

	return mid;
}

ListNode* getNthNodeFromLastI(ListNode *head,int n){
	static int i=0;
	// base case
	if(head==NULL) return head;
	 getNthNodeFromLastI(head->next,n);
	if(++i==n) return head;


}


ListNode* getNthNodeFromLastII(ListNode *head,int n){

 ListNode *ref_Pointer=head;
 ListNode *main_Pointer=head;

 if(head!=NULL){
	 int count=0;
	 while(count<n){
		 assert(ref_Pointer!=NULL);
		 ref_Pointer=ref_Pointer->next;
		 count++;
	 }
}

 while(ref_Pointer){
 		 ref_Pointer=ref_Pointer->next;
 		 main_Pointer=main_Pointer->next;
 }

 return main_Pointer;

}

/*
Write a function that counts the number of times a given int occurs
in a Linked List

*/

int countData(ListNode *head,int target){

	ListNode *current=head;
	int count=0;
	while(current){
		if(current->val==target)
			count++;
		current=current->next;
	}

	return count;
}
/*
Floyd’s Cycle-Finding Algorithm:

This is the fastest method. Traverse linked list using two pointers.
 Move one pointer by one and other pointer by two.  If these pointers
 meet at some node then there is a loop.  If pointers do not meet then
 linked list doesn’t have loop.

*/
bool detectLoop(ListNode *list){

	if(list==NULL) return false;

	ListNode* fastPointer=list;
	ListNode* slowPointer=list;

	while(fastPointer && fastPointer->next){
		slowPointer=slowPointer->next;
		fastPointer=fastPointer->next->next;
		if(slowPointer==fastPointer)
		{
			printf("Yes, There is a Loop");
			return true;
		}
	}
     return false;
}

ListNode* __intersectionInYshapedList(ListNode* list1,ListNode* list2,int d){

 while(d--){
	list1=list1->next;
 }
 while(list1 && list2){
	 if(list1==list2)
		 return list1;
	 list1=list1->next;
	 list2=list2->next;
 }
 return NULL;
}


ListNode* intersectionInYShapedList(ListNode* list1,ListNode* list2){
  int count1=count(list1);
  int count2=count(list2);
  ListNode *res=NULL;
  if(count1>count2)
  {
	  res=__intersectionInYshapedList(list1,list2,count1-count2);
  }
  else{
	  res=__intersectionInYshapedList(list2,list1,count2-count1);
  }
 return res;
}



ListNode* intersectionOfTwoSortedLinkedList(ListNode* list1,ListNode* list2){

	ListNode *result=NULL;
	ListNode** lastPtrRef=&result;

	while(list1!=NULL && list2!=NULL){
	   if(list1->val<list2->val){
		   list1=list1->next;
	   }
	   else if(list2->val<list1->val){
		   list2=list2->next;
	   }
	   else{
		   push(lastPtrRef,list1->val);
		   lastPtrRef= &(*lastPtrRef)->next;
		   list1=list1->next;
		   list2=list2->next;
	   }

	}
	return result;
}


void removeDuplicates(ListNode* list){

 ListNode *current=list;

 //Handle emptyCase
 if(!current) return;

 ListNode* next_next=NULL;

 while(current->next!=NULL){

   if(current->val==current->next->val){
	   next_next=current->next->next;
	   free(current->next);
	   current->next=next_next;
   }
   else{
	   current=current->next;
   }

 }

}



void removeDuplicatesFromUnsortedArrayI(ListNode* list){


	for(ListNode* i=list;i!=NULL && i->next!=NULL;i=i->next){

	 for(ListNode* j=i;j->next!=NULL;){

	    if(i->val==j->next->val){
	    	ListNode *temp=j->next;
	    	j->next=j->next->next;
	    	free(temp);
	    }
	    else{
	    	j=j->next;
	    }

	 }

	}


}

bool twoListAreIdentical(ListNode* list1,ListNode *list2){


   while(true){
	   if(list1==NULL && list2==NULL)
		   return true;
	   if(list1!=NULL && list2==NULL)
		   return false;
	   if(list2!=NULL && list1==NULL)
	   		   return false;
	   if(list1->val!=list2->val)
		   return false;
	   list1=list1->next;
	   list2=list2->next;
   }
   return false;
}




void testCaseForRemoveDuplicatesFprUnSorted(){
	ListNode *list=buildListByString("54325411223");//"54325411223"
	printList(list);
	removeDuplicatesFromUnsortedArrayI(list);
	printList(list);
}


void testCaseForRemoveDuplicates(){
	ListNode *list=buildListByString("112223344455");
	printList(list);
	removeDuplicates(list);
	printList(list);
}


bool isPalindrome(ListNode** left,ListNode *right ){
   //Handle Base Case
   if(!right) return true;

   bool isSubListPalindrome=isPalindrome(left,right->next);

   if(!isSubListPalindrome)
	   return false;
   if(!((*left)->val==right->val))
	return false;
   else{
	  (*left)=(*left)->next;
	   return true;
    }
}

void moveLastNodeToFront(ListNode** head_ref){
	if(!(*head_ref)) return;
	ListNode** last=head_ref;

	while((*last)->next!=NULL)
		last=&((*last)->next);

	(*last)->next=*head_ref;

	*head_ref=*last;
	*last=NULL;

}


void pairwiseSwapElementsOfList(ListNode *list){

	while(list!=NULL && list->next!=NULL){

		swap(&list->val,&list->next->val);
		list=list->next->next;
	}

}


ListNode* sortedMerge(ListNode* l1,ListNode* l2){

	ListNode* result=NULL;
	ListNode** lastPtrRef=&result;

	while(l1 && l2){
		if(l1->val<l2->val){
			*lastPtrRef=l1;
			l1=l1->next;
		}
		else{
			*lastPtrRef=l2;
			 l2=l2->next;
		}
		lastPtrRef=&(*lastPtrRef)->next;
	}
    if(l1)
    	*lastPtrRef=l1;
    else
    	*lastPtrRef=l2;
    return result ;
}

void TestCaseForsortedInsert(){
	ListNode *list=buildList(2345);
	printList(list);
	insertIntoSortedList(&list,1);
	printList(list);
}

void YShapedtestCase(){
	ListNode *p1=getNode(1),*p2=getNode(2),*p3=getNode(3),
			*p4=getNode(4),*p5=getNode(5),*p6=getNode(6),*p7=getNode(7),*p8=getNode(8),*p9=getNode(9);
    ListNode *p11=getNode(11),*p12=getNode(12),*p13=getNode(13),*p14=getNode(14);
       p1->next=p2; p11->next=p12;
       p2->next=p3; p12->next=p13;
       p3->next=p4; p13->next=p14;
       p4->next=p5; p14->next=p5;
       p5->next=p6;
       p6->next=p7;
       p7->next=p8;
       p8->next=p9;

      printList(p1);
      printList(p11);
      printList(intersectionInYShapedList(p1,p11));

}

void testCaseFormoveLastNodeToFront(){

	ListNode* list=buildList(12345);
	printList(list);
	moveLastNodeToFront(&list);
	printList(list);
}

void testCaseForPairWiseSwap(){
	ListNode* list=buildList(12345);
		printList(list);
		pairwiseSwapElementsOfList(list);
		printList(list);
}

void testCaseForintersectionTwoSortedArray(){
	ListNode *list1=buildListByString("1244455678");
	ListNode *list2=buildListByString("12344689");
		printList(list1);
		printList(list2);
   ListNode *intersection=intersectionOfTwoSortedLinkedList(list1,list2);
   printf("Intersection=\n");
   printList(intersection);
}

void testForAlterNateDelete(){
	ListNode *list=buildListByString("1234");
	printList(list);
	deleteAlternative(list);
	printList(list);
}

void testForSortedMerge(){
	ListNode *l1=buildListByString("579");
	ListNode *l2=buildListByString("12348");
	printList(l1);
	printList(l2);
	ListNode *result=sortedMerge(l1,l2);
	printList(result);

}
int main(){
	//TestCaseForsortedInsert();
    // YShapedtestCase();
	//testCaseForRemoveDuplicates();
	//testCaseForRemoveDuplicatesFprUnSorted();
	//testCaseFormoveLastNodeToFront();
	//testCaseForPairWiseSwap();
	//testCaseForintersectionTwoSortedArray();
	//testForAlterNateDelete();
	testForSortedMerge();
 return 0;
}









