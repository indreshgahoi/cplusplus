#include<stdio.h>
#define INT_MAX 32767

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
        p->key=key;
        p->left=NULL;
        p->right=NULL; 
    return(p);
}/*enf of maketree*/

void printline(int a){
	int j=25;
	while(j--)
		printf("%c",a);
		printf("\n");
}


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
 while(key != EOF){
    p=NULL;q=*tree;
     while(q!=NULL){
       p=q;
      if(key<=p->key)
        q=p->left;
      else
        q=p->right; 
     }/*End of inner while*/

     if(p==NULL){
    	 *tree=maketree(key);
     }else if(key<=p->key){
    	 setleft(p,key);
     }
     else setright(p,key);
     scanf("%d",&key);

 }/*end of outer while*/

}/*end of insert function*/

void pretrav(NODEPTR t){
    if(t!=NULL){
      printf("%d\n",t->key);
      pretrav(t->left);
      pretrav(t->right);
   }
}
void intrav(NODEPTR t){
    if(t!=NULL){
      intrav(t->left);
      printf("%d\n",t->key);
      intrav(t->right);
   }
}
void posttrav(NODEPTR t){
    if(t!=NULL){
      posttrav(t->left);
      posttrav(t->right);
      printf("%d\n",t->key);  
    }
}
void traversal(NODEPTR p){
  int ch;
  printline('*');
  while(1){
    printf("\nEnter the choice\n1.pretraversal\n2.posttraversal\n3.inorder\n4.return");
    scanf("%d",&ch);
   
    switch(ch){
         
         case 1:
                pretrav(p);break;
         case 2:
                posttrav(p);break;
         case 3:
                intrav(p);break;  
         case 4:
               break;
         default:
                 printf("Hi i m default");
                 break;

      }/*end of switch*/
  }

}/*end of traversal*/ 

int kthMin(NODEPTR T,int *k){
	int x;
	if(T){
		x=kthMin(T->left ,k);
		if((*k)!=0){
			(*k)--;
			if(*k==0)
				return(T->key);

			return(kthMin(T->right,k));
		}
	}
return x;
}

main()
{
	NODEPTR *tree;
	int ch;int j=0;
	//int number;
	*tree=NULL;
	while(1){
		printline('*');
		printf("Enter the choice:-");
		printf("\n1.Insert the element\n2.Delete the element\n3.Traversal\n4.call function\n");
		scanf("%d",&ch);
		printline('=');

      switch(ch){
         
         case 1:
                insert(tree);break;
         case 2:
               // delete();break;
         case 3:
                traversal(*tree);break;  
         case 4:printf("\nEnter the no u want to smallest\n");
		        scanf("%d",&j);
               printf("\n%d\n",kthMin(*tree,&j));printline('*');break;
         default:
              printf("Hi i m default");
              break;
      }/*end of switch*/
	}/*end of while*/
}/*end of main*/





   







