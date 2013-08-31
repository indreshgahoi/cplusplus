#include<stdio.h>
#include<malloc.h>
struct node {
   int key;
    struct node* left;
    struct node* right;
};
typedef struct node* NODEPTR;
NODEPTR getnode(void){
   NODEPTR p;
   p=(NODEPTR)malloc(sizeof(struct node));
   return(p);

}/*end of getnode*/
NODEPTR maketree(int key){
        NODEPTR p;
        p=getnode();
       // printf("\nprinting the node\n");
        p->key=key;
        p->left=NULL;
        p->right=NULL;
    return(p);
}/*enf of maketree*/
void setleft(NODEPTR p,int key){

if(p==NULL)
     printf("void insertion");
else if(p->left != NULL)
     printf("invalid insertion");
else
  p->left=maketree(key);
}
void setright(NODEPTR p,int key){

if(p==NULL)
     printf("void insertion");
else if(p->right != NULL)
     printf("invalid insertion");
else
  p->right=maketree(key);
}
void insert(NODEPTR *tree){

NODEPTR p,q;
int key;


    printf("\nEnter the keys");
    scanf("%d",&key);
while(key != -1){
   p=NULL;
   q=*tree;
    while(q!=NULL){
      p=q;

      if(key<=p->key)
        q=p->left;
      else
        q=p->right;
    }/*End of inner while*/

if(p==NULL){
    printf("\n core dump\n");
   *tree=maketree(key);
}else if(key<=p->key){
      setleft(p,key);
      }else setright(p,key);
scanf("%d",&key);

}}
void intrav(NODEPTR t){
    if(t!=NULL){
      intrav(t->left);
      printf("%d\n",t->key);
      intrav(t->right);
   }
}
int isleaf(NODEPTR tree){

if(tree->left==NULL && tree->right==NULL)
 return 1;
else
 return 0;

}

void updatetree(NODEPTR *tree){
    NODEPTR t= (*tree);


      if(t!=NULL) {
          int left_old=0;
          int right_old=0;
          int left_new=0;
          int right_new=0;
          if(t->left==NULL && t->right==NULL)
           {

           }
           else{

                   if(t->left!=NULL){
                      left_old=(t->left)->key;
                      updatetree(&t->left);
                     if(!isleaf(t->left))
                      left_new=(t->left)->key;
                   }
                if(t->right!=NULL){
                  right_old=(t->right)->key;
                  updatetree(&t->right);
                  if(!isleaf(t->right))
                  right_new=(t->right)->key;

               }

          t->key=left_old+right_old+ left_new+right_new ;
        }

    }


      }

int main(){
     NODEPTR tree=NULL;
     insert(&tree);
     intrav(tree);
     updatetree(&tree);
     intrav(tree);
     return 0;

}
