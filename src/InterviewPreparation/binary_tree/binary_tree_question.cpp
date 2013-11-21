/*
 * binary_tree_question.cpp
 *
 *  Created on: Mar 11, 2013
 *      Author: indresh
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include <queue>
#include <stack>
#define INF 1e9

using  namespace std;
//Definition for singly-linked list.
 struct ListNode
 {
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
     void setLeft(int lval)
     {
    	 this->left=new TreeNode(lval);
     }
     void setRight(int rval)
     {
    	 this->right=new TreeNode(rval);
     }
    friend std::ostream& operator<<(std::ostream& out,TreeNode* node)
     {
    	 if(node)
    	 {
    		 out<<"["<<node->val<<"]";
    	 }
    	 else
    	 {
    		 out<<"[NULL]";
    	 }
    	 out<<" ";
    	 return out;
     }
 };

 void preTraversal(TreeNode *root);
 void inOrderTraversal(TreeNode *root);
 void inOrderFronArray(int* in,int start,int end);
 vector<vector<int> > levelOrderBottom(TreeNode *root);
 vector<vector<int> > levelOrderi(TreeNode *root);
 void levelOrder(TreeNode* root);
 void printLevelOrder(TreeNode *root);
 void printLevelOrderZigZag(TreeNode* root);
 void reverseLevelOrderTraversal(TreeNode* root);
 vector<vector<int> > zigzagLevelOrder(TreeNode *root);
 vector<TreeNode*> nodesAtDistanceK(TreeNode*root,int k);


 TreeNode *sortedListToBST(ListNode *head);
 ListNode* getMidPointer(ListNode *head);
 TreeNode *sortedArrayToBST(vector<int> &num);


 int size(TreeNode* root);
 int countLeafs(TreeNode* root);
 int minValue(TreeNode* root);


 void maxDepth(TreeNode *root,int h);
 int maxDepth(TreeNode *root);
 int minDepth(TreeNode *root);
 int maxWidth(TreeNode* root);
 int height(TreeNode* root);
 /* Longest lesf to leaf path */
 int diameter(TreeNode* root);
 int diameterN2(TreeNode* root);


 void flatten(TreeNode *tree);
 void doubleTree(TreeNode* tree);

 bool isSame(TreeNode *r1,TreeNode*r2);
 bool isSymmetric(TreeNode *root);
 bool isFoldable(TreeNode* root);
 void mirror(TreeNode *root);
 bool isValidBSThelp(TreeNode *root);
 bool isBalanced(TreeNode *root);

 int numTrees(int n);
 vector<TreeNode *> generateTrees(int n);


 void recoverTree(TreeNode *root) ;

 TreeNode*  buildTree(vector<int> &preorder , vector<int> &inorder);

 bool hasPathSum(TreeNode *root, int sum);
 vector<vector<int> > pathSumii(TreeNode *root, int sum);
 void printPaths(TreeNode* root);// root_leaf_path

 int maxPathSum(TreeNode *root);
 bool isSumProperty(TreeNode* root);

// Done By PostOrder
void deleteTree(TreeNode* root);
TreeNode *lca(TreeNode *, TreeNode *);



// utility function

TreeNode* getNode(int new_data){
	TreeNode* new_node=new TreeNode(new_data);
	return new_node;
}

void insert(TreeNode** root_ref,int new_data){

	TreeNode* root=*root_ref;
	if(!root)
	{
		*root_ref=getNode(new_data);;
		return;
	}
    if(new_data<=root->val)
    {
    	insert(&(root->left),new_data);
    }
    else
    {
    	insert(&(root->right),new_data);
    }


}

 /*
  *  Tree Traversal
  */

 void printArray(int *A,int n)
 {
	std::cout<<"elements==[";
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<", ";
	}
	std::cout<<"]"<<std::endl;
 }

template <typename T>

T Max(T a,T b)
{
	return ((a)>(b))?(a):(b);
}

 template < class T >
 std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
 {
     os << "[";
     for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
     {
         os << " " << *ii;
     }
     os << "]";
     return os;
 }

 template < class T >
 vector<T> operator+(vector<T> &a,vector<T> &b){
      vector<T> res(a);
      for(typename vector<T>::iterator it=b.begin();it!=b.end();it++)
     	 res.push_back(*it);
      return res;
 }


 vector<int> inorderTraversal(TreeNode *root)
 {
        if(root){
        vector<int> left=inorderTraversal(root->left);
        left.push_back(root->val);
        vector<int> right=inorderTraversal(root->right);
        return left+right;
        }
        return vector<int>();
  }


 void inOrderTraversal(TreeNode *root)
 {
 	if(root){
 		inOrderTraversal(root->left);
 		cout<<" "<<root->val;
 		inOrderTraversal(root->right);
 	}
 }




 void preTraversal(TreeNode *root)
 {
 	if(root){
 		cout<<" "<<root->val;
 		preTraversal(root->left);
 		preTraversal(root->right);
 	}
 }


 void inOrderFronArray(int* in,int start,int end)
 {
	 if(start>end)
	 {
		 return;
	 }

	 inOrderFronArray(in,(start<<1)+1,end);

	 std::cout<<" "<<in[start];

	 inOrderFronArray(in,(start<<1)+2,end);



 }

 /*
  * Question: Given an arbitrary binary tree, convert it to a binary
  *  tree that holds Children Sum Property. You can only increment
  *  data values in any node (You cannot change structure of tree and
  *  cannot decrement value of any node).
  *
  *
  */

 void increment(TreeNode* root,int diff)
 {
	 if(root->left!=NULL)
	 {
		 root->left->val+=diff;
		 increment(root->left,diff);
	 }
	 else if(root->right!=NULL)
	 {
	 	 root->right->val+=diff;
	 	 increment(root->right,diff);
	 }
 }

 void convertTree(TreeNode* root)
 {
	 if(!root  || ((root->left==NULL)&& (root->right==NULL)))
	 {
	   return;
	 }

	 convertTree(root->left);
	 convertTree(root->right);

	 int lvalue=0,rvalue=0;

	 if(root->left)
	 {
		 lvalue=root->left->val;
	 }
	 if(root->right)
	 {
		 rvalue=root->right->val;
	 }

	 int diff=(lvalue+rvalue)-root->val;

	 if(diff>0)
	 {
		 root->val=lvalue+rvalue;
	 }
	 else
	 {
		 increment(root,-diff);
	 }
 }





 int size(TreeNode* root){

	 if(root){
		 return size(root->left)+1+size(root->right);
	 }
	 else{
		 return (0);
	 }

 }


 int countLeafs(TreeNode* root){

	 if(!root)
	 {
		 return 0;
	 }
	 // node is leaf
	 if(root->left==NULL && root->right==NULL)
	 {
		 return (1);
	 }
	 else
	 {
		 return (countLeafs(root->left)+countLeafs(root->right));
	 }
 }


 int minValue(TreeNode* root){
	 TreeNode *current=root;
	 if(current==NULL){
		 return INF;
	 }

	 while(current->left!=NULL){
		 current=current->left;
	 }
	 return (current->val);
 }


 ListNode* getMidPointer(ListNode *head){

     ListNode *n1=head,*n2=head,*res=n1;
     while(n2)
     {
	    if(n2->next)
		  n2=n2->next->next;
        else
		   break;
        if(n1)
        {
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



 int maxH=-1;
 int pre=-1e9;
 /*
  *  Level order Traversal of the tree
  */
 vector<vector<int> > res;


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



     void  maxDepthHelp(TreeNode *root,int h) {

          if(root){

               maxDepthHelp(root->left,h+1);
         	   maxDepthHelp(root->right,h+1);
                maxH=max(maxH,h);

          }

  }
    int maxDepthI(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        maxH=-1;
        maxDepthHelp(root,0);
        return maxH+1;

    }
int maxDepth(TreeNode *root) {

	 if(root==NULL)
	 {
		 return (0);
	 }
	 else{
		 int lDepth=maxDepth(root->left);
		 int rDepth=maxDepth(root->right);
		 if(lDepth>rDepth)
			 return (lDepth+1);
		 else{
			 return (rDepth+1);
		 }
	 }

 }

int height(TreeNode* root){
	if(!root)
	{
		return (0);
	}
	else
	{
		int lheight=height(root->left);
		int rheight=height(root->right);
		return (lheight>rheight)?(lheight+1):(rheight+1);
	}
}
/*
Maximum width of a binary tree
May 15, 2010

Given a binary tree, write a function to get the maximum width of the given tree. Width of a tree is maximum of widths of all levels.

Let us consider the below example tree.

         1
        /  \
       2    3
     /  \     \
    4    5     8
              /  \
             6    7

For the above tree,
width of level 1 is 1,
width of level 2 is 2,
width of level 3 is 3
width of level 4 is 2.

So the maximum width of the tree is 3.
*/

void maxWidthUtil(TreeNode* root,int* M,int h){
  if(root==NULL){
	  return;
  }
  M[h]++;
  maxWidthUtil(root->left,M,h+1);
  maxWidthUtil(root->right,M,h+1);

}



int maxWidth(TreeNode* root){

	int height=maxDepth(root);
	int *M=new int[height];
	for(int i=0;i<height;i++)
	{
		M[i]=0;
	}
	maxWidthUtil(root,M,0);
	int mWidth=-INF;
	for(int i=0;i<height;i++){
		mWidth=(mWidth>M[i])?mWidth:M[i];
	}
	return mWidth;
}

/*
http://www.cs.duke.edu/courses/spring00/cps100/assign/trees/diameter.html
Definition:-
The diameter of a tree (sometimes called the width) is the number of
nodes on the longest path between two leaves in the tree. The diagram
 below shows two trees each with diameter nine, the leaves that form
  the ends of a longest path are shaded (note that there is more than
  one path in each tree of length nine, but no path longer than nine
  nodes)
*/
// this is o(n^2) solution
int diameterN2(TreeNode* root){

	if(!root)
	{
		return (0);
	}

	int lheight=height(root->left);
	int rheight=height(root->right);

	int lDiameter=diameterN2(root->left);
	int rDiameter=diameterN2(root->right);

  return Max((lheight+rheight+1),Max(lDiameter,rDiameter));
}

int diameterUtil(TreeNode* root,int &h)
{
  if(!root)
  {
	  h=0;
	  return (0);
  }
  else
  {   int lHeight=0,rHeight=0;
	  int lDiameter=diameterUtil(root->left,lHeight);
	  int rDiameter=diameterUtil(root->right,rHeight);

	  h=Max(lHeight,rHeight)+1;
	  return Max((lHeight+rHeight+1),Max(lDiameter,rDiameter));
  }
}

int diameter(TreeNode* root){
    int h=0;
	return diameterUtil(root,h);
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

void printLevelOrderZigZag(TreeNode* root)
{

	if(!root)
	{
		return ;
	}

	stack<TreeNode*> currentLevel,nextlevel;

	bool leftToRight=true;
	currentLevel.push(root);

	while(!currentLevel.empty())
	{
		TreeNode* currentNode=currentLevel.top();
		currentLevel.pop();

		if(currentNode)
		{
			std::cout<<" "<<currentNode->val;
			if(leftToRight)
			{
				nextlevel.push(currentNode->left);
				nextlevel.push(currentNode->right);

			}
			else
			{
				nextlevel.push(currentNode->right);
				nextlevel.push(currentNode->left);
			}
		}
		if(currentLevel.empty())
		{
			std::cout<<" "<<std::endl;
			leftToRight=!leftToRight;
			swap(currentLevel,nextlevel);
		}
	}
}






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



 void levelOrder(TreeNode* root){

    if(!root)
   {
     return;
   }
    queue<TreeNode*> Q;
    Q.push(root);

    while(!Q.empty()){
      TreeNode* current=Q.front();
      Q.pop();
      std::cout<<" "<<current->val;
      if(current->left)
      {
        Q.push(current->left);
      }
      if(current->right)
      {
    	  Q.push(current->right);
      }

    }

}


 void printLevelOrder(TreeNode *root) {
   if (!root) return;
   queue<TreeNode*> nodesQueue;
   int nodesInCurrentLevel = 1;
   int nodesInNextLevel = 0;
   nodesQueue.push(root);
   while (!nodesQueue.empty()) {
	   TreeNode *currNode = nodesQueue.front();
     nodesQueue.pop();
     nodesInCurrentLevel--;
     if (currNode) {
       cout << currNode->val << " ";
       nodesQueue.push(currNode->left);
       nodesQueue.push(currNode->right);
       nodesInNextLevel += 2;
     }
     if (nodesInCurrentLevel == 0) {
       cout << endl;
       nodesInCurrentLevel = nodesInNextLevel;
       nodesInNextLevel = 0;
     }
   }
 }


 void reverseLevelOrderTraversal(TreeNode* root)
 {
	 if(!root)
	 {
		 return;
	 }
     queue<TreeNode*> Q;
     vector<TreeNode*> result;
     Q.push(root);

     while(!Q.empty())
     {
    	 TreeNode* current=Q.front();
    	 Q.pop();
    	 result.push_back(current);
    	 if(current->right)
    	 {
    		 Q.push(current->right);
    	 }
    	 if(current->left)
    	 {
    		 Q.push(current->left);
    	 }

     }
     for(vector<TreeNode*>::const_reverse_iterator it=result.rbegin();it!=result.rend();++it)
     {
    	 std::cout<<(*it);
     }
 }



/*
Given a root of a tree, and an integer k. Print all the nodes which are at k distance from root.
 For example, in the below tree, 4, 5 & 8 are at distance 2 from root.

                   1
                 /   \
                2     3
               / \   /
              4   5 8



  */

vector<TreeNode*> nodesAtDistanceK(TreeNode* root,int k){

 if(root==NULL)
	 return vector<TreeNode*>();
 if(k==0){
	 vector<TreeNode*> result;
	 result.push_back(root);
	 return result;
 }

 vector<TreeNode*> left=nodesAtDistanceK(root->left,k-1);
 vector<TreeNode*> right=nodesAtDistanceK(root->right,k-1);
 return left+right;
}


 /*
 Change a tree so that the roles of the
 left and right pointers are swapped at every node.
 So the tree...
        4
       / \
      2   5
     / \
    1   3
       is changed to...
       4
      / \
     5   2
    / \
   3   1
 */


 void mirror(TreeNode* root){

   if(root==NULL)
   {
	   return;
   }
   else
   {
	 mirror(root->left);
	 mirror(root->right);

	 TreeNode* temp=root->left;
	 root->left=root->right;
	 root->right=temp;
  }

}

 /*
  Question:
  Given a binary tree, find out if the tree can be folded or not.

  Definition:-A tree can be folded if left and right subtrees of the tree are
              structure wise mirror image of each other.
              An empty tree is considered as foldable.

  Consider the below trees:
  (a) and (b) can be folded.
  (c) and (d) cannot be folded.

  (a)
         10
       /    \
      7      15
       \    /
        9  11

  (b)
          10
         /  \
        7    15
       /      \
      9       11

  (c)
          10
         /  \
        7   15
       /    /
      5   11

  (d)

           10
         /   \
        7     15
      /  \    /
     9   10  12


 */

 bool isFoldableUtil(TreeNode *l,TreeNode* r){

	 if(l==NULL && r==NULL){
		 return true;
	 }
	 if(l==NULL || r==NULL)
		 return false;

	 return isFoldableUtil(l->left,r->right)&& isFoldableUtil(l->right,r->left);
 }


 bool isFoldable(TreeNode* root){
	 if(root==NULL)
		 return true;
	 return isFoldableUtil(root->left,root->right);

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
  *   Same tree leetcode two trees are identical or not
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
      pre=-1e9;
      return  isValidBSThelp(root);
     }

     /*
      * Recover Binary Search Tree
      *
      */

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

    	  pre=-1e9;
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


int maxSum=-1;
int modifiedTree(TreeNode *root){
	if(!root)
		return 0;
	 int maxLeftSum=0;
	 int maxRightSum=0;
	if(root->left)
		maxLeftSum=max(0,modifiedTree(root->left));
	if(root->right)
		maxRightSum=max(0,modifiedTree(root->right));
	return root->val=root->val+max(maxLeftSum,maxRightSum);
}
void maxPathHelpSum(TreeNode *root){

   if(root){
    int left=(root->left)?root->left->val:0;
    left=max(left,0);
    int right=(root->right)?root->right->val:0;
    right=max(right,0);
    int m=max(left,right);
    maxSum=max(maxSum,root->val+left+right-m);
	maxPathHelpSum(root->left);
	cout<<root->val<<endl;
	maxPathHelpSum(root->right);
   }
}

int maxPathSum(TreeNode *root){
	modifiedTree(root);
    maxPathHelpSum(root);
	 return maxSum;
}


// maxPathSum method 2
int max(int x ,int y) { return x > y ? x : y ; }

    int maxPathSumUtil(TreeNode *root ,  int *maX){
        if(!root) return 0;
        if(!root->left && !root->right ){
           if(*maX < root->val)
             *maX = root->val ;
           return root->val ;
        }

        int l = max(0,maxPathSumUtil(root->left , maX));
        int r = max(0,maxPathSumUtil(root->right , maX));
        int res = max(l,r)+root->val ;

        *maX = max(*maX,l+r+root->val);
        return res ;
    }

   int maxPathSum2(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int maX=-9999999 ;
        maxPathSumUtil(root,&maX);
        return maX;

    }

// Sum Tree Problem


bool isSumProperty(TreeNode* root)
{
	if(!root || (root->left==NULL && root->right==NULL))
	{
		return true;
	}

	int lvalue=0,rvalue=0;
	if(root->left)
		lvalue=root->left->val;
	if(root->right)
		rvalue=root->right->val;

	if(((lvalue+rvalue)==(root->val)) &&
	    isSumProperty(root->left) &&
		isSumProperty(root->right))
	{
		return true;
	}
	else
	{
		return false;
	}

}





/*
 * Question: If you are given two traversal sequences, can you construct the binary tree?
 * Answer:-It depends on what traversals are given. If one of the traversal methods is Inorder
 * then the tree can be constructed, otherwise not.
 *
 */
/*
 * Therefore, following combination can uniquely identify a tree.

 	 Inorder and Preorder.
	 Inorder and Postorder.
	 Inorder and Level-order.

 And following do not.
	Postorder and Preorder.
	Preorder and Level-order.
	Postorder and Level-order.
 */


/*
 *  construct Binary Tree from Inorder and preorder
 */

int *M,*in,*preT;

TreeNode* buildtreeHelp(int preT[],int in[],int n,int offset){
	if(n==0)
		return NULL;
	TreeNode *root=new TreeNode(preT[0]);
	int i=M[preT[0]]-offset;

	root->left=buildtreeHelp(preT+1,in,i,offset);
	root->right=buildtreeHelp(preT+i+1,in+i+1,n-i-1,offset+i+1);
    cout<<" root val="<<root->val<<endl;
	return root;
}


TreeNode*  buildTree(vector<int> &preorder , vector<int> &inorder)
{
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
     M=new int[inorder.size()];
     in=new int[inorder.size()];
     preT= new int[inorder.size()];
     for(int i=0;i<inorder.size();i++){
    	 M[inorder[i]]=i;
    	 in[i]=inorder[i];
    	 preT[i]=preorder[i];
     }
 return buildtreeHelp(preT,in,inorder.size(),0);
 }

//prints Paths



void printPathsUtil(TreeNode* root,int *paths, int level){

	if(!root) return;
	paths[level]=root->val;
	level++;
	//if leaf node then print the path
	if(root->left==NULL && root->right==NULL)
	{
		printArray(paths,level);
	}
	else
	{
		printPathsUtil(root->left,paths,level);
		printPathsUtil(root->right,paths,level);
	}
}
void printPaths(TreeNode* root){

	int *paths=new int[1000];
	printPathsUtil(root,paths,0);
}








/*
 *  Path Sum 2 Leetocde
 */
int list[1000];
vector<int> vcopy(int j){
 vector<int> v;
  for(int i=0;i<=j;i++){
	  v.push_back(list[i]);
  }
  return v;
}

void pathSumHelp (TreeNode *root, int sum,int  j) {
  if(!root) return ;
   list[j]=root->val;
	if(0==(sum-root->val)&&root->left==NULL && root->right==NULL ){
		res.push_back(vcopy(j));
	}
	if(root->left){
		pathSumHelp(root->left,sum-root->val,j+1);
	}
	if(root->right){
			pathSumHelp(root->right,sum-root->val,j+1);
		}
}
vector<vector<int> > pathSumii(TreeNode *root, int sum) {
       // Start typing your C/C++ solution below
       // DO NOT write int main() function
	res.clear();
	pathSumHelp (root,sum,0);
	return res;
   }


bool hasPathSum(TreeNode *root, int sum) {

      // Start typing your C/C++ solution below
      // DO NOT write int main() function
    if(!root) return sum==0;

		if(0==(sum-(root->val))&&root->left==NULL && root->right==NULL ){
			return true;
		}
		bool l=false,r=false;
		if(root->left){
			l=hasPathSum(root->left,(sum-(root->val)));
		}
		if(root->right){
			r=hasPathSum(root->right,(sum-(root->val)));
			}
	return l||r;
  }


/*
 *  minimumDepth Binary Tree
 */
int vminDepth=1E9;
int minDepthhelp(TreeNode *root,int j) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
     if(!root) return (vminDepth>j)?j:vminDepth;

     if(root->left==NULL && root->right==NULL){
         vminDepth=(vminDepth>j+1)?(j+1):vminDepth;
         return vminDepth;
     }
     int l=1e9,r=1e9;
     if(root->left)
     {
         if((j+1)<vminDepth){
   		 l=minDepthhelp(root->left,j+1);
   	  }
   	 else l=vminDepth;
     }
     if(root->right){
   	  if((j+1)<vminDepth){
   	     		 r=minDepthhelp(root->right,j+1);
   	     	  }
   	     else r=vminDepth;
     }
     return (l<r)?l:r;
  }

int minDepth(TreeNode *root) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      vminDepth=1E9;
     return minDepthhelp(root,0);

  }

/*
 *  Binary Tree isBalanced leetCode
 */
bool isBalancedhelp(TreeNode *root,int &h) {

	if(!root)
	{
	  h=0;
	  return true;
	}
    int l=0,r=0;

    bool lb=isBalancedhelp(root->left,l);
	bool rb=isBalancedhelp(root->right,r);

	h=max(l,r)+1;

	if(abs(l-r)<=1)
	{
		return lb&&rb;
	}
	else
		return false ;
 }
 bool isBalanced(TreeNode *root) {
  int h=0;
   return isBalancedhelp(root,h);

 }



// flaten binary tree
void flatten(TreeNode *tree) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    if(!tree) return;

    TreeNode *left=tree->left,*right=tree->right;

	tree->left=NULL;
	tree->right=left;

	TreeNode *rightmost=left;
	if(left){
	  while(rightmost->right)rightmost=rightmost->right;
    }

	if(rightmost)
       rightmost->right=right;
     else
        tree->right=right;
	flatten(tree->right);
  }



/*
For each node in a binary search tree,
create a new duplicate node, and insert
the duplicate as the left child of the original node.
The resulting tree should still be a binary search tree.
So the tree...
  2
 / \
1   3
Is changed to...
      2
     / \
    2   3
   /   /
  1   3
 /
1
 *
*/

void doubleTree(TreeNode* tree){
	if(tree==NULL)
		return ;
	else
	{
		doubleTree(tree->left);
		doubleTree(tree->right);
		TreeNode* oldLeft=tree->left;
		tree->left=new TreeNode(tree->val);
		tree->left->left=oldLeft;
	}

}
/* Question:
 * To delete a tree we must traverse all the nodes of the tree and delete them one by one.
 *  So which traversal we should use – Inorder or Preorder or Postorder.
 *  Answer is simple – Postorder, because before deleting the parent node we should
 *  delete its children nodes first
 * We can delete tree with other traversals also with extra space complexity but why
 * should we go for other traversals if we have Postorder available which does the work
 *  without storing anything in same time complexity
 */
void deleteTree(TreeNode *root){
	if(!root)
		return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

/*
 * Sorted order printing of a given array that represents a BST
Given an array that stores a complete Binary Search Tree, write a
function that efficiently prints the given array in ascending order.
For example, given an array [4, 2, 5, 1, 3], the function should
print 1, 2, 3, 4, 5

*/




void testForLevelOrderTraversal()
{
/*                     10
 *                    /  \
 *                   6    14
 *                  / \   /  \
 *                 2   9 13   15
 *                /   / /       \
 *               1   8 11        18
 *              /   /          /
 *             0   7           17
 *
 *
 *
 * outPut:-
 *         10 6 14 2 9 13 15 1 8 11 18 0 7 17
 */


 TreeNode* tree=NULL;
 insert(&tree,10);
 insert(&tree,14);
 insert(&tree,13);
 insert(&tree,15);
 insert(&tree,18);
 insert(&tree,17);
 insert(&tree,6);
 insert(&tree,2);
 insert(&tree,1);
 insert(&tree,0);
 insert(&tree,9);
 insert(&tree,11);
 insert(&tree,8);
 insert(&tree,7);
 levelOrder(tree);
}

void testForReverseLevelOrderTraversal(){
	/*                     10
	 *                    /  \
	 *                   6    14
	 *                  / \   /  \
	 *                 2   9 13   15
	 *                /   / /       \
	 *               1   8 11        18
	 *              /   /          /
	 *             0   7           17
	 *
	 *
	 *
	 * outPut:-
	 *         [0] [7] [17] [1] [8] [11] [18] [2] [9] [13] [15] [6] [14] [10]
	 */


	 TreeNode* tree=NULL;
	 insert(&tree,10);
	 insert(&tree,14);
	 insert(&tree,13);
	 insert(&tree,15);
	 insert(&tree,18);
	 insert(&tree,17);
	 insert(&tree,6);
	 insert(&tree,2);
	 insert(&tree,1);
	 insert(&tree,0);
	 insert(&tree,9);
	 insert(&tree,11);
	 insert(&tree,8);
	 insert(&tree,7);
	 reverseLevelOrderTraversal(tree);

}

void isSumPropertyTestCase(){
/*
 *         10
 *        /  \
 *       8    2
 *      / \
 *     5   3
 *
 *
 *
 */

	TreeNode tree(10);
	tree.setLeft(8);
	tree.setRight(2);
	tree.left->setLeft(5);
	tree.left->setRight(3);
    std::cout<<"val="<<isSumProperty(&tree);
    levelOrder(&tree);
}



int main(){
    //testForLevelOrderTraversal();
    //isSumPropertyTestCase();
	testForReverseLevelOrderTraversal();
	return (0);
}








