#include<iostream>
#include<cstdio>
#include<vector>
#include<list>
#include<queue>

using namespace std;

struct node
{
    int sum;
    int mul;
    //int id;
    //int num;
    //struct node *parent;
    struct node *child[10];
   // struct node *next;
}*tree;

queue<struct node*> myqueue1,myqueue2,&myqueue3=myqueue1,&myqueue4=myqueue2;

 struct lst
{
    struct node *p;
};

 lst list1[10];

void create(int d)
{
   int cnt=0;

    node *t=NULL;
    tree=new node;

    for(int i=1;i<=9;i++)
    {


      node* temp =tree->child[i]=new node;
      myqueue2.push(temp);
      temp->mul=i;
      temp->sum=i;
     // temp->id=i;
      //temp->num=i;
      //temp->parent=tree;
      //temp->next=NULL;
      //if(t!=NULL)
       //t->next=temp;
       //t=temp;

    }
   // list1[1].p=tree->child[1];
    //t->next=NULL;

    for(int i=2;i<=d;i++)
    { // cnt=0;
       // t=NULL;
        if(i & 1)
        {
            while(!myqueue1.empty())
        {
             node *temp=myqueue1.front();
             myqueue1.pop();
            for(int j=1;j<=9;j++)
            {
              node* temp1 =temp->child[j]=new node;
              myqueue2.push(temp1);
              temp1->mul=(temp->mul)*j;
              temp1->sum=(temp->sum)+j;
             // temp1->parent=temp;
              //temp1->id=j;
              //temp1->num=temp->num*10+j;
              //temp1->next=NULL;
             // cnt++;
              //printf("%d\n",temp1->num);
              if(temp1->mul%temp1->sum==0)
              { //cnt++;

                  //if(t==NULL)
                   // list1[i].p=temp1;
                  //if(t!=NULL)
                   //t->next=temp1;
                   //t=temp1;
              }
           }
        }

             //myqueue3=myqueue1;
            //myqueue4=myqueue2;
    }
        else
        {

            while(!myqueue2.empty())
        {
             node *temp=myqueue2.front();
             myqueue2.pop();
            for(int j=1;j<=9;j++)
            {
              node* temp1 =temp->child[j]=new node;
              myqueue1.push(temp1);
              temp1->mul=(temp->mul)*j;
              temp1->sum=(temp->sum)+j;
             // temp1->parent=temp;
              // temp1->id=j;
                //temp1->num=temp->num*10+j;
                 // printf("%d\n",temp1->num);
              //temp1->next=NULL;
             // cnt++;
              if(temp1->mul%temp1->sum==0)
              {
                //  cnt++;

                  //if(t==NULL)
                    //list1[i].p=temp1;
                  //if(t!=NULL)
                  // t->next=temp1;
                  // t=temp1;
              }
           }
        }

            //myqueue3=myqueue2;
            //myqueue4=myqueue1;
        }

       /* while(!myqueue3.empty())
        {
             node *temp=myqueue3.front();
             myqueue3.pop();
            for(int j=1;j<=9;j++)
            {
              node* temp1 =temp->child[j]=new node;
              myqueue4.push(temp1);
              temp1->mul=(temp->mul)*j;
              temp1->sum=(temp->sum)+j;
              temp1->parent=temp;
              temp1->next=NULL;
              if(temp1->mul%temp1->sum==0)
              { printf("\nhi");
                  if(t==NULL)
                    list1[i].p=temp1;
                  if(t!=NULL)
                   t->next=temp1;
                   t=temp1;
              }
           }
        }*/
       // printf("\n\n cnt=%d\n\n",cnt);
        //if(t!=NULL)
          //t->next=NULL;

    }

}



int main()
{
 int cnt=0;
  create(7);

 /* node * current;
  current=list1[7].p;
  while(current!=NULL)
  { cnt++;
      printf("%d %d %d\n",current->mul,current->sum,current->num);
      current=current->next;
  }
  printf("\n\n\n%d",cnt);*/


return 0;
}
