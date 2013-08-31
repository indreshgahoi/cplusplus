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

struct Node
{
    int pr;
    int id;
    int eat;
};
Node animal[N];

int parent[N],rank1[N],L,fal=0;

void make_set (int v) {
	parent[v] = v;
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

	for (int i=1; i<=L; ++i){
		animal[i].eat=-1;
		make_set (i);}
}

inline bool check(int x , int y)
{
if(animal[x].eat==-1)
    return true;
if(find_set(animal[x].eat)==find_set(y))
    return true;
return false;
}


void process_query (int l, int x, int y) {

   if(x>L || y>L){
     fal++;
     // printf("l1\n");
     return;
     }

//same kind x and y

if(l==1)
{
        x=find_set(x);
	    y=find_set(y);

	    if(x==y)
	   {
	       //printf("l2\n");
	    return;
       }
	    else {
	        if(animal[x].eat==-1 && animal[y].eat== -1)
               {
                       union_sets(x,y);
               }
	            else if(animal[x].eat==-1 && animal[y].eat!= -1)
	            {
	                animal[x].eat=find_set(animal[y].eat);
	            }
	            else if(animal[x].eat!=-1 && animal[y].eat== -1)
	            {
	                animal[y].eat=find_set(animal[x].eat);
	            }
	          else
	          {

	              if(!(find_set(animal[x].eat)==find_set(animal[y].eat)))
	              {
	                  fal++;
                      return;
	              }
                  else if((check(x,y) || check(y,x)))
                  {
	                   fal++;
	                   return;
                  }
                  else
                  {
                    union_sets(find_set(animal[x].eat),find_set(animal[y].eat));
                  }
	          }
                union_sets(x,y);


        }
   }

// x can eat y

if(l==2)
{
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
            if(animal[x].eat==-1)
            {
	          animal[x].eat=y;
	          union_sets(animal[y].id,find_set(x));
            }
            else
            {       if(find_set(animal[y].eat)==x)
	                {
	                  fal++;
	                  return;
                    }
                    if((find_set(animal[x].eat)==(find_set(animal[y].eat))))
	                {
	                    fal++;
                        return;
	                }
	                if((find_set(animal[x].eat)!=(find_set(animal[y].eat))))
	                {
	                    union_sets(find_set(animal[x].eat),y);
                        return;
	                }

                    else
                    union_sets(find_set(animal[x].eat),y);
            }
        }

    }

}






int main()
{
     #ifndef ONLINE_JUDGE
    freopen("input2.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif

    int T,k,a,b,c;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&L,&k);
        init();
        fal=0;
        for(int i=1;i<=k;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            process_query(a,b,c);
            printf("%d %d\n",i,fal);

        }
        printf("%d\n",fal);

     }
    return 0;
}
