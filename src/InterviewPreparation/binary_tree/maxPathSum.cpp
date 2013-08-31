/*
 * maxPathSum.cpp
 *
 *  Created on: Jan 19, 2013
 *      Author: indresh
 */

/* LeetCode Question
 * Binary Tree MaximumPath Sum
 * Given a binary tree, find the maximum path sum.
 * The path may start and end at any node in the tree.
 *
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>

using  namespace std;

class TreeNode{
	public:
	   int val;
	   TreeNode *left;
	   TreeNode *right;
	   TreeNode(int x):val(x),left(NULL),right(NULL){
		   }
};

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


/*
 *  construct Binary Tree from Inorder and preorder
 */

int *M,*in,*pre;

TreeNode *buildtreeHelp(int pre[],int in[],int n,int offset){
	if(n==0)
		return NULL;
	TreeNode *root=new TreeNode(pre[0]);
	int i=M[pre[0]]-offset;

	root->left=buildtreeHelp(pre+1,in,i,offset);
	root->right=buildtreeHelp(pre+i+1,in+i+1,n-i-1,offset+i+1);
    cout<<" root val="<<root->val<<endl;
	return root;
}


TreeNode*  buildTree(vector<int> &preorder , vector<int> &inorder)
{
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
     M=new int[inorder.size()];
     in=new int[inorder.size()];
     pre= new int[inorder.size()];
     for(int i=0;i<inorder.size();i++){
    	 M[inorder[i]]=i;
    	 in[i]=inorder[i];
    	 pre[i]=preorder[i];
     }
 return buildtreeHelp(pre,in,inorder.size(),0);
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
vector<vector<int> > res;
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
    if(!root) return false;

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
int vminDepth=1E10;
int minDepthhelp(TreeNode *root,int j) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
     if(!root) return (vminDepth>j)?j:vminDepth;

     if(root->left==NULL && root->right==NULL){
         vminDepth=(vminDepth>j+1)?(j+1):vminDepth;
         return vminDepth;
     }
     int l=1e10,r=1e10;
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
      vminDepth=1E10;
     return minDepthhelp(root,0);

  }

/*
 *  Binary Tree isBalanced leetCode
 */
bool isBalancedhelp(TreeNode *root,int &h) {

   if(!root){
	   h=0;
		return true;
	}
	if(root->left==NULL && root->right==NULL){
		h=1;
		return true;
	}
   int l=0,r=0;
   bool lb=true,rb=true;
    if(root->left)
    {
     lb=isBalancedhelp(root->left,l);
   	 h++;
    }
	if(root->right)
	{
         rb=isBalancedhelp(root->right,r);
		 h++;
	}
	h=max(l,r)+1;
	if((abs(l-r)==1 || abs(l-r)==0)){
		 return lb&&rb;
	}
	 else
	return false ;
 }
bool isBalanced(TreeNode *root) {
int h=0;
return isBalancedhelp(root,h);

  }






void inOrderTraversal(TreeNode *root){
	if(root){
		inOrderTraversal(root->left);
		cout<<" "<<root->val;
		inOrderTraversal(root->right);
	}
}



void preTraversal(TreeNode *root){
	if(root){
		cout<<" "<<root->val;
		preTraversal(root->left);
		preTraversal(root->right);
	}
}



int main(){
	TreeNode *root=new TreeNode(1);
//	root->left=new TreeNode(2);
//	root->right=new TreeNode(3);
//	cout<<maxPathSum(root)<<endl;
//	vector<int> in;
//	vector<int> pre;
//	in.push_back(2);
//	in.push_back(3);
//	in.push_back(4);
//	in.push_back(5);
//	in.push_back(7);
//	in.push_back(8);
//	in.push_back(9);
//	pre.push_back(5);
//	pre.push_back(3);
//	pre.push_back(2);
//	pre.push_back(4);
//	pre.push_back(8);
//	pre.push_back(7);
//	pre.push_back(9);
	//in.push_back(0);
//	in.push_back(2);
//	in.push_back(1);
//	in.push_back(3);
//	//in.push_back(3);
////	in.push_back(7);
////	in.push_back(8);
//	pre.push_back(1);
//	pre.push_back(2);
//
//	pre.push_back(3);
//	pre.push_back(0);

//	pre.push_back(8);
//	pre.push_back(7);

//	TreeNode *tree=buildTree(pre,in);
	//cout<<endl<<"InOdrder :"<<endl;
	//inOrderTraversal(tree);
//	cout<<endl<<"preOdrder :"<<endl;
//	preTraversal(tree);
	//cout<<pathSum(root,1);
	return 0;
}
