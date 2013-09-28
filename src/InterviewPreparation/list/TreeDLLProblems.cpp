/*
 * TreeDLLProblems.cpp
 *
 *  Created on: Apr 12, 2013
 *      Author: Indresh Gahoi
 */

#include<constant.h>


struct Node
{
	int data;
	Node *small;
	Node *large;
};


void printList(Node *head){

	Node *current=head;
	printf("DLL=[");
	while(current){
		printf("%d ,",current->data);

			current=current->large;
			if(current==head) break;

	}
	printf("]\n");
}

void __printTree(Node *root){

	if(root){
		__printTree(root->small);
		printf("%d ,",root->data);
		__printTree(root->large);
	}
}

void printTree(Node *root){
	printf("inorder traversl=[");
	__printTree(root);
	printf("]\n");

}

// join the two dll node
static void __join(Node *DLLa,Node *DLLb){
  DLLa->large=DLLb;
  DLLb->small=DLLa;
}

static Node * __append(Node *a,Node *b){
	if(!a)return b;
	if(!b) return a;

	Node *aLast=a->small;
	Node *bLast=b->small;
	__join(aLast,b);
	__join(bLast,a);

	return a;
}

Node * treeToDLL(Node *root){

	if(!root) return NULL;

	Node *leftDLL=treeToDLL(root->small);
	Node *rightDLL=treeToDLL(root->large);

	// make root as only node to DLL;
	root->small=root;
	root->large=root;
    leftDLL=__append(leftDLL,root);
    leftDLL=__append(leftDLL,rightDLL);

    return leftDLL;
}

void insertToTree(Node **root_ref,int new_data){
	 if(!(*root_ref)) {
		 Node *temp=new Node();
		 temp->data=new_data;
		 temp->small=NULL;
		 temp->large=NULL;
		 (*root_ref)=temp;

		return;
	 }
	 Node *root=(*root_ref);
	 if(new_data<=root->data){
		  insertToTree(&(root->small),new_data);
	 }
	 else{
		 insertToTree(&(root->large),new_data);
	 }

}
Node *tree=NULL;
void BuildTestTree(){
	insertToTree(&tree,5);
	insertToTree(&tree,8);
	insertToTree(&tree,4);
	insertToTree(&tree,3);
	insertToTree(&tree,5);
	insertToTree(&tree,1);
    insertToTree(&tree,9);
    insertToTree(&tree,10);
    insertToTree(&tree,6);
    insertToTree(&tree,7);
}

void treeToListTest(){

	BuildTestTree();
	printTree(tree);
    Node *DLL=treeToDLL(tree);
    printList(DLL);
}

void driver(){
	treeToListTest();
}
