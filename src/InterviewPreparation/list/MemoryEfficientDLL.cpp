/*
 * MemoryEfficientDLL.cpp
 *
 *  Created on: Apr 21, 2013
 *      Author: Indresh Gahoi
 */

/*
 *  http://www.linuxjournal.com/article/6828?page=0,0
 */

#include<iostream>
#include<cstdio>
#include<alloca.h>
#include<malloc.h>

#define null (NULL)
typedef  int Key;
struct listNode{
	Key val;
	listNode *diff;
	listNode * next(listNode *pre){
		return (listNode*)((int) this->diff ^ (int) pre);
	}
};

typedef listNode* Node;






Node list=null;

void printList(Node list){
Node pre=null;
Node current=list;
Node next;
   printf("[");
   while(current){
	   next=current->next(pre);
	   printf("(%d),",current->val);
	   pre=current;
	   current=next;
   }
  printf("]\n");
}

Node getNode(Key new_val){
	Node p=(Node) malloc(sizeof(listNode));
	p->val=new_val;
	p->diff=NULL;
	return p;
}


void insert(Node new_node,Key elm){

Node pre=null;
Node current=list;
Node next;
   while(current){
	   next=current->next(pre);
	   if(current->val==elm){

          new_node->diff=(Node)((int)current^(int)(next));
          if(next){
            next->diff=(Node)((int)next->diff^(int)current^(int) new_node);
          }
          current->diff=(Node)((int)current->diff^(int)(next)^(int)new_node);



	    break;
	   }
	   pre=current;
	   current=next;
   }

}

void buildList(){
 list=getNode(1);
 Node p1=getNode(5);
 list->diff=(Node)((int)null^(int)p1);
 p1->diff=(Node)((int)null^(int)list);
 printList(list);
 Node p2=getNode(3),p3=getNode(2),p4=getNode(4),p5=getNode(6);
 insert(p2,1);
 insert(p3,1);
 insert(p4,3);
 insert(p5,5);
}

void testCase(){
	buildList();
	printList(list);

}



int main(){
	testCase();
	return 0;
}








