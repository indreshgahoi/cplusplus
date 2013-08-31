/*
 * CopyLinkedListHavingArbitPointer.cpp
 *
 *  Created on: Apr 20, 2013
 *      Author: root
 */
#include<iostream>
#include <cstdio>
#include<sstream>
#include <alloca.h>
#include <malloc.h>
#include <vector>
#include<map>
#include<assert.h>
using namespace std;

typedef int data;

struct ListNodeWithArbitPointert{
 	data val;
 	ListNodeWithArbitPointert *next;
 	ListNodeWithArbitPointert *random;
    friend std::ostream& operator<<(std::ostream& out,ListNodeWithArbitPointert *node){
    	if(node==NULL){
    		out<<"[NULL]";

      }else{
    	  void *p1=node->next,*p2=node->random,*n=node;
    	  out<<"[ val("<<n<<")="<<node->val<<" next("<<p1<<")=";
    	  if(node->next)
    		  out<<node->next->val;
    	  else
    		  out<<"    NULL";

    	  out<<" random("<<p2<<")="<<node->random->val<<"]"<<std::endl;
      }
    	return out;
    }
};

void push(ListNodeWithArbitPointert **head_ref,data new_data,ListNodeWithArbitPointert *random){

 ListNodeWithArbitPointert *new_node=(ListNodeWithArbitPointert *)malloc(sizeof(ListNodeWithArbitPointert));
 new_node->val=new_data;
 new_node->next=(*head_ref);
 new_node->random=random;
 (*head_ref)=new_node;
}

void printList(ListNodeWithArbitPointert *start){

	for(ListNodeWithArbitPointert *current=start;current;current=current->next){
		std::cout<<current;
	}
}

ListNodeWithArbitPointert* copy(ListNodeWithArbitPointert *list){

	// O->C
	map<ListNodeWithArbitPointert*,ListNodeWithArbitPointert*> originalToCopy;

	ListNodeWithArbitPointert *copyList=NULL;
	ListNodeWithArbitPointert *previous=NULL;

	for(ListNodeWithArbitPointert *start=list;start!=NULL;start=start->next){
		//original.insert(make_pair(start,start->random));
		ListNodeWithArbitPointert *temp=(ListNodeWithArbitPointert *)malloc(sizeof(ListNodeWithArbitPointert));
		temp->val=start->val;
		temp->random=NULL;
		temp->next=NULL;
		if(copyList==NULL)
			copyList=temp;
		else{
			previous->next=temp;
		}

		previous=temp;
       originalToCopy.insert(make_pair(start,temp));
	}

  // code for setting RandomPointer
	ListNodeWithArbitPointert *current=copyList;
   for(ListNodeWithArbitPointert *start=list;start!=NULL;start=start->next){
	   current->random=originalToCopy[start->random];

       assert(current->random!=NULL);
	   current=current->next;
     }
 return copyList;
}

ListNodeWithArbitPointert* copy2(ListNodeWithArbitPointert *list){



	ListNodeWithArbitPointert *copyList=NULL;


	for(ListNodeWithArbitPointert *start=list;start!=NULL;){

		ListNodeWithArbitPointert *temp=(ListNodeWithArbitPointert *)malloc(sizeof(ListNodeWithArbitPointert));
		temp->val=start->val;
		temp->random=NULL;
		temp->next=start->next;
		start->next=temp;
		start=temp->next;

    }

  //set random pointer
  copyList=(list)?list->next:NULL;
   for(ListNodeWithArbitPointert *start=list;start!=NULL;){
	   start->next->random=(start->random!=NULL)?start->random->next:NULL;
	   start=start->next->next;

     }



   // restore list
   ListNodeWithArbitPointert *list1_curr=list;
   ListNodeWithArbitPointert *list2_curr=NULL;

   while(list1_curr!=NULL){
       list2_curr=list1_curr->next;
       list1_curr->next=list1_curr->next->next;
       if(list2_curr->next)
    	   list2_curr->next=list2_curr->next->next;
       list1_curr=list1_curr->next;
   }


 return copyList;
}






ListNodeWithArbitPointert * getNode(data val){
	ListNodeWithArbitPointert *p=(ListNodeWithArbitPointert *)malloc(sizeof(ListNodeWithArbitPointert));
	p->val=val;
	return p;
}




ListNodeWithArbitPointert* buildList(){

    ListNodeWithArbitPointert *p1=getNode(1)
    		,*p2=getNode(2),*p3=getNode(3),*p4=getNode(4),*p5=getNode(5);
    p1->next=p2;p1->random=p3;
    p2->next=p3;p2->random=p5;
    p3->next=p4;p3->random=p3;
    p4->next=p5;p4->random=p2;
    p5->next=NULL;p5->random=p3;
	return p1;
}


 void testCase(){
   ListNodeWithArbitPointert *list1=buildList();
   printList(list1);
   std::cout<<"copy list data"<<std::endl<<std::endl;
   ListNodeWithArbitPointert *list2=copy2(list1);
   printList(list2);
 }

int main(){
	testCase();
	return 0;
}






















