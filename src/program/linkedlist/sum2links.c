#define NULL 0
struct node
{
// its really gud program toadd the two linked list without reversing them at all :)

int value;
struct node *next;
};
struct node *head1=NULL;
struct node *head2=NULL;

int AddtwoNumbers(struct node *l1,struct node *l2,int v1,int v2)
{

if(!l1 && !l2)
return v1+v2;
if(l1 && !l2)
v1=v1*10+l1->value;
if(!l1 && l2)
v2=v2*10+l2->value;
if(l1 && l2)
{
v1=l1->value+v1*10;
v2=l2->value+v2*10;
}
if(l1)
l1=l1->next;
if(l2)
l2=l2->next;

return(AddtwoNumbers(l1,l2,v1,v2));

}

int main(int argc,char **argv)
{

int sum=0;
struct node *temp,*temp2;
temp=(struct node*)malloc(sizeof(struct node));
head1=temp;
temp->value=1;
temp->next=(struct node*)malloc(sizeof(struct node));
temp->next->value=3;
temp=temp->next;
temp->next=(struct node*)malloc(sizeof(struct node));
temp->next->value=4;
temp=temp->next;
temp->next=(struct node*)malloc(sizeof(struct node));
temp->next->value=5;
temp->next->next=NULL;
temp=(struct node*)malloc(sizeof(struct node));
temp2=(struct node*)malloc(sizeof(struct node));
temp2->value=2;
head2=temp2;
temp2->next=(struct node*)malloc(sizeof(struct node));
temp2->next->value=5;
temp2->next->next=NULL;
sum=AddtwoNumbers(head1,head2,0,0);
printf("%d",sum);


}
