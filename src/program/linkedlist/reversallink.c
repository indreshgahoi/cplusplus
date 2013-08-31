#define NULL 0
struct node
{
int item;
struct node* next;
}*start;
struct node* simplereverse(struct node *star);
struct node* groupreverse(struct node* star,int size);
struct node* recrev(struct node *star);
int main()
{
struct node *s,*p,*q;
struct node *rev;
int ch;
s=(struct node*)malloc(sizeof(struct node));
start=s;
s->item=1;
start->next=(struct node*)malloc(sizeof(struct node));
p=start->next;
p->item=2;
q=(struct node*)malloc(sizeof(struct node));
p->next=q;
p=q;
p->item=3;
s=(struct node*)malloc(sizeof(struct node));
p->next=s;
p=s;
p->item=4;
s=(struct node*)malloc(sizeof(struct node));
p->next=s;
s->item=5;
s->next=NULL;
while(1)
{
printf("what u want baby:");
printf("1.:simplereverse");
printf("2.groupreverse");
printf("3.exit");
scanf("%d",&ch);
if(ch==3)
exit(0);
else if(ch==1)
{
start=simplereverse(start);
rev=start;
while(rev!=NULL)
{
printf("%d",rev->item);
rev=rev->next;
}
}
if(ch==4)
{
start=recrev(start);
rev=start;
while(rev!=NULL)
{
printf("%d",rev->item);
rev=rev->next;
}}
else
{
start=groupreverse(start,2);
rev=start;
while(rev!=NULL)
{
printf("%d",rev->item);
rev=rev->next;
}}
}}
struct node* simplereverse(struct node *star)
{
struct node *p;
struct node *q;
struct node *r;
p=start;
q=p->next;
p->next=NULL;
r=q->next;
q->next=p;
p=q;
q=r;
r=r->next;
while(q!=NULL)
{
q->next=p;
p=q;
q=r;
if(r!=NULL)
{
r=r->next;
}}
return(p);
}

struct node* groupreverse(struct node* star,int size)
{
struct node *q;
struct node *r=NULL;
while(start)
{
struct node *next;
struct node *prev=NULL;
struct node *p=start;
int count=size;
while(start && count--)
{
next=start->next;
start->next=prev;
prev=start;
start=next;
}
if(!r)
{
r=prev;
}
else
{
q->next=prev;}
q=p;

}
return(r);
}

struct node* recrev(struct node *star)
{
struct node *temp;
if(star==NULL||star->next==NULL)
{
return(star);
}
temp=recrev(star->next);
star->next->next=star;
star->next=NULL;

return(temp);


}



