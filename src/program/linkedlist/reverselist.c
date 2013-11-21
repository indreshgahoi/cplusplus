#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct node
{
	int data;
	struct node* next;
};

/* Function to reverse the linked list */
static void reverse(struct node** head_ref)
{
	struct node* prev   = NULL;
	struct node* current = *head_ref;
	struct node* next;
	while (current != NULL)
	{
		next  = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}



void insafter(struct node** head_ref,int new_data ){


	struct node* current= *head_ref;
	/* allocate node */
	struct node* new_node =
			(struct node*) malloc(sizeof(struct node));

	/* put in the data  */
	new_node->data  = new_data;
	new_node->next=NULL;
	if(current==NULL){
		(*head_ref) =new_node;
	}
	else
	{
		while(current->next !=NULL)
			current=current->next;

		current->next=new_node;
	}
}

/* Function to push a node */
void push(struct node** head_ref, int new_data)
{
	/* allocate node */
	struct node* new_node =
			(struct node*) malloc(sizeof(struct node));

	/* put in the data  */
	new_node->data  = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref)    = new_node;
}

/* Function to print linked list */
void printList(struct node *head)
{
	struct node *temp = head;
	while(temp != NULL)
	{
		printf("%d  ", temp->data);
		temp = temp->next;
	}
}   

void recursiveReverse(struct node** head_ref)
{
	struct node* first;
	struct node* rest;

	/* empty list */
	if (*head_ref == NULL)
		return;

	/* suppose first = {1, 2, 3}, rest = {2, 3} */
	first = *head_ref;
	rest  = first->next;

	/* List has only one node */
	if (rest == NULL)
		return;

	/* put the first element on the end of the list */
	recursiveReverse(&rest);
	first->next->next  = first;

	/* tricky step -- see the diagram */
	first->next  = NULL;

	/* fix the head pointer */
	*head_ref = rest;
}

/* Drier program to test above function*/
int main()
{
	/* Start with the empty list */
	struct node* head = NULL;
	int ele;
	printf("Enter the element\n");
	while(scanf("%d",&ele)!=EOF){


		insafter(&head, ele);

	}
	printList(head);
	reverse(&head);
	printf("\n Reversed Linked list by non rerusive \n");
	printList(head);
	printf("\nReverse Linked list by recursive\n");
	recursiveReverse(&head);
	printList(head);
	getchar();
}



