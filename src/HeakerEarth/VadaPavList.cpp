/*
 * VadaPavList.cpp
 *
 *  Created on: Oct 4, 2014
 *      Author: indresh
 */

#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<cstring>

using namespace std;
int count = 0;
int noOfChildres;

struct node {
	bool isEnd;
	struct node* child[26];
	char name[6] ;
};
node *tree;
char glName[6] ;

void _add(node **tree, const char *word) {
	if ((*tree) == 0) {
		*tree = new node();
		(*tree)->isEnd = false;
		for (int i = 0; i < noOfChildres; ++i) {
			(*tree)->child[i] = 0;
		}

	}

	if (*word != '\0') {
		_add(&(*tree)->child[(*word)-'a'], word + 1);
	} else {
		(*tree)->isEnd = true;
	    strcpy((*tree)->name,glName);
		count++;
	}
}
bool _find(node *tree, const char *word) {
	if (*word == '\0') {
		return tree->isEnd;
	}
	if (tree->child[(*word)-'a'] != 0) {
		return _find(tree->child[(*word)-'a'], word + 1);
	} else {
		return false;
	}
}
void init_tree() {
	tree = new node();
	tree->isEnd = true;
	noOfChildres = 26;
	for (int i = 0; i < noOfChildres; ++i) {
		tree->child[i] = 0;
	}
}

void addWord(const std::string &str) {
	const char *word = str.c_str();
	_add(&tree, word);
}

void traverse(node * tree) {
	if (tree == 0) {
		return;
	}
	if (tree->isEnd) {
		printf("%s\n",tree->name);
	}
	for (int i = 0; i < noOfChildres; ++i) {
		traverse(tree->child[i]);
	}
}

int main() {
	int N;
	scanf("%d", &N);
	init_tree();
	for (int i = 0; i < N; ++i) {
		char name[6];
		scanf("%s", name);
		strcpy(glName,name);

		if (!_find(tree, name)) {
             _add(&tree,name);
		}

	}
	printf("%d",count);
	vector<char> str ;
	traverse(tree);
	return 0;
}

