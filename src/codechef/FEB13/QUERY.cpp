#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<cmath>
#include<cassert>
using namespace std;

#define REP(i,a,b) for(i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define logN 18

int N, M;
char mode[111111]; int X1[111111], Y1[111111], A[111111], B[111111];

vector<int> edge[111111];
int up[111111][logN], subsize[111111], depth[111111];

void calc_up_subsize(int root, int bef){
  int i, j;

  up[root][0] = bef;
  REP(i,1,logN){
    if(up[root][i-1]==-1){ up[root][i] = -1; continue; }
    up[root][i] = up[up[root][i-1]][i-1];
  }

  if(bef==-1) depth[root] = 0;
  else        depth[root] = depth[bef] + 1;

  subsize[root] = 1;
  rep(i,edge[root].size()){
    j = edge[root][i];
    if(j==bef) continue;
    calc_up_subsize(j, root);
    subsize[root] += subsize[j];
  }
}

int get_up(int a, int k){
  int i;
  if(k==0) return a;
  rep(i,logN) if(k&1<<i){
    a = up[a][i];
    if(a==-1) return a;
  }
  return a;
}

int LCA(int a, int b){
  int i;
  if(depth[a] > depth[b]) a = get_up(a, depth[a]-depth[b]);
  if(depth[b] > depth[a]) b = get_up(b, depth[b]-depth[a]);
  if(a==b) return a;

  if(up[a][0]==up[b][0]) return up[a][0];
  REP(i,1,logN) if(up[a][i]==up[b][i]) return LCA(up[a][i-1], up[b][i-1]);
  assert(0 && "LCA");
}



/* Heacvy Light Deconposition */
int HLD_node;
vector< vector<int> > HLD_list;

int in_HLD_node[111111], in_HLD_place[111111];
int up_HLD_node[111111], up_HLD_place[111111];

void get_HLD_dfs(int root){
  int i, k, mx, hvy, node;
  vector<int> emp;

  node = HLD_node++;
  HLD_list.push_back(emp);

  for(;;){
    HLD_list[node].push_back(root);
    in_HLD_node[root] = node;
    in_HLD_place[root] = HLD_list[node].size()-1;
    
    mx = -1;
    rep(i,edge[root].size()) if(edge[root][i]!=up[root][0]) mx = max(mx, subsize[edge[root][i]]);
    rep(i,edge[root].size()) if(edge[root][i]!=up[root][0]) if(mx == subsize[edge[root][i]]) break;
    if(mx==-1) break;
    
    hvy = i;

    rep(i,edge[root].size()){
      k = edge[root][i];
      if(k==up[root][0]) continue;
      if(i==hvy) continue;

      up_HLD_node[k] = node;
      up_HLD_place[k] = HLD_list[node].size()-1;
      get_HLD_dfs(k);

    }

    root = edge[root][hvy];
  }
}

void get_HLD(void){
  HLD_node = 0;
  HLD_list.clear();

  get_HLD_dfs(0);
}



/* segment tree */
typedef struct SNODE_hogehoge {
  ll sum, add, d_add;
  int a, b;
  struct SNODE_hogehoge *left, *right;
} SNODE;


SNODE* gen_segtree(int a, int b){
  int sz = b-a;
  SNODE *res = (SNODE*) malloc( sizeof(SNODE) );
  res->a = a, res->b = b;
  res->sum = res->add = res->d_add = 0;
  if(sz > 1){
    res->left = gen_segtree(a, a+sz/2);
    res->right = gen_segtree(a+sz/2, b);
  }
  return res;
}

SNODE* node_copy_segtree(SNODE *node){
  SNODE *res = (SNODE*) malloc( sizeof(SNODE) );
  res->a = node->a; res->b = node->b;
  res->sum = node->sum; res->add = node->add; res->d_add = node->d_add;
  res->left = node->left; res->right = node->right;
  return res;
}

ll calc_sum_segtree(SNODE *node, ll A ,ll B){
  ll res = node->sum, n = (node->b) - (node->a);
  res += n * (node->add + A) + n * (n-1) / 2 * (node->d_add + B);
  return res;
}

SNODE* change_segtree(SNODE *node, int a, int b, ll A, ll B, ll All, ll Bll){
  SNODE *res;
  int sz;

  if(a < (node->a)){
    A += B * ((node->a)-a);
    a = node->a;
  }
  if(b > (node->b)) b = (node->b);

  if(a >= b){
    if(All || Bll){
      res = node_copy_segtree(node);
      res->add += All;
      res->d_add += Bll;
      return res;
    } else {
      return node;
    }
  }

  res = node_copy_segtree(node);
  if(a==(res->a) && b==(res->b)){
    res->add += A + All;
    res->d_add += B + Bll;
  } else {
    sz = (res->left->b) - (res->left->a);
    All += res->add;
    Bll += res->d_add;
    res->left  = change_segtree(res->left,  a, b, A, B, All, Bll);
    res->right = change_segtree(res->right, a, b, A, B, All+sz*Bll, Bll);
    res->add = res->d_add = 0;
    res->sum = calc_sum_segtree(res->left, 0, 0) + calc_sum_segtree(res->right, 0, 0);
  }

  return res;
}

ll get_sum_segtree(SNODE *node, int a, int b, ll A, ll B){
  int sz;
  if(a < (node->a)) a = (node->a);
  if(b > (node->b)) b = (node->b);

  if(a >= b) return 0;
  if(a==(node->a) && b==(node->b)) return calc_sum_segtree(node, A, B);

  sz = (node->left->b) - (node->left->a);
  A += node->add; B += node->d_add;
  return get_sum_segtree(node->left, a, b, A, B) + get_sum_segtree(node->right, a, b, A+B*sz, B);
}


/* history tree */
/* this momorize the root node of each HLD (after each changing query) */
typedef struct CNODE_hogehoge {
  int a, b, val;
  struct CNODE_hogehoge *left, *right;
} CNODE;

CNODE* node_copy_changetree(CNODE *node){
  CNODE *res = (CNODE*) malloc( sizeof(CNODE) );
  res->a = node->a; res->b = node->b; res->val = node->val;
  res->left = node->left; res->right = node->right;
  return res;
}

CNODE* gen_changetree(int a, int b){
  int sz = b-a;
  CNODE *res = (CNODE*) malloc( sizeof(CNODE) );
  res->a = a, res->b = b; res->val = 0;
  if(sz > 1){
    res->left = gen_changetree(a, a+sz/2);
    res->right = gen_changetree(a+sz/2, b);
  }
  return res;
}

int get_changetree(CNODE *node, int tn){
  int sz = (node->b) - (node->a);
  if(sz==1) return node->val;

  if(tn < (node->a) + sz/2) return get_changetree(node->left, tn);
  return get_changetree(node->right, tn);
}

CNODE* change_changetree(CNODE *node, int tn, int val){
  CNODE *res;
  int sz = (node->b) - (node->a);
  if(tn < (node->a) || tn >= (node->b)) return node;

  res = node_copy_changetree(node);
  if(sz>1){
    res->left  = change_changetree(res->left,  tn, val);
    res->right = change_changetree(res->right, tn, val);
  } else {
    res->val = val;
  }
  return res;
}

int change_time, cur_time;
int changing;
ll res;

CNODE *changetree_root[111111];

vector<SNODE*> segHLD_root[111111];
vector<int> segHLD_root_tm[111111];

vector<int> changetree_update;

/* segtree on HLD */
SNODE* get_segtree_root(int HLD_ind){
  int ls_tm;
  int a, b, c;

  if(changing && segHLD_root_tm[HLD_ind][segHLD_root[HLD_ind].size()-1] == change_time){
    return segHLD_root[HLD_ind][segHLD_root[HLD_ind].size()-1];
  }

  ls_tm = get_changetree(changetree_root[cur_time], HLD_ind);

  a = 0; b = segHLD_root[HLD_ind].size()-1;
  while(a<b){
    c = (a+b)/2;
    if(segHLD_root_tm[HLD_ind][c] < ls_tm) a = c + 1;
    else                                   b = c;
  }

  return segHLD_root[HLD_ind][a];
}

void do_change_HLD(int HLD_ind, int a, int b, ll A, ll B){
  SNODE* node = get_segtree_root(HLD_ind);
  node = change_segtree(node, a, b, A, B, 0, 0);

  changetree_update.push_back(HLD_ind);
  if(segHLD_root_tm[HLD_ind][segHLD_root[HLD_ind].size()-1] == change_time){
    segHLD_root[HLD_ind][segHLD_root[HLD_ind].size()-1] = node;
  } else {
    segHLD_root[HLD_ind].push_back(node);
    segHLD_root_tm[HLD_ind].push_back(change_time);
  }
}

void do_change(int a, int b, ll A, ll B, int len){
  ll Au = A + B * (len-1);
  
  while(in_HLD_node[a] != in_HLD_node[b]){
    Au -= in_HLD_place[b] * B;
    do_change_HLD(in_HLD_node[b], 0, in_HLD_place[b]+1, Au, B);
    b = HLD_list[in_HLD_node[b]][0];
    b = HLD_list[up_HLD_node[b]][up_HLD_place[b]];
    Au -= B;
  }
  do_change_HLD(in_HLD_node[a], in_HLD_place[a], in_HLD_place[b]+1, A, B);
}

void query_change(int X, int Y, ll A, ll B){
  int i;
  int len1, len2;
  int Z = LCA(X,Y);

  int len;
  int up, down;
  ll Au, Bu;

  changing = 1;

  len1 = depth[X] - depth[Z] + 1;
  len2 = depth[Y] - depth[Z];


  if(len1>0){
    len = len1; up = Z; down = X;
    Au = A+B*(len-1); Bu = -B;
    do_change(up, down, Au, Bu, len);
  }
  if(len2>0){
    len = len2; up = get_up(Y,len-1); down = Y;
    Au = A+B*len1; Bu = B;
    do_change(up, down, Au, Bu, len);
  }

  sort(changetree_update.begin(), changetree_update.end());
  changetree_root[change_time] = changetree_root[cur_time];
  rep(i,changetree_update.size()){
    if(i && changetree_update[i] == changetree_update[i-1]) continue;
    changetree_root[change_time] = change_changetree(changetree_root[change_time], changetree_update[i], change_time);
  }
  changetree_update.clear();
  changing = 0;
}

ll get_sum_HLD(int HLD_ind, int a, int b){
  SNODE *node = get_segtree_root(HLD_ind);
  return get_sum_segtree(node, a, b, 0, 0);
}

ll get_sum(int a, int b){
  ll res = 0;
  while(in_HLD_node[a] != in_HLD_node[b]){
    res += get_sum_HLD(in_HLD_node[b], 0, in_HLD_place[b]+1);
    b = HLD_list[in_HLD_node[b]][0];
    b = HLD_list[up_HLD_node[b]][up_HLD_place[b]];
  }
  res += get_sum_HLD(in_HLD_node[a], in_HLD_place[a], in_HLD_place[b]+1);
  return res;
}

ll query_question(int X, int Y){
  int Z = LCA(X, Y);
  return get_sum(Z,X) + get_sum(Z,Y) - get_sum(Z,Z);
}


int main(){
  int i,j,k;

  assert( scanf("%d%d",&N,&M)==2 );
  assert( 1<=N&&N<=100000 );
  assert( 1<=M&&M<=100000 );

  rep(i,N) edge[i].clear();
  REP(k,1,N){
    assert( scanf("%d%d",&i,&j)==2 );
    assert( 1<=i&&i<=N && 1<=j&&j<=N && i!=j );
    i--; j--;
    edge[i].push_back(j);
    edge[j].push_back(i);
  }

  rep(i,M){
    assert( scanf("%s",mode+i)==1 );
    assert( mode[i]=='c' || mode[i]=='q' || mode[i]=='l' );
    assert( mode[i+1]=='\0' );
    if(mode[i]=='c'){
      assert( scanf("%d%d%d%d",X1+i,Y1+i,A+i,B+i)==4 );
      assert( 0<=X1[i] && X1[i]<=100000 );
      assert( 0<=Y1[i] && Y1[i]<=100000 );
      assert( 0<=A[i] && A[i]<=1000 );
      assert( 0<=B[i] && B[i]<=1000 );
    }
    if(mode[i]=='q'){
      assert( scanf("%d%d",X1+i,Y1+i)==2 );
      assert( 0<=X1[i] && X1[i]<=100000 );
      assert( 0<=Y1[i] && Y1[i]<=100000 );
    }
    if(mode[i]=='l'){
      assert( scanf("%d",X1+i)==1 );
      assert( 0<=X1[i] && X1[i]<=100000 );
    }
  }

  change_time = cur_time = 0;
  res = 0;

  calc_up_subsize(0, -1); /* initialize: for example calculating LCA*/
  get_HLD(); /* getting HLD tree */

  changetree_root[0] = gen_changetree(0, HLD_node); /* creating history tree */
  rep(i,HLD_node){
    segHLD_root[i].push_back( gen_segtree(0, HLD_list[i].size()) );
    segHLD_root_tm[i].push_back( cur_time );
  }

  rep(k,M){
    if(mode[k]=='c'){
      change_time++;
      query_change((X1[k]+res)%N, (Y1[k]+res)%N, A[k], B[k]);
      cur_time = change_time;
    }
    if(mode[k]=='q'){
      res = query_question( (X1[k]+res)%N, (Y1[k]+res)%N );
      printf("%lld\n",res);
    }
    if(mode[k]=='l'){
      cur_time = (X1[k] + res)%(change_time + 1);
    }
  }

  return 0;
}
