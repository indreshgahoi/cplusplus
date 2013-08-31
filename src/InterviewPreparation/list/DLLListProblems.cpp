/*
 * DLLListProblems.cpp
 *
 *  Created on: Apr 24, 2013
 *      Author: Indresh Gahoi
 */



#include<iostream>
#include<cstdio>
#include<vector>
#include<climits>
#include<algorithm>
#include<assert.h>
#include<string>
#include <cstring>
using namespace std;

typedef int Key;

template<typename T>
void swap(T *a,T *b){
	T temp=*a;
	*a=*b;
	*b=temp;
}

struct DLLNode{
	Key data;
	DLLNode *previous;
	DLLNode *next;
};

typedef DLLNode* DllNode;
#define null (NULL)

DllNode getNode(Key new_data){
     DllNode	dllNode=(DllNode) malloc(sizeof(DLLNode));
     dllNode->data=new_data;
     dllNode->previous=null;
     dllNode->next=null;
     return dllNode;
}

void deleteNode(DllNode *dll_ref,DllNode del){

	if((*dll_ref)==NULL || del==NULL)
		 return;
	if((*dll_ref)==del){
		*dll_ref=del->next;
	}
	// set next and previous pointer
	if(del->next!=null)
		del->next->previous=del->previous;
	if(del->previous!=null)
		del->previous->next=del->next;
	free(del);
}

void push(DllNode *head_ref,Key new_data){
    DllNode dllNode=getNode(new_data);
    dllNode->next=(*head_ref);
    if((*head_ref))
    (*head_ref)->previous=dllNode;
    *head_ref=dllNode;
}

DllNode find(DllNode dll,Key k){
	DllNode res=null;

	while(dll){
		if(dll->data==k)
			return dll;
		dll=dll->next;
	}
	return res;
}

void printDLL(DllNode dll){
	printf("Dll=    \n");
    if(!dll){printf("[empty]");return;}
      printf("NULL<-");
     while(dll->next!=NULL){
	    printf("[%d]<->",dll->data);
	    dll=dll->next;
     }
     printf("[%d]->NULL\n",dll->data);

}

DllNode buildDllBYString(char **e){
   DllNode dll=NULL;

    while(true){

    	if(strcmp(*e,"null")==0 || strcmp(*e,"NULL")==0){

    		break;
    	}
    	else{
    		Key k=atoi(*e);
    		push(&dll,k);
    	}
       e++;

    }
    return dll;
}



void reverseDLL(DllNode *dll){

 if(!dll || (*dll)->next==NULL) return;  // handle empty or only node in the Dlllist

 DllNode current=*dll;
 while(true){
	 swap(&(current->next),&(current->previous));
	 if(current->previous==NULL){
		 *dll=current;
		 break;
	 }
	 current=current->previous;
 }


}


void reverseDLLTestCase(){

   char *elms[]={"1","2","3","4","5","null"};

   DllNode dll=buildDllBYString(elms);
   printDLL(dll);
   reverseDLL(&dll);
   printDLL(dll);
}

void testCaseFordeleteNode(){
	char *elms[]={"1","2","3","4","5","null"};

	   DllNode dll=buildDllBYString(elms);
	   printDLL(dll);
	   DllNode del=find(dll,4);
	   deleteNode(&dll,del);
	   printDLL(dll);
}



int main(){
	//reverseDLLTestCase();
	testCaseFordeleteNode();
	return 0;
}




