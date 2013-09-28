#define NULL 0

struct Node{
	int item;
	struct Node *next;
}*start;

void insert(int i);
void bubblesort();

int main()
{
	int i;
	struct Node *temp;

	for(i=5;i>=1;i--)
	{
		insert(i);
	}
	bubblesort();
	temp=start;
	while(temp!=NULL)
	{
		printf("%d\n",temp->item);
		temp=temp->next;
	}
	return(0);
}

void insert(int i)
{
	struct Node *temp;
	if(i==5)
	{
		start=(struct Node*)malloc(sizeof(struct Node));
		start->item=i;
		temp=start;
	}
	else
	{
		temp->next=(struct Node*)malloc(sizeof(struct Node));
		temp=temp->next;
		temp->item=i;
		temp->next=NULL;
	}
}

void bubblesort()
{
	int count=0;
	int i;
	int t=0;
	struct Node *star;
	struct Node *temp;

	star=start;
	temp=start;

	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}

	for(i=1;i<=count;i++)
	{
		star=start;
		while(star->next!=NULL)
		{
			if((star->item)>((star->next)->item))
			{
				t=star->item;
				star->item=(star->next)->item;
				(star->next)->item=t;
				star=star->next;
			}
			else
			{
				star=star->next;
			}
		}
	}
}
