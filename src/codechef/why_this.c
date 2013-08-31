#include<stdio.h>
#define get(in) scanf("%d",&in);
#define put(op) printf("%d\n",op);
#include <stdio.h>
#include <malloc.h>

struct node
{
  int info;
  struct node *link;
}*last;
void create_list(int num)
{
  struct node *q,*tmp;
  tmp= malloc(sizeof(struct node));
  tmp->info = num;

  if(last == NULL)
  {
    last = tmp;
    tmp->link = last;
  }
  else
  {
    tmp->link = last->link; /*added at the end of list*/
    last->link = tmp;
    last = tmp;
  }
}/*End of create_list()*/

void del(struct node *q)
{
  struct node *tmp;
  if( q->link == last)  /*Only one element*/
  {
    tmp = last;
    q->link = last->link;
    last=q;
    free(tmp);
    return;
  }
  else{
  tmp = q->link;
  q->link = tmp->link;
  free(tmp);
  return;
  }

}

void display()
{
  struct node *q;
  if(last == NULL)
  {
    printf("List is empty\n");
    return;
  }
  q = last->link;
  printf("List is :\n");
  while(q != last)
  {
    printf("%d ", q->info);
    q = q->link;
  }
  printf("%d\n",last->info);
}/*End of display()*/
int main()
{
    int t,i,n,j,m;
    struct node *st,*p2;
    get(t);
    printf("{");
    while(t--){
        free(last);
        last=NULL;
        //ct=2;
        scanf("%d",&n);
      for(i=1; i<=n ;i++)
      {
        create_list(i);
      }
      p2=last;
      st=last->link;
      for(i=1; i<n ;i++)
      {



         for(j=1;j<i;j++){
             p2=st;
             st=st->link;
          }
        // ct++;
          st=st->link;

          //printf("st:%d\n",st->info);
          //printf("p2:%d\n",p2->info);
          del(p2);
           //display();


          // del(p2);
          //printf("p:%d\n",st->info);

       // create_list(st+i);
      }

      printf("%d ,",last->info);

    }
    printf("}");
    return 0;
}
