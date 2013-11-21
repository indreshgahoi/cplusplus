/*
 * ConstructionOfBSTFronInPre.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/binary_tree/ConstructionOfBSTFronInPre.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 7, 2013
 *      Author: Indresh Gahoi
 */


#include<iostream>
#include<cstdio>

using namespace std ;

struct TreeNode {
	int val ;
	struct node *left ;
	struct node *right ;
	TreeNode(int x):val(x),left(NULL),right(NULL)
	{

	}
};

int search(int *in ,int st , int end , int key);

struct TreeNode* buildTreeFronInPre(int *pre , int *in , int inStart ,int inEnd){

 if(inStart > inEnd)
	 return NULL ;

   static int preindex = 0;
   TreeNode *root = new TreeNode(pre[preindex++]);

   // base cae
   if(inStart == inEnd)
	   return root ;

   int IndexInInorder = search(in,st,end,root->val);
   root->left = buildTreeFronInPre(pre,in,st,IndexInInorder-1);
   root->right = buildTreeFronInPre(pre,in,IndexInInorder+1,end);
 return root ;
}

class InorderPreorder{
map<int,int> M ;

TreeNode* buildtreeHelp(vector<int>::iterator pre,vector<int>::iterator in,int size,int start){
	if(size==0)
		return NULL;
	TreeNode *root=new TreeNode(*pre);
	int i=M[*pre]-start ;

	root->left=buildtreeHelp(pre+1,in,i,start);
	root->right=buildtreeHelp(pre+i+1,in+i+1,size-i-1,start+i+1);
    //cout<<" root val="<<root->val<<endl;
	return root;
}


TreeNode*  buildTree(vector<int> &preorder , vector<int> &inorder)
{
      // Start typing your C/C++ solution below
      // DO NOT write int main() function


     for(int i=0;i<inorder.size();i++){
    	 M[inorder[i]]=i;

     }
 return buildtreeHelp(preorder.begin(),inorder.begin(),inorder.size(),0);
 }

};

class InorderPostorder{
map<int,int> M ;

TreeNode* buildtreeHelp(vector<int> post,vector<int>::iterator in,int size,int start ){
	if(size==0)
		return NULL;
	TreeNode *root=new TreeNode(post[last]);
	int i=M[post[last]]-start ;

	root->right=buildtreeHelp(post,in+i+1,size-i-1,start+i+1);
	root->left=buildtreeHelp(post,in,i,start);

    //cout<<" root val="<<root->val<<endl;
	return root;
}


TreeNode*  buildTree(vector<int> &postorder , vector<int> &inorder)
{
      // Start typing your C/C++ solution below
      // DO NOT write int main() function


     for(int i=0;i<inorder.size();i++){
    	 M[inorder[i]]=i;

     }
 return buildtreeHelp(postorder,inorder.begin(),inorder.size(),0);
 }

};



























