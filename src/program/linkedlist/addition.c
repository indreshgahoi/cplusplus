struct node{
	int value;
	struct node*next;
};
struct node *reverse(struct node *head)
{
	struct node *temp;
	if(!head||head->next==0)
		return head;
	temp=reverse(head->next);
	head->next->next=head;
	head->next=0;
	return temp;
}


struct node *linkaddition(struct node *l1,struct node *l2)
{
	struct node *temp1=l1,*temp2=l2,*tempo,*temp;
	struct node *head=0;
	int carry=0,sum=0,p,k;
	if(!l1)
		return l2;
	if(!l2)
		return l1;
	l1=reverse(l1);
	l2=revere(l2);
	while(temp1 || temp2)
	{
		if(temp1)
		{
			k=temp1->value;
			temp1=temp1->next;
		}
		if(temp2)
		{
			p=temp2->value;
			temp2=temp2->next;
		}
		sum=p+k;
		if(carry)
			sum=sum+carry;
		if(sum>10)
		{
			sum=sum-10;
			carry=1;
		}
		else
		{
			carry=0;
		}
		temp=malloc(sizeof(struct node));
		if(!head)
		{
			head=temp;
			head->value=sum;
			head->next=0;
			tempo=head;
		}
		else
		{
			tempo->next=temp;
			tempo->next->value=sum;
			tempo=tempo->next;
			tempo->next=0;
		}
	}
	head=reverse(head);
	return head;
}
