
#include"list.h"



ListNode* kReverse(ListNode *head ,int k){
	ListNode *pre ,*current,*next  ;
	int count ;
	current = head ;

	pre = NULL ;
	count = k;

	while(current != NULL && count){
		next = current->next ;
		current->next = pre ;
		pre = current ;
		current = next ;
		count--;
	}
	if(head)
		head->next = current ;
	return pre;
}

ListNode* kAltReverse(ListNode* head ,int k){

	ListNode *current = head ,*pre ,*new_head ;
	int count = k ,set =0;
	pre=NULL ;
	while(current){

		if(!set){
			new_head =kReverse(current,k);
			pre=current ;
			set = 1;
		}
		else
		{
			pre->next = kReverse(current,k) ;
		}

		count = k ;
		while(current != NULL && count){
			current=current->next;
			count--;
		}
		if(current){
			pre = current ;
			current = current->next;
		}
	}
	return new_head ;
}

ListNode* kReverseGroup(ListNode* head , int k){
	ListNode *current = head ,*pre ,*new_head=NULL ;
	int count = k ,set =0;
	pre=NULL ;
	while(current){
		count = k ;
		ListNode *start = current;
		 // check list have k node
		while(start && count){
			start = start->next ;
			count-- ;
		}

		if(count==0){
			if(!set){
				new_head =kReverse(current,k);

				set = 1;
			}
			else
			{
				pre->next = kReverse(current,k) ;
			}

			pre = current ;
			current = current->next;
		}
		else
		{
			break ;
		}
	}
	return new_head ;
}

// kAlternate test

void test_0_kAltReverse(){
	int arr [] ={1,2,3,4,5,6,7,8,9,10} ;
	int k ;
	ListNode *head = getListFromArray(arr,ARRAYSIZE(arr));
	printList(head);
	head = kAltReverse(head,2);
	printList(head);
}

void test_1_kAltReverse(){
	int arr [] ={1,2,3,4,5,6,7,8,9,10} ;
	int k ;
	ListNode *head = getListFromArray(arr,ARRAYSIZE(arr));
	printList(head);
	head = kAltReverse(head,1);
	printList(head);
}

void test_2_kAltReverse(){
	int arr [] ={1,2,3,4,5,6,7,8,9,10} ;
	int k ;
	ListNode *head = getListFromArray(arr,ARRAYSIZE(arr));
	printList(head);
	head = kAltReverse(head,3);
	printList(head);
}

// kGroup test
void test_0_kReverseGroup(){
	int arr [] ={1,2,3,4,5,6,7,8,9,10} ;
	int k ;
	ListNode *head = getListFromArray(arr,ARRAYSIZE(arr));
	printList(head);
	head = kReverseGroup(head,2);
	printList(head);
}

void test_1_kReverseGroup(){
	int arr [] ={1,2,3,4,5,6,7,8,9,10} ;
	int k ;
	ListNode *head = getListFromArray(arr,ARRAYSIZE(arr));
	printList(head);
	head = kReverseGroup(head,1);
	printList(head);
}

void test_2_kReverseGroup(){
	int arr [] ={1,2,3,4,5,6,7,8,9,10,11} ;
	int k ;
	ListNode *head = getListFromArray(arr,ARRAYSIZE(arr));
	printList(head);
	head = kReverseGroup(head,3);
	printList(head);
}


int main(){
	//	test_0_kAltReverse();
	//	test_1_kAltReverse();
	//    test_2_kAltReverse();


	test_0_kReverseGroup();
	test_1_kReverseGroup();
	test_2_kReverseGroup();

	return 0 ;
}
