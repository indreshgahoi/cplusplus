/*
 * QueueUsingStack.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/stack/QueueUsingStack.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 5, 2013
 *      Author: Indresh Gahoi
 */
/*A queue can be implemented using two stacks. Let queue to be implemented be q and stacks used to implement q be
 *  stack1 and stack2. q can be implemented in two ways:
 *
 */

/* Method 1
 *
 *This method makes sure that newly entered element is always at the top of stack 1, so that deQueue operation
 *just pops from stack1. To put the element at top of stack1, stack2 is used.

enQueue(q, x)
  1) While stack1 is not empty, push everything from satck1 to stack2.
  2) Push x to stack1 (assuming size of stacks is unlimited).
  3) Push everything back to stack1.

dnQueue(q)
  1) If stack1 is empty then error
  2) Pop an item from stack1 and return it
 *
 *
 */
/* Method 2 :
 * Method 2 (By making deQueue operation costly)
In this method, in en-queue operation, the new element is entered at the top of stack1. In de-queue operation,
 if stack2 is empty then all the elements are moved to stack2 and finally top of stack2 is returned.

enQueue(q,  x)
  1) Push x to stack1 (assuming size of stacks is unlimited).

deQueue(q)
  1) If both stacks are empty then error.
  2) If stack2 is empty
       While stack1 is not empty, push everything from satck1 to stack2.
  3) Pop the element from stack2 and return it.

Method 2 is definitely better than method 1. Method 1 moves all the elements twice in enQueue operation,
while method 2 (in deQueue operation) moves the elements once and moves elements only if stack2 empty.
 *
 */

/* Method 3 (Use Function call stack)
 * Queue can also be implemented using one user stack and one Function Call Stack.
Below is modified Method 2 where recursion (or Function Call Stack) is used to implement queue using only one user defined stack.

enQueue(x)
  1) Push x to stack1.

deQueue:
  1) If stack1 is empty then error.
  2) If stack1 has only one element then return it.
  3) Recursively pop everything from the stack1, store the popped item
    in a variable res,  push the res back to stack1 and return res

The step 3 makes sure that the last popped item is always returned and since the recursion stops when there is only one item in stack1 (step 2), we get the last element of stack1 in dequeue() and all other items are pushed back in step 3.

Implementation of method 2 using Function Call Stack:
 *
 */

/* Implement Queue using Method 2 */
#include<iostream>
#include<cstdio>
#include "Stack.h"
using namespace std ;

class Queue1{
public :
	void pop();
	void push(int);
    bool isEmpty() ;
private:
    Stack s1 ;
    Stack s2 ;
};


bool Queue1::isEmpty(){
	return (s1.isEmpty() && s2.isEmpty());
}
void Queue1::push(int x){
  this->s1.push(x);
}

void Queue1::pop(){
	if(this->s1.isEmpty() && this->s2.isEmpty()){
		printf("Queue is Empty");
		exit(1);
	}
	if(!this->s2.isEmpty()){
		s2.pop();
	}
	else
	{
		while(!s1.isEmpty()){
			s2.push(s1.pop());
		}
	}
}

