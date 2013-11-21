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
  struct node *tmp;
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


int main()
{
    int t,i,n,j;
    struct node *st,*p2,*tmp;
    get(t);
    while(t--){
        free(last);
        last=NULL;
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
          st=st->link;

if( p2->link == last)  /*Only one element*/
  {
    tmp = last;
    p2->link = last->link;
    last=p2;
    free(tmp);

  }
  else{
  tmp = p2->link;
  p2->link = tmp->link;
  free(tmp);
  }

      }

      printf("%d\n",last->info);

    }
    return 0;
}
