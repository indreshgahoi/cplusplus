/*
 * CircularLinkedList.cpp
 *
 *  Created on: Apr 24, 2013
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<cstdio>
#include<sstream>
#include<vector>
#include<algorithm>
#include <string>
#include <cstring>
#include <assert.h>
#include<climits>


#define null (NULL)
typedef int Key;

struct CircularLinkedListNode{
  	Key data;
  	CircularLinkedListNode *next;
friend std::ostream& operator<<(std::ostream& out,CircularLinkedListNode *node){
	if(!node){
		out<<"[NULL]"<<std::endl;
	}
	else{
		out<<"[add=("<<node<<") data="<<node->data<<"]"<<std::endl;
	}
	return out;
}

};


typedef CircularLinkedListNode* CllNode;


// CLL Utility Function
CllNode getNode(Key new_data){
	CllNode cllNode=(CllNode) malloc(sizeof(CircularLinkedListNode));
	cllNode->next=null;
	cllNode->data=new_data;
	return cllNode;
}

void push(CllNode *head_ref,Key new_data){
	CllNode cllNode=getNode(new_data);
	cllNode->next=*head_ref;
	*head_ref=cllNode;
}

CllNode buildListByString(std::string *elements){
 CllNode cllNode=null;
 CllNode *last=&cllNode;


  while(true){
	  if(*elements=="null" || *elements=="NULL")
	  break;
     Key k=atoi((*elements).c_str());
     push(last,k);
     last=  &((*last)->next);
     elements++;
  }
  (*last)=cllNode;
 return cllNode;


}

void printList(CllNode cll){
	if(!cll){ printf("List=[empty]\n"); return;}
	CllNode current=cll;
	printf("list=");
  do{
		printf("[%d]->",current->data);
		current=current->next;
	}while(current!=cll);
	printf("\n");
}

void inserIntoSortedLinkedList(CllNode *cll,Key new_data);
CllNode getLastNodeOfCLL(CllNode cll);
std::vector<CllNode> splitIntoTwpHalf(CllNode cll);

CllNode getLastNodeOfCLL(CllNode cll){
	if(!cll) return null;
	CllNode current=cll;
	while(current->next!=cll)
		current=current->next;
	return current;
}

void inserIntoSortedLinkedList(CllNode *cll,Key new_data){

	CllNode new_node=getNode(new_data);
	//Case1 list is Empty
	if(!(*cll)){
		*cll=new_node;
		new_node->next=new_node;
	}
	//Case where new_node insert just Before to the head
	else if(new_node->data<=(*cll)->data)  {
		CllNode last=getLastNodeOfCLL(*cll);
		new_node->next=*cll;
		*cll=new_node;
		last->next=new_node;
	}
	else{
		//current->next!=(*cll) condition need to break the loop when node is inserted to the after the last node
		CllNode current=*cll;
		while(new_node->data>current->next->data && current->next!=(*cll)){
			current=current->next;
		}
		new_node->next=current->next;
		current->next=new_node;
	}


}

std::vector<CllNode> splitIntoTwpHalf(CllNode cll){

	CllNode fHalf=null,sHalf=null;
	std::vector<CllNode> res;
	if(!cll){return res; }
	CllNode fast=cll,slow=cll;
    while(fast->next!=cll && fast->next->next!=cll){
       fast=fast->next->next;
       slow=slow->next;
    }
    // if even no of node
    if(fast->next->next==cll){
    	fast=fast->next;
    }
    fHalf=cll;
    if(cll->next!=cll)
    sHalf=slow->next;
    fast->next=slow->next;
    slow->next=cll;
    res.push_back(fHalf);
    res.push_back(sHalf);
    return res;
}


void testCaseForCLLClist(){
	std::string elements[]={"1","2","4","5","null"};
    CllNode cll=buildListByString(elements);
    inserIntoSortedLinkedList(&cll,0);
    printList(cll);
    inserIntoSortedLinkedList(&cll,3);
    printList(cll);
    inserIntoSortedLinkedList(&cll,6);
    printList(cll);
}

void testCaseForSplitCll(){
	std::string elements[]={"1","2","3","4","5","6","7","8","9","null"};
	std::string elements1[]={"1","2","3","4","null"};
	CllNode cll=buildListByString(elements1);
	printList(cll);
	std::vector<CllNode>ans=splitIntoTwpHalf(cll);
	printList(ans[0]);
	printList(ans[1]);
}

int main(){

	//testCaseForCLLClist();
	testCaseForSplitCll();
	return 0;
}


