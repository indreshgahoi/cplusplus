// insertion sort in the singly linked list :)


struct node{
	struct node *data;
	struct node *next;
};
void InsertionSort(struct node *L)
{
	struct node *temp1,*temp2;
	int tempval;
	int key;

	if(!L||!(L->next))
		return ;
	temp1=L->next;
	while(temp1)
	{
		for(temp2=L;temp2->data<temp1->data && temp2!=temp1;temp2=temp2->next);
		if(temp2!=temp1)
		{
			key=temp2->data;
			temp2->data=temp1->data;
			temp2=temp2->next;
			while(temp2!=temp1)
			{
				tempval=temp2->data;
				temp2->data=key;
				key=tempval;
				temp2=temp2->next;
			}


			tempval=temp2->data;
			temp2->data=key;
			key=tempval;
			temp2=temp2->next;
		}
	}
}
