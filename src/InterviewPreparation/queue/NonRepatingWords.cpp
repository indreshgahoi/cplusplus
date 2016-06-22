/*
 * NonRepatingWords.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/queue/NonRepatingWords.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 24, 2013
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

#define FOR(_i,a,b) for(int _i=a;_i<b;_i++)
#define REP(_i,n)    for(int _i=0;_i<n;_i++)
#define debug(x) cout<<#x" "<<x;
#define nl cout<<"\n";
#define tab cout<<"		";
void driver();
void printArray(int A[], size_t size) {
	printf("values= [");
	for (int i = 0; i < size - 1; i++)
		printf("%d ,", A[i]);
	printf("%d]\n", A[size - 1]);
}
template<class T>
ostream& operator<<(ostream &out, const vector<T>& V) {
	out << "[";
	for (typename vector<T>::const_iterator it = V.begin(); it != V.end();
			it++) {
		out << " " << *it;
	}
	out << "]" << endl;
	return out;
}
void getInput(vector<int> &v) {
#define ARRAYSIZE(A) sizeof(A)/sizeof(A[0])
	int arr[] = { -1, -1, -1, 1, 1 };
	int size = ARRAYSIZE(arr);
	for (int iter = 0; iter < size; ++iter) {
		v.push_back(arr[iter]);
	}
}
/*
 Link :-
 Question :-


 */

#define NO_OF_CHAR 256
struct dll_node {
	struct dll_node *next;
	struct dll_node *pre;
	dll_node(const string &str) :
		next(0), pre(0) {
		this->str = str;
	}
	string str;

};
void traverse(dll_node *t) {
	cout << "[";
	while (t) {
		cout << " " << t->str;
		t = t->next;
	}
	cout << " ]\n";
}
struct trie_node {
	bool isEnd;
	bool toRemoveFromDll;
	dll_node *root;
	vector<trie_node*> children;

	trie_node() :
			isEnd(false), root(0), toRemoveFromDll(false) {
		children.resize(NO_OF_CHAR, 0);
	}
};

class Trie {

	void push(dll_node *t) {
		t->next = this->start;
		if (this->start) {
			this->start->pre = t;
		}
		this->start = t;
	}
	void deattach(dll_node* t) {
		if (t->pre) {
			t->pre->next = t->next;
		} else {
			this->start = t->next;
		}
		if (t->next) {
			t->next->pre = t->pre;
		}
	}
public:
	Trie() :
		start(0) {
		root = new trie_node();
	}
	dll_node* getDll() {
		return this->start;
	}
	bool insert(const string &word) {
		int level = word.size();
		trie_node **child, *t;
		t = root;
		for (int i = 0; i < level; ++i) {
			child = &t->children[word[i]];
			if ((*child) == 0) {
				(*child) = new trie_node();
			}
			t = (*child);
		}
		bool res = false;
		t->isEnd = true;
		if (!t->toRemoveFromDll) {
			t->root = new dll_node(word);
			push(t->root);
			t->toRemoveFromDll = true;
			res = true;
		} else {
			if (t->root) {
				deattach(t->root);
				delete t->root;
				t->root = 0;
			}
		}
		return res;
	}
private:
	trie_node *root;
	dll_node *start;
};
class Solution {

public:
	dll_node* getNonRepeatedList(fstream &fin) {
		string str;
		Trie t;
		while (fin >> str) {
			bool r = t.insert(str);
			cout << " " << str << " ";
			if (r) {
				cout << "inserted to list\n";
			} else {
				cout << "already in list and removed if present\n";
			}
		}
		return t.getDll();
	}

};
void driver() {
	fstream fin("input.txt");
	Solution solver;
	dll_node * t = solver.getNonRepeatedList(fin);
	traverse(t);
}
/*
 input.txt 

 */
int main() {
	driver();
	cout << "\n";
	return 0;
}
