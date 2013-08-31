#include<stdio.h>
#include<string.h>
#define MAXNODES 10000000
#define NONLEAF -1
#define left(r) (2*r)
#define  right(r) (2*r+1)
#define father(r) ((r-1)/2)
#define  key(r)   (Treap[r].key)
struct item
{   int l,r,p;
    int key;
    int idx;
}Treap[MAXNODES];

void buildtree(int node ,int st,int lt,int p)
{
    if(st==lt)
    {
        Treap[node].key=1;
        Treap[node].idx=st;
        Treap[node].l=Treap[node].r=0;
        Treap[node].p=p;

    }
    else
    {
        buildtree(2*node,st,(st+lt)/2,node);
        Treap[node].l=2*node;
        buildtree(2*node+1,(st+lt)/2+1,lt,node);
        Treap[node].r=2*node+1;
        Treap[node].key=Treap[2*node].key+Treap[2*node+1].key;
        Treap[node].idx=NONLEAF;
        Treap[node].p=p;
    }


}

void print_tree(int root)

{
    if(root!=0)
    {
        print_tree(Treap[root].l);
        if(Treap[root].l==0 && Treap[root].r==0)
        {
            printf("\nleaf: idx=%d key=%d  \n",Treap[root].idx,Treap[root].key);
        }
        else
            printf("\nnonleaf key=%d",Treap[root].key);
        print_tree(Treap[root].r);
    }
}
int search_key(int k)
{
    int p,r=k;
    p=1;
    while(!(Treap[p].l==0 && Treap[p].r==0))
    {
        if(r<=Treap[Treap[p].l].key)
        {
            p=Treap[p].l;
        }
        else
        {
            r=r-Treap[Treap[p].l].key;
            p=Treap[p].r;
        }
    }
    return p;
}

void erase_key(int root, int k)
{
    int r=Treap[Treap[root].l].key,q,b,f,ff;
       q=root;
    while(!(Treap[q].l==0 && Treap[q].r==0))
    {   ff=Treap[q].p;
        f=q;
        if(r>=k)
        {
            b=Treap[q].r;
            q=Treap[q].l;
        }
        else
        {
            k=k-r;
            b=Treap[q].l;
            q=Treap[q].r;

        }
        r=Treap[Treap[q].l].key;
        Treap[f].key--;
        if(b==0 && !(Treap[q].l==0 && Treap[q].r==0) )
        {
            Treap[q].p=ff;
            if(Treap[ff].l==f)
              Treap[ff].l=q;
             else
               Treap[ff].r=q;
            ff=f;
            ff=Treap[f].p;
        }

    }

    if(Treap[f].l==q)
    {
        Treap[f].l=0;
      //  b=Treap[f].r;
    }
    else
    {
        Treap[f].r=0;
      //  b=Treap[f].l;
    }

    // printf("erase :%d\n",Treap[q].idx);
    q=0;
}
int main()
{
    int i,j,n,sr,m;
    Treap[0].l=Treap[0].r=Treap[0].key=0;


    while(1)
    {
    //    memset(Treap,0,MAXNODES*sizeof(item));
        scanf("%d%d",&n,&m);
        if(n==0 && m==0)
          break;
        buildtree(1,1,n,0);
        i=n;
        j=m;
        while(i>1)
        {
            //printf("\n\ncall erase with j=%d steps:%d\n",j,steps);
            erase_key(1,j);
          // print_tree(1);
            i--;
            j=((j+m-2)%i)+1;
        }
         sr=search_key(1);

         n==2?printf("2 %d 2\n",m):printf("%d %d %d\n",n,m,Treap[sr].idx);

        // (Treap[1].l)? printf("%d\n",Treap[1].idx):printf("%d\n",Treap[1].idx);
    }
  return 0;
}

