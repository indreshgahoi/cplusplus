/*
 * stack.h
 *
 *  Created on: Oct 28, 2013
 *      Author: Indresh Gahoi
 */

#ifndef STACK_H_
#define STACK_H_

#include<stdlib.h>
typedef struct stack Stack;

void Init(Stack *s ,size_t capacity);
void push(Stack *s , void *elem);
void pop(Stack *s);
void* top(Stack *s);
#endif /* STACK_H_ */
