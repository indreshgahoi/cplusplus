/*
 * listtoBinaryTree.cpp
 *
 *  Created on: Mar 11, 2013
 *      Author: indresh
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using  namespace std;

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


 //Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 ListNode* getMidPointer(ListNode *head){

     ListNode *n1=head,*n2=head,*res=n1;
  while(n2){
	 if(n2->next)
		  n2=n2->next->next;
     else
		  break;
       if(n1){
    	  res=n1;
		  n1= n1->next;
	   }
  }
   return res;
 }

 TreeNode *sortedListToBST(ListNode *head) {
        ListNode *mid=getMidPointer(head);
        if(!mid) return NULL;
        TreeNode *root=NULL;
        if(!mid->next){
         root=new TreeNode(mid->val);
         root->left=NULL;root->right=NULL;

        }
        else{
        root=new TreeNode(mid->next->val);
        ListNode *next=mid->next->next;
        mid->next=NULL;
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(next);
        }
        return root;
     }

 /*
  *  Sorted Array to Binary Tree
  */
 TreeNode *sortedArrayToBSTHelp(vector<int> &num,int l,int r) {
         // Start typing your C/C++ solution below
         // DO NOT write int main() function
	 if(l>r)
		 return NULL;
	 TreeNode *root=NULL;
	   if(l==r)
	   {
		  root=new TreeNode(num[l]);
		  root->left=root->right=NULL;
	   }
	   else{
		  int m=(l+r)>>1;
		   root=new TreeNode(num[m]);
		   root->left=sortedArrayToBSTHelp(num,l,m-1);
		   root->right=sortedArrayToBSTHelp(num,m+1,r);
	   }
	   return root;
     }
 TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return sortedArrayToBSTHelp(num,0,num.size()-1);
    }

 /*
  *  Level order Traversal of the tree
  */
 vector<vector<int> > res;
     int maxH=-1;

     void  maxDepth(TreeNode *root,int h) {

          if(root){

         	  maxDepth(root->left,h+1);
         	  maxDepth(root->right,h+1);
                maxH=max(maxH,h);

          }

  }

  void  levelOrderBottomHelper(TreeNode *root,int h) {
         if(root){
              levelOrderBottomHelper(root->left,h+1);
         	  levelOrderBottomHelper(root->right,h+1);
              res[maxH-h].push_back(root->val);
          }
  }
  vector<vector<int> > levelOrderBottom(TreeNode *root) {
 	 res.clear();
 	 maxH=-1;
     maxDepth(root,0);
     res=*new vector<vector<int> >(maxH+1,vector<int>());
 	 levelOrderBottomHelper(root,0);
 	 return res;
  }

  /*
   *  MaxDepth of Binary Tree
   */

  int maxH=-1;

     void  maxDepthHelp(TreeNode *root,int h) {

          if(root){

               maxDepthHelp(root->left,h+1);
         	   maxDepthHelp(root->right,h+1);
                maxH=max(maxH,h);

          }

  }
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        maxH=-1;
        maxDepthHelp(root,0);
        return maxH+1;

    }
/*
 *  ZigZag Level Order Traversal
 */
//    vector<vector<int> > res;
//void zigzagLevelOrderHelper(TreeNode *root,int h) {
//            // Start typing your C/C++ solution below
//            // DO NOT write int main() function
//	     if(!root) return;
//	      static int fl=0;
//	      if(res.size()<=h)
//	    	  res.push_back(vector<int>());
//	       if(fl){
//	    	   fl=0;
//	    	   zigzagLevelOrderHelper(root->left,h+1);
//	    	   zigzagLevelOrderHelper(root->right,h+1);
//	       }
//	       else{
//	    	   fl=1;
//	    	   zigzagLevelOrderHelper(root->right,h+1);
//	    	   zigzagLevelOrderHelper(root->left,h+1);
//
//	       }
//           res[h].push_back(root->val);
//      }

    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
                vector<TreeNode*> e,o;
                int h=0;
                vector<vector<int> > res;
                if(root)
                {
                    e.push_back(root);

                }
                while(!(e.size()==0 && o.size()==0)){
                  res.push_back(vector<int>());

                  if((h%2)==0){
                	 // o.clear();
                	  for(vector<TreeNode*>::iterator it=e.begin();it!=e.end();it++){
                		  res[h].push_back((*it)->val);
                		  if((*it)->left)
                		  o.push_back((*it)->left);
                		  if((*it)->right)
                		  o.push_back((*it)->right);
                	  }
                         e.clear();
                  }
                	  else{
                		 // e.clear();
                         vector<TreeNode*>::iterator it1=o.begin();

                         for(vector<TreeNode*>::reverse_iterator it=o.rbegin();it!=o.rend();it++){
                		             		  res[h].push_back((*it)->val);
                		             		  if((*it1)->left)
                		             		  e.push_back((*it1)->left);
                		             		  if((*it1)->right)
                		             		  e.push_back((*it1)->right);
                                               it1++;
                		             	  }
                                            o.clear();

                	  }
                  h++;
                }

         return res;
        }

/*
 * Binary Tree Level order traversal
 */
    vector<vector<int> > res;
       void  levelOrderHelper(TreeNode *root,int h) {
              if(root){
                   if(res.size()<=h){
                  	  res.push_back(vector<int>());
              	  }
                   levelOrderHelper(root->left,h+1);
                   levelOrderHelper(root->right,h+1);

                   res[h].push_back(root->val);
               }
    }


   vector<vector<int> > levelOrderi(TreeNode *root) {
              // Start typing your C/C++ solution below
              // DO NOT write int main() function
              res.clear();
              levelOrderHelper(root,0);
              return res;
    }







  /*
   *  Binary Tree is Symetric
   */
bool isSame(TreeNode *r1,TreeNode*r2){
	 if(!r1 && !r2) return true;

	 if((!r1 && r2) || (r1 && !r2) || (r1->val!=r2->val))
		 return false;
	return (isSame(r1->left,r2->right)) &&(isSame(r1->right,r2->left));
 }

 bool isSymmetric(TreeNode *root) {
             if(!root)
            	 return true;
             return isSame(root->left,root->right);
}

 /*
  *   Same tree leetcode
  */

 bool isSameTree(TreeNode *p, TreeNode *q) {
     if(!p&& !q) return true;
     if((!p && q) ||(p && !q) ||(p->val!=q->val))
    	 return false;
     return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }

 /*
  *  Validation of binary Tree
  */
 int pre=-1e10;

  bool isValidBSThelp(TreeNode *root) {
        if(root){
           bool l= isValidBSThelp(root->left);
     	   if(root->val>pre){
     		   pre=root->val;
     	   }
     	   else{
     		   return false;
     	   }
     	   bool r=isValidBSThelp(root->right);
     	   return l&&r;
        }
       return true;
     }
      bool isValidBST(TreeNode *root) {
      pre=-1e10;
      return  isValidBSThelp(root);
     }

     /*
      * Recover Binary Search Tree
      *
      */
      int pre=-1e10;
      TreeNode *n1,*n2;
      void recoverTreeHelper(TreeNode *root) {
                   if(root){
                	   recoverTreeHelper(root->left);
                	  if(pre!=-1e10 && root->val<pre){
                            n2=root;

                            if(!n1)
                            	n1=root;

                	  }
                	  else{
                		  pre=root->val;
                	  }
                   recoverTreeHelper(root->right);
                }
      }
      void recoverTree(TreeNode *root) {

    	  pre=-1e10;
    	  n1=n2=NULL;

         n2=root;
    	  recoverTreeHelper(root);
           swap(n1->val,n2->val);
          }


 /*
  *  count trees
  *  count the structurally different no binary trees
  *
  */

int numTrees(int n) {
             if(n<=1)
               return 1;
             else{
                int sum=0,left,right,root;
                for(int i=1;i<=n;i++)
                {
                    root=i;
                    left=numTrees(root-1);
                    right=numTrees(n-root);
                    sum+=(left*right);
                }
                 return sum;
             }

         }
/*
 * Unique Binary Trees II
 *
 */
vector<TreeNode*> generate(int s,int e){
   TreeNode *r=NULL;
   if(s>e) return vector<TreeNode*>(1,r);
   vector<TreeNode*> res;
   for(int i=s;i<=e;i++){
      vector<TreeNode*> left=generate(s,i-1);
      vector<TreeNode*> right=generate(i+1,e);
      int ls=left.size(),rs=right.size();
      for(int l=0;l<ls;l++)
          for(int r=0;r<rs;r++){
             TreeNode *root=new TreeNode(i);
             root->left=left[l];
             root->right=right[r];
             res.push_back(root);
    	  }

   }
   return res;
}

vector<TreeNode *> generateTrees(int n) {
      return generate(1,n);

}

/*
 *  Inorder Traversal
 */

vector<int> operator+(vector<int> &a,vector<int> &b){
     vector<int> res(a);
     for(vector<int>::iterator it=b.begin();it!=b.end();it++)
    	 res.push_back(*it);
     return res;
}
vector<int> inorderTraversal(TreeNode *root) {
       if(root){
       vector<int> left=inorderTraversal(root->left);
       left.push_back(root->val);
       vector<int> right=inorderTraversal(root->right);
       return left+right;
       }
       return vector<int>();
}

      int main(){
    	 int x;
    	 scanf("%d",&x);
    	char s[15];
    	int i=0;
    	while(scanf("%s",s)){
    		if(s[1]=='+'){
    			i++;
    		}
    		else
    			 i--;
    	}
        printf("%d\n",x+i);
    }
