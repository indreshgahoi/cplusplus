#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

const int inf	=	1000000000;

struct node
{
	node *left,*right;
	int aux,key,size,cnt;
};
typedef node* Treap;

inline void renew(Treap &root)
{
	root->size=root->cnt+root->left->size+root->right->size;
}

inline void leftRotate(Treap &root)
{
	Treap t=root->left;
	root->left=t->right;
	t->right=root;
	renew(root);
	renew(t);
	root=t;
}

inline void rightRotate(Treap &root)
{
	Treap t=root->right;
	root->right=t->left;
	t->left=root;
	renew(root);
	renew(t);
	root=t;
}
//====================================

const int maxn	=	500005;

Treap nilpoint;
node mem[maxn*2];
vector<Treap> memStack;
int nodeCnt;

inline Treap newNode()
{
	Treap ret;
	if (memStack.size()){
		ret=memStack.back();
		memStack.pop_back();
	}else{
		assert(nodeCnt<maxn*2);
		ret=&mem[nodeCnt++];
	}
	return ret;
}

inline void insert(Treap &root,int key)
{
	if (root==nilpoint){
		root=newNode();
		root->left=root->right=nilpoint;
		root->key=key;
		root->cnt=root->size=1;
		root->aux=rand()%inf;
		return;
	}
	if (key==root->key){
		++root->cnt;
	}else if (key<root->key){
		insert(root->left,key);
		if (root->left->aux<root->aux){
			leftRotate(root);
		}
	}else if (key>root->key){
		insert(root->right,key);
		if (root->right->aux<root->aux){
			rightRotate(root);
		}
	}else{
		assert(false);
	}
	renew(root);
}

inline void erase(Treap &root,int key)
{
	if (root==nilpoint){
		printf("error finding %d\n",key);while (1);
		return;
	}
	if (root->key==key){
		if (root->cnt>1){
			--root->cnt;
		}else{
			if (root->left==nilpoint && root->right==nilpoint){
				memStack.push_back(root);
				root=nilpoint;
				return;
			}
			if (root->left->aux<root->right->aux){
				leftRotate(root);
				erase(root->right,key);
			}else{
				rightRotate(root);
				erase(root->left,key);
			}
		}
	}else if (key<root->key){
		erase(root->left,key);
	}else if (key>root->key){
		erase(root->right,key);
	}else{
		assert(false);
	}
	renew(root);
}

inline int query(Treap &root,int key)
{
	if (root==nilpoint) return 0;
	if (key>root->key) return query(root->right,key);
	return root->right->size+root->cnt+query(root->left,key);
}

//========================================

int color[2][maxn];// R/C, id
int timeStamp[2][maxn];// R/C, id
Treap tree[2][2];// R/C, 0/1, id
int n;

inline int query(int op,int id)// R/C row_id/col_id
{
	int cur=color[op][id];
	int ts=timeStamp[op][id];
	int changed=query(tree[op^1][cur^1],ts);
	int cnt=(n-changed);
	if (cur==0){
		return cnt;
	}else{
		return n-cnt;
	}
}

inline void set(int op,int id,int value,int times)// R/C row_id/col_id new_value time_stamp
{
	int cur=color[op][id];
	int ts=timeStamp[op][id];
	if (ts>0){
		erase(tree[op][cur],ts);
	}
	timeStamp[op][id]=times;
	color[op][id]=value;
	insert(tree[op][value],times);
}

int main()
{
	nodeCnt=0;
	nilpoint=new node;
	nilpoint->left=nilpoint->right=nilpoint;
	nilpoint->size=nilpoint->cnt=0;
	nilpoint->aux=inf;
	memStack.clear();
	
	int q;
	scanf("%d%d",&n,&q);
	memset(color,0,sizeof(color));
	memset(timeStamp,0,sizeof(timeStamp));
	for (int i=0;i<2;++i){
		for (int j=0;j<2;++j){
			tree[i][j]=nilpoint;
		}
	}
	for (int times=1;times<=q;++times){
		char op[10];
		scanf("%s",op);
		int x,y,res=0;
		if (!strcmp(op,"RowQuery")){
			scanf("%d",&x);
			printf("%d\n",query(0,x));
		}else if (!strcmp(op,"ColQuery")){
			scanf("%d",&x);
			printf("%d\n",query(1,x));
		}else if (!strcmp(op,"RowSet")){
			scanf("%d%d",&x,&y);
			set(0,x,y,times);
		}else if (!strcmp(op,"ColSet")){
			scanf("%d%d",&x,&y);
			set(1,x,y,times);
		}
	}
	return 0;
}
