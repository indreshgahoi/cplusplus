struct node
{
 int info;
 struct node *next;
}*h;


void Delete(struct node *key)
{
 struct node *temp;
 temp=start;
 if(temp==key)
 {
	  start=temp->next;
  free(temp);
 }
 while(temp->next!=key)
 temp=temp->next;
 temp->next->next=temp;
 free(key);
}

struct node *reverse(struct node *h)
{
 struct node *temp;
  if(!h||h->next==0)
 return(h);
 temp=reverse(h->next);
  h->next->next=h;
 h->next=0;
 return(temp);
}
struct node *deleteRight(struct node *h)
{
 int max=-32767;
 struct node *temp;
 h=reverse(h);
 temp=h;
 while(temp->next!=0)
 {
 if(max>temp->info)
	 Delete(temp);
 	 max=temp->info;
 }
 h=reverse(h);
 return(h);
}
