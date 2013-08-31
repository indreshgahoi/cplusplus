#include<iostream>
#include<cassert>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#define N 50001
using namespace std;
typedef long long int LL;
typedef int I;

struct _list
{
    int id;
    struct _list *next;
};
_list *animal[N];
//bool animal[N][N];

int parent[N],rank1[N],L,fal=0;
int parent1[N],rank2[N];

void make_set1 (int v) {
	parent1[v] = -1;
	rank2[v]=0;
}

int find_set1 (int v) {
	if (v == parent1[v])
		return v;
	return parent1[v] = find_set1 (parent1[v]);
}

void union_sets1(int a,int b) {

	a = find_set1(a);
	b = find_set1(b);
	if (a != b) {
		if (rank2[a] < rank2[b])
			swap (a, b);
		parent1[b] = a;
		if (rank2[a] == rank2[b])
			++rank2[a];
	}
}

void make_set (int v) {
	parent[v] = -1;
	rank1[v]=0;
}

int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}

void union_sets(int a,int b) {

	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (rank1[a] < rank1[b])
			swap (a, b);
		parent[b] = a;
		if (rank1[a] == rank1[b])
			++rank1[a];
	}
}

void init() {

	for (int i=1; i<=L; ++i)
	{
	    make_set (i);
	    make_set1 (i);
	}
}

inline bool check(int x , int y)
{  //if(animal[x]!=NULL)
   for(_list* i=animal[x];i!=NULL;i=i->next)
       if(i->id==y)
     //  if(animal[x][y])
         return true;
   return false;
}
void list_combine(int x ,int y)
{
    _list* current=NULL;
 if(animal[x]==NULL)
 {
  animal[x]=animal[y];
  //cout<<"Hello"<<endl;
 }
 else{
     current=animal[x];

    while(current->next!=NULL)
        current=current->next;
       current->next=animal[y];
        }
 animal[y]=NULL;

 /*for(int i=1;i<=L;i++)
 {
     if(animal[y][i])
     {
         animal[x][i]=1;
         animal[y][i]=0;
     }

 }*/

}

void process_query (int l, int x, int y) {
  // int a=x,b=y;

    if(x>L || y>L){
     fal++;
     return;}

  //same kind x and y

	if(l==1)
	{
	    if(parent[x]==-1 || parent[y]==-1)
	    {
	        if(parent[x]==-1)
	         parent[x]=x;
	        if(parent[y]==-1)
	          parent[y]=y;
            list_combine(x,y);
            union_sets1(x,y);
	        union_sets(x,y);
	        return;
	    }

	    x=find_set(x);
	    y=find_set(y);

	    if(x==y)
	     return;
	    else {
	          if(find_set1(x) || check(y,x))
	           {
	               fal++;
	               return;
	           }
	           else{
	             //list_combine(x,y);
	             union_sets1(x,y);
	             union_sets(x,y);
	           }

        }
   }

  // x can eat y

	if(l==2)
	{
	    if(parent[x]==-1 || parent[y]==-1)
	    {
	        if(parent[y]==-1)
	          parent[y]=y;

	        if(parent[x]==-1){
	         parent[x]=x;
	        }
            union_sets1(x,y);
           // list_combine(x,y);

	        return;
	    }



	    if(x==y)
	    {
	        fal++;
	        return;
	    }

	   x = find_set (x);
	   y = find_set (y);

	   if(x==y)
	   {
	       fal++;
	       return;
	   }
	   else
	   {
	       if(check(y,x))
	       {
	           fal++;
	           return;
	       }
	       else
	       {

           /*  // animal[a][b]=1;
	          _list *temp= new  _list;
	           temp->id=y;
	           temp->next=animal[x];
	           animal[x]=temp;*/
	           union_sets1(x,y);
	            //list_combine(x,y);
	       }

	   }

	}

}


int main()
{
    int T,k,a,b,c;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&L,&k);
        init();
        fal=0;
        /*for(int i=0;i<=L;i++)
            for(int j=0;j<=L;j++)
          animal[i][j]=0;*/
       //   for(int i=0;i<=L;i++)
        //     animal[i]=NULL;

        for(int i=1;i<=k;i++)
        {
           scanf("%d%d%d",&a,&b,&c);
            process_query(a,b,c);

        }
        printf("%d\n",fal);

     }
    return 0;
}
