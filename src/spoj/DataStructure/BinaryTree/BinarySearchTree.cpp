/*
 * BinarySearchTree.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/spoj/DataStructure/BinaryTree/BinarySearchTree.cpp -o /usr/build/Main.o
 *
 *  Created on: Jan 27, 2014
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<climits>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>

using namespace std;

typedef int KeyType ;

struct TreeNode
{
	KeyType key ;
	TreeNode *left,*right ;
	TreeNode(KeyType key_):left(0),right(0),key(key_){}
};


class BinarySearchTree {
public:
	BinarySearchTree(){root_ = 0 ;};
	virtual ~BinarySearchTree();
	void Insert(KeyType key);
	TreeNode* Find(KeyType key) ;
	void Delete(KeyType key) ;
private :
	TreeNode *root_ ;
};


TreeNode* InsertUtil(TreeNode *root,KeyType key)
{
	if(root==0)
	{
		root = new TreeNode(key) ;
		return root ;
	}
	if(key<root->key)
	{
		root->left = InsertUtil(root->left,key) ;
	}
	else if(key>root->key)
	{
		root->right = InsertUtil(root->right,key) ;
	}
	return root ;
}

TreeNode* BinarySearchTree::Find(KeyType key)
{
  TreeNode *root = root_ ;
    while(root)
    {
    	if(root->key == key) break ;

    	if(key<root->key)
    		root = root->left ;
    	else if(key > root->key)
    		root = root->key ;

    }
	return root ;
}

TreeNode* Minimum(TreeNode *root)
{
	while(root->left)
		root = root->left ;
	return root ;
}

TreeNode* DeleteUtil(TreeNode *root , KeyType key)
{
	if(!root) return 0;

	if(key<root->key)
	{
		root->left = DeleteUtil(root->left,key) ;
	}
	else if(key>root->key)
	{
		root->right = DeleteUtil(root->right,key) ;
	}
	else
	{
            TreeNode *curr  ;
            if(root->left && root->right)
            {
            	curr = Minimum(root->right) ;
            	root->key = curr->key ;
            	root->right = DeleteUtil(root->right,curr->key) ;
            }
            else
            {
            	curr = root ;
            	if(root->left==0)
            		root = curr->right ;
            	else if(root->right==0)
            		root  = root->left ;
            	delete curr ;

            }
	}
	return root ;
}


void BinarySearchTree::Insert(KeyType key)
{
      root_ = InsertUtil(root_,key) ;
}















