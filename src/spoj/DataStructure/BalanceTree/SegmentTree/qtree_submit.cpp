#include<iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#define MAXN 100008
#define dg(v) printf(#v"=%d\n",v);
using namespace std;
vector < pair<int,int> >  g[MAXN];
int root,N;
vector <int> lca_tree,lca_h,cost,lca_dfs_used, lca_dfs_list,lca_first;


void lca_dfs (int v, int h=1)
 {
	 lca_dfs_used[v] = 1;
	 lca_h [v] = h;
	 //puts("visit");
	 //dg(v);
	 lca_dfs_list.push_back(v);
	 int size=g[v].size();
//     dg(g[v][i].first);
	 //dg(size);
	 for (int i = 0; i<size;++i)
		 if (!lca_dfs_used [g[v][i].first])
		 {   cost[g[v][i].first]=cost[v]+g[v][i].second;
		     //dg(v);
		     //dg(g[v][i].first);
			 lca_dfs (g[v][i].first,h+1);
			 lca_dfs_list.push_back(v);
		 }
		 //else{
		//     dg(g[v][i].first);
		  //   puts("not call");}


			 // puts("visit back");
			  //dg(v);
 }

 void lca_build_tree (int i, int l, int r)
 {
	 if (l == r)
		 lca_tree [i] = lca_dfs_list [l];
	 else
	 {
		 int m = (l + r) >> 1;
		 lca_build_tree (i + i, l, m);
		 lca_build_tree (i + i +1, m +1, r);
		 if (lca_h [lca_tree [i + i]] <lca_h [lca_tree [i + i +1]])
			 lca_tree [i] = lca_tree [i + i];
		 else
			 lca_tree [i] = lca_tree [i + i +1];
	 }
 }

 int lca_tree_min (int i, int sl, int sr, int l, int r)
 {
	 if (sl == l && sr == r)
		 return lca_tree [i];
	 int sm = (sl + sr) >> 1;
	 if (r <= sm)
		 return lca_tree_min (i + i, sl, sm, l, r);
	 if (l> sm)
		 return lca_tree_min (i + i +1, sm +1, sr, l, r);
	 int ans1 = lca_tree_min (i + i, sl, sm, l, sm);
	 int ans2 = lca_tree_min (i + i +1, sm +1, sr, sm +1, r);
	 return lca_h [ans1] <lca_h [ans2]?  ans1: ans2;
 }

void init()
{
    int a,b,c;


        cost.resize(N+1);
        lca_h.resize (N+1);
        lca_dfs_list.resize((N) << 1);
	 lca_dfs_used.assign (N+1, 0);
        lca_dfs_used[0]=1;
        // graph read and set
        for(int i=1;i<=N;i++)
        {
            g[i].clear(),cost[i]=10000000;
        }
        for(int i=1;i<=N-1;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
              g[a].push_back(make_pair(b,c));
              g[b].push_back(make_pair(a,c));
        }

        root=rand()%N +1;
        cost[root]=0;
        //dg(root);
        lca_dfs (root);

        int m = (int)lca_dfs_list.size();
	    lca_tree.assign (lca_dfs_list.size ()*4+1,-1);
        //dg(m);
        lca_build_tree (1, 0, m-1);

        lca_first.assign (N+1,-1);
        //puts("hello");
	    for(int i = 0; i <m; ++i)
	    {
		     int v = lca_dfs_list [i];
          //     dg(v);
            // printf("%d ",v);
		     if (lca_first [v] == -1)
			     lca_first [v] = i;
        }
      //  printf("\n");
       // for(int i=1;i<=N;i++)
          // printf("%d ",lca_first[i]);



}

int lca (int a, int b)
 {
	 int left = lca_first[a],
		 right = lca_first[b];
	 if (left> right) swap(left, right);
	 return lca_tree_min (1, 0, (int) lca_dfs_list.size()-1, left, right);
 }


 int kth (int a, int b,int k)
 {
	 int left = lca_first [a],
		 right = lca_first [b];
	 if (left> right){k=left-right-k+2; swap (left, right);}
	 return lca_dfs_list[left+k-1];
 }


int main()
{

    string s1;
    int T ,la,k,n1,n2;

    scanf("%d",&T);


    while(T--)
    {
        scanf("%d",&N);
        init();

       // dg(root);


        while(true){
            cin>>s1;

        if(s1=="KTH"){

          scanf("%d%d%d",&n1,&n2,&k);
          printf("%d\n",kth(n1,n2,k));

         }
        else if(s1=="DIST"){
             scanf("%d%d",&n1,&n2);
             la=lca(n1,n2);
             //printf("la=%d\n",la);
             //puts("hello");
            // dg(n1);
            // dg(n2);
            // dg(la);
            // dg(c[n1]);
             //dg(c[n2]);
             printf("%d\n",cost[n1]+cost[n2]-(2*cost[la]));
         }
         else if(s1=="DONE")
         {
             break;
         }
     }
     }

 return 0;
}
