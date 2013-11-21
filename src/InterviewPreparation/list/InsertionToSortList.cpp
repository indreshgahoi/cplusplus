/*
 * InsertionToSortList.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/list/InsertionToSortList.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 21, 2013
 *      Author: Indresh Gahoi
 */

#include "list.h"
/*
Link :-  
Question :-

 */
class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {

		if(head==0 || head->next==0) return head ;
		ListNode start(-1) ;
		start.next = head ;
		ListNode *nodeToInsert=head->next ,*pre ;
		head->next = NULL ;
		while(nodeToInsert)
		{
            pre = &start ;
			ListNode  *curr = start.next ;
			while(curr!=0 && curr->val < nodeToInsert->val )
			{
				pre=curr;
				curr = curr->next ;

			}
			printList(start.next);
			ListNode *next = nodeToInsert->next ;
			nodeToInsert->next = pre->next ;
			pre->next = nodeToInsert ;
			nodeToInsert = next;
		}
		return start.next ;
	}
};


void driver()
{
	ListNode *list ;
	int arr[] = {5,4,3,2,8,1};
	//int arr[] = {4,2,1,3} ;
	list = getListFromArray(arr,ARRAYSIZE(arr));
	printList(list);
	Solution solve ;
	list = solve.insertionSortList(list);
	printList(list);
}
/*
 input.txt 

 */
int main(){
	driver();
	cout<<"\n";
	return 0;
}
