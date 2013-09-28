//to check a linked list is palindrome or not ??/
// we can use of the stack or just using the progrm stack 
// means to with help of the recursion u can check the 
// given linked list is the palindrome or not

//1. recursive method
#include <stdio.h>
struct node
{
	char info;
	struct node *next;
}*head=NULL;

void insert(char c)
{
	struct node *temp;
	if(!head)
	{
		head=(struct node*)malloc(sizeof(struct node));
		head->info=c;
		temp=head;
		temp->next=NULL;
		return;
	}
	temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=(struct node *)malloc(sizeof(struct node));
	temp=temp->next;
	temp->info=c;
	temp->next=NULL;
	return;
}

int isPalindrome(struct node *L,struct node **r)
{
	int c;
	if(L==NULL)
		return 1;

	c=isPalindrome(L->next,r);
	if(c==0)
		return 0;
	if(L->info==(*r)->info)
	{
		*r=(*r)->next;
		return 1;
	}
	return 0;
}

int main(void)
{
	int c;
	char s[100],*t;
	struct node *head1,*head2;
	puts("enter the string for palindrome check");
	gets(s);
	t=s;
	while(*t!='\0')
	{
		insert(*t);
		t++;
	}
	head1=head;
	head2=head;
	c=isPalindrome(head1,&head2);
	if(c==1)
		printf("Palindrome");
	else
		printf("NOT palindrome");
	return 0;

}
