struct node *reverseatlk(struct node *head,int k)
{
struct *p,*q,*r;
struct node *h1=head;
int c=k;
p=head;
q=head->next;
while(q && c--)
{
r=q->next;
q->next=p;
p=q;
q=r;
}
if(!h1)
h1->next=q;
c=k;
while(c!=0)
{
q=q->next;
}

q->next=reverseatlk(q->next,k);
return(p);



}