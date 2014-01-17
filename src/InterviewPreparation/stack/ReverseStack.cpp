/*
 * ReverseStack.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/stack/ReverseStack.cpp -o /usr/build/Main.o
 *
 *  Created on: Dec 29, 2013
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


struct node
{
	int data ;
	struct node *next ;
};
class Stack
{
 public :
	void push(int x);
	int top();
	int pop() ;
	bool empty() ;
	int size() ;

 private:
	struct node *_top ;
	size_t _size ;
};

void addAtBottom(Stack &s , int x)
{
  if(s.empty())
  {
	  s.push(x) ;
   return ;
  }
  int y = s.pop();
  addAtBottom(s,x);
  s.push(y);

}

void reverse(Stack &s)
{
	if(s.empty()) return ;
	int x = s.pop() ;
	reverse(s);
	addAtBottom(s,x);

}

