/*
 * MagicBoard.cpp
 *
 *  Created on: Feb 9, 2013
 *      Author: indresh
 */

#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>
#include <string.h>
#define tr(c,i)    for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
using namespace std;
typedef pair<int ,int> pib;

/*
 * ORDERSET.cpp
 *
 *  Created on: Feb 25, 2013
 *      Author: indresh
 */



#define BLACK 0
#define RED    1

/*
 *  1-> Every Node is either Red or Black.
 *  2-> The root is Black.
 *  3-> Every leaf (NIL) is Black.
 *  4-> If a node is Red then both it's children are Black.
 *  5->For each node, all simple paths from the node to descendant leaves
 *        contain the same number of nodes.
 *
 */

typedef  int Integer;


struct Key{
	Integer key;
	Key(Integer key=1000000007):key(key){

	}
	void print(){
		 printf("%d",key);
	}
	bool operator==(Key&o){
		return key==o.key;
	}
	bool operator<(Key&o){
			return key<o.key;
		}
	bool operator>(Key&o){
			return key>o.key;
		}
};

 /*
  * Key compare function
  */


struct rb_tree_node{
	Key key;
	bool color;
	Integer count;
	Integer size;
	rb_tree_node *left,*right,*parent;
};

int compare(const void *obj1,const void *obj2){
	Key k1=((rb_tree_node *)obj1)->key,k2=(( rb_tree_node *)obj2)->key;
	    if(k1>k2)
		    return 1;
	    if(k1<k2)
		   return -1;
	return 0; /* k1==k2 */
}

class RedBlackTree{
public:
	rb_tree_node  *root;
	rb_tree_node  *nil;
	int (*compare) (const void *obj1,const void *obj2);

	RedBlackTree(int (*compare) (const void * ,const void *)):compare(compare){

		this->nil=new rb_tree_node();
		this->nil->color=BLACK;
		this->nil->left=nil;
		this->nil->key=Key(1000000009);
		this->nil->size=0;
		this->nil->count=0;
		this->nil->right=nil;
		this->nil->parent=nil;
		this->root=nil;
	}

	void leftRotation(rb_tree_node *x){
		rb_tree_node  *y;
		rb_tree_node  *nil=this->nil;

		y=x->right;
		if(y==nil)
			return;
		//assert(y!=nil);
		x->right=y->left;

		if(y->left!=nil){
			y->left->parent=x;
		}
		y->parent=x->parent;
		if(x->parent==nil){
			this->root=y;
		}
		else if(x->parent->left==x){
			x->parent->left=y;
		}else{
			 x->parent->right=y;
		}
		y->left=x;
		x->parent=y;
		y->size=x->size;
		x->size=((x->left->size)+(x->right->size)+(x->count));
	}

	void rightRotation(rb_tree_node  *y){
		rb_tree_node  *x;
		rb_tree_node  *nil=this->nil;

		x=y->left;

		//assert(x!=nil);
         if(x==nil)
        	 return;
		y->left=x->right;

		if(x->right!=nil){
			x->right->parent=y;
		}

		x->parent=y->parent;

		if(y->parent==nil){
			this->root=x;
		}
		else if(y->parent->left==y){
			 y->parent->left=x;
		}
		else{
			y->parent->right=x;
		}

		x->right=y;
		y->parent=x;
        x->size=y->size;
        y->size=((y->left->size)+(y->right->size)+(y->count));

	}

	rb_tree_node * grandparent(rb_tree_node  *x){
		rb_tree_node *nil=this->nil;
		if(x!=nil && x->parent!=nil)
			return x->parent->parent;
		else
		   return nil;
	}

	rb_tree_node * uncle(rb_tree_node *x){
		rb_tree_node  *nil=this->nil;
		rb_tree_node  *g=grandparent(x);
		if(g==nil){
			return nil;
		}
		else if(x->parent==g->left)
		{
			return g->right;
		}
		else{
			 return g->left;
		}
	}



	rb_tree_node * sibling(rb_tree_node  *n)
	{
	 if (n == n->parent->left)
	  return n->parent->right;
	 else
	  return n->parent->left;
	}

	void maintainSize(RedBlackTree *tree,rb_tree_node  *n)
	{


		while(n!=tree->root && (n!=tree->nil)){
			n->size=((n->left->size)+(n->right->size)+(n->count));
			n=n->parent;
		}
		n->size=((n->left->size)+(n->right->size)+(n->count));

	}

	rb_tree_node *  TreeSuccessor(rb_tree_node* x) {
		 rb_tree_node* y=this->nil;
		 rb_tree_node* nil=this->nil;
		 rb_tree_node* root=this->root;

	   if (nil != (y = x->right)) { /* assignment to y is intentional */
	     while(y->left != nil) { /* returns the minium of the right subtree of x */
	       y=y->left;
	     }
	     return(y);
	   } else {
	     y=x->parent;
	     while(x == y->right) { /* sentinel used instead of checking for nil */
	       x=y;
	       y=y->parent;
	     }
	     if (y == root) return(nil);
	     return(y);
	   }
	 }

	 void RBInsert_FixUP(rb_tree_node  *z){
		 rb_tree_node *nil=this->nil;
	    while(RED==(z->parent->color)){
	    	rb_tree_node  *g=grandparent(z);
	    	rb_tree_node  *u=uncle(z);
	    	 if(g->left==z->parent)
	    	 {

	    		 if(RED==u->color){
	    			 z->parent->color=BLACK;
	    			 u->color=BLACK;
	    			 g->color=RED;
	    			 z=g;
	    		 }
	    		 else{

	    		    	   if(z==z->parent->right){ /* Zig-Zag */
	    			         z=z->parent;
	    			         leftRotation(z);
	    		            }
	    		    	    g=grandparent(z);
	    		    	    z->parent->color=BLACK;
	    		    	    g->color=RED;
	    		    	    rightRotation(g);
	    		      }

	    	 }
	    	 else{

	    		  if(RED==u->color){
                   z->parent->color=BLACK;
                   u->color=BLACK;
                   g->color=RED;
                   z=g;
	    		  }
	    		  else{

	    			   if(z->parent->left==z){
	    				   z=z->parent;
	    				   rightRotation(z);
	    			   }
	    			   g=grandparent(z);
	    			   z->parent->color=BLACK;
	    			   g->color=RED;
	    			   leftRotation(g);



	    		  }
	    	 }

	    }
	 this->root->color=BLACK;
	 }

	 rb_tree_node* search(RedBlackTree *tree,Key key){
			 rb_tree_node  *x=tree->root;
			 while(x!=nil){
				   if(key==x->key){/* x.key==z.key */
					  return x;
					}
				   else if(key>x->key){ /*z.key> x.key */
					        x=x->right;
				    }
				    else{
					   x=x->left;
				    }
			  }

       return tree->nil;
	 }

	 int  queryC(RedBlackTree *tree,Key key){
		int res=0;
	 			 rb_tree_node  *x=tree->root;
	 			 while(x!=nil){
	 				   if(key==x->key){/* x.key==z.key */

	 					  return res=res+(x->left->size);
	 					}
	 				   else if(key>x->key){ /*z.key> x.key */
	 					  res=res+1+(x->left->size);
	 					        x=x->right;
	 				    }
	 				    else{

	 					 x=x->left;

	 				    }
	 			  }
	        return res;
	 	 }





	 void  RBInsert(rb_tree_node *z){
	 rb_tree_node  *nil=this->nil;
	 rb_tree_node  *y=this->nil;
	 rb_tree_node  *x=this->root;

	 while(x!=nil){
		 y=x;
		 Integer c=this->compare(z,x);
		 if(0==c){/* x.key==z.key */
			// x->count+=1;
			 //free(z);
			 return ;
		 }
		 else if(1==c){ /*z.key> x.key */
			      // x->size=(x->size)+1;
			       x=x->right;
		 }
		 else{
			// x->size=(x->size)+1;
			  x=x->left;
		 }
	 }

	 z->parent=y;
	 if(y==nil){
		 this->root=z;
	 }
	 else if(1==this->compare(z,y)){
		        y->right=z;
	          }
	       else{
	    	   y->left=z;
	       }
	 z->left=this->nil;
	 z->right=this->nil;
	 z->color=RED;
	 z->size=1;
	 z->count=1;
	 maintainSize(this,z);
	 RBInsert_FixUP(z);

 }


	 void insert(Key key){
           rb_tree_node *z=new rb_tree_node();
           z->key=key;
     //      z->value=value;
          // z->size=1;
           //z->count=1;
           RBInsert(z);
    }


 void RBDeleteFixUp(RedBlackTree *tree, rb_tree_node* x) {
	 rb_tree_node* root=tree->root;
	 rb_tree_node* w=this->nil;

   while( (x->color==BLACK) && (root != x) && (x!=tree->nil)) {

	   if (x == x->parent->left) {
          w=x->parent->right;
       if (w->color==RED) {

    	   w->color=BLACK;
 	       x->parent->color=RED;
 	       leftRotation(x->parent);
 	       w=x->parent->right;
       }
       if ( (w->right->color==BLACK) && (w->left->color==BLACK) ) {
 	      w->color=RED;
 	      x=x->parent;
       }
       else {
 	        if (w->right->color==BLACK) {
 	             w->left->color=BLACK;
 	             w->color=RED;
 	             rightRotation(w);
 	             w=x->parent->right;
 	         }
 	         w->color=x->parent->color;
 	         x->parent->color=BLACK;
 	         w->right->color=BLACK;
 	         leftRotation(x->parent);
 	         x=root; /* this is to exit while loop */
        }
     }

	   else
	   { /* the code below is has left and right switched from above */
       w=x->parent->left;
          if (w->color==RED) {
 	          w->color=BLACK;
 	          x->parent->color=RED;
 	          rightRotation(x->parent);
 	          w=x->parent->left;
          }
          if ( (w->right->color==BLACK) && (w->left->color==BLACK) ) {
 	            w->color=RED;
 	            x=x->parent;
           }
          else {
 	               if (w->left->color==BLACK) {
 	                      w->right->color=BLACK;
 	                      w->color=RED;
 	                      leftRotation(w);
 	                      w=x->parent->left;
 	                }
 	               w->color=x->parent->color;
 	               x->parent->color=BLACK;
 	               w->left->color=BLACK;
 	               rightRotation(x->parent);
 	               x=root; /* this is to exit while loop */
          }
     }
   }
   x->color=BLACK;


 }

 void RBTransPlant(RedBlackTree  *tree, rb_tree_node  *u,rb_tree_node  *v){
	 if(u->parent==this->nil){
		 tree->root=v;
		 if(v->parent!=this->nil)
		 v->parent=this->nil;
	 }
	 else if(u==u->parent->left){
		 u->parent->left=v;
	 }
	 else{
		 u->parent->right=v;
	 }
	 if(v!=this->nil)
	 v->parent=u->parent;
 }

 void RBDelete(RedBlackTree *tree, rb_tree_node *z){
	 rb_tree_node* y;
	 rb_tree_node* x;
	 rb_tree_node* p=z->parent;
	y=z;
	bool y_original_color=y->color;
	if(z->left==tree->nil){
		x=z->right;
		RBTransPlant(tree,z,z->right);
		if(x!=tree->nil)
		{
			maintainSize(tree,x);
		}

		else
		{
		   maintainSize(tree,p);
		}

	}
	else if(z->right==tree->nil){
		     x=z->left;
		     RBTransPlant(tree,z,z->left);
		     maintainSize(tree,x);
	}
	else{
		y=TreeSuccessor(z);
		y_original_color=y->color;
        p=y->parent;
		x=y->right;
		if(y->parent==z){
            if(x!=tree->nil)
			x->parent=y;/* i didn't get it*/
		    p=y;
		}
		else
		{
		 RBTransPlant(tree,y,y->right);
		  y->right=z->right;
		  if(y->right!=tree->nil)
		  y->right->parent=y;
		}
		RBTransPlant(tree,z,y);
		y->left=z->left;
		if(y->left!=tree->nil)
		y->left->parent=y;
		y->color=z->color;
		maintainSize(tree,p);


	}
    delete z;
	//free(z);
	if(y_original_color==BLACK)
			{
				RBDeleteFixUp(tree,x);
			}
}

 void erase(Key  key){
 		 rb_tree_node  *get=search(this,key);

 		  if(get==this->nil){
 			//  printf("tree dont't have key..."); while(1);
 		  }

 		  else{
 			  RBDelete(this,get);
 		  }
 	}


 rb_tree_node  * queryKthmin(rb_tree_node *tree,Integer k){
	 Integer r;
	 while(true){
	 r=(tree->left->size)+(tree->count);
	   if(k==r)
		 			 return tree;
	   else  if(k<r)
			tree=tree->left;
	   else{
		  tree=tree->right;k=k-r;
	   }
	 }
	// printf("invalid\n");
	 return this->nil;
 }


 void InorderTreePrint(RedBlackTree * tree, rb_tree_node* x) {
	 rb_tree_node* nil=tree->nil;
	 rb_tree_node* root=tree->root;
   if (x != tree->nil) {
     InorderTreePrint(tree,x->left);
     printf("size=%d",x->size);
   //  x->value.print();
     printf("  key=");
     x->key.print();
     printf("  l->key=");
     if( x->left == nil) printf("NULL"); else x->left->key.print();
     printf("  r->key=");
     if( x->right == nil) printf("NULL"); else (x->right->key).print();
     printf("  p->key=");
     if( x->parent == nil) printf("NULL"); else (x->parent->key).print();
     printf("  red=%i\n",x->color);
     InorderTreePrint(tree,x->right);
   }
 }

};








vector<pib> row(500001),col(500001);
RedBlackTree  r0(&compare),r1(&compare),c0(&compare),c1(&compare);
int t=0,n;
void urq(int i,int x){
	int lasttime=row[i].first;
	t++;
	row[i].first=t;
	if(row[i].second){
		r1.erase(lasttime);

		if(x==1)
		{ r1.insert(t);
			row[i].second=1;
		}
		else{

			r0.insert(t);
			row[i].second=0;
		}
	}
	else{
		r0.erase(lasttime);
		if(x==1){
			r1.insert(t);
			row[i].second=1;
		}
		else{
			r0.insert(t);
			row[i].second=0;
		}
	}


}
void ucq(int i,int x){
	int lasttime=col[i].first;
		t++;

		col[i].first=t;
		if(col[i].second){
			c1.erase(lasttime);
			if(x==1)
			{
				c1.insert(t);
				col[i].second=1;
			}
			else{
				c0.insert(t);
				col[i].second=0;
			}
		}
		else{
			c0.erase(lasttime);
			if(x==1){
				c1.insert(t);
				col[i].second=1;
			}
			else{
				c0.insert(t);
				col[i].second=0;
			}
		}

}

int rrq(int i){
	int res;

    if(row[i].second)
    {
    	res=(c0.root->size)-(c0.queryC(&c0,Key(row[i].first)));


   }
    else
    {

    	res=n-((c1.root->size)-(c1.queryC(&c1,Key(row[i].first))));

    }

	return res;
}
int rcq(int i)
{
	int res ;
	if(col[i].second){
		res=(r0.root->size)-(r0.queryC(&r0,Key(col[i].first)));

	}
	else{
		res=n-((r1.root->size)-(r1.queryC(&r1,Key(col[i].first))));

	}
	// cout<<"res="<<res<<endl;
	return res;
}
int main(){


    int T;
	cin>>n>>T;
	char s[17];
	int x,q;
	t=0;
	for(int i=0;i<T;i++){
		scanf("%s",s);
		scanf("%d",&q);
		 if(s[0]=='R'){
			 if(s[3]=='Q')
			 printf("%d\n",rrq(q));
			 else{
			 scanf("%d",&x);urq(q,x);
			 }
		 }
		 else{
			 if(s[3]=='Q')
			 			  printf("%d\n",rcq(q));
			 			 else{
			 				scanf("%d",&x);ucq(q,x);
	}
		 }


	}
	return 0;
}
