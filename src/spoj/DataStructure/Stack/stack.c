/*
 * stack.c
 *
 *  Created on: Oct 28, 2013
 *      Author: Indresh Gahoi
 */

#include "stack.h"
#include<stdio.h>


typedef struct stack{
	size_t capacity;
	void **items;
	size_t size;
}Stack;


void Init(Stack *st ,size_t capacity)
{
	st->size = 0 ;
	st->capacity = capacity ;
	st->items = malloc(sizeof(void *)* st->capacity) ;
}

void push(Stack *S , void *item){

	if(S->size == S->capacity)
	{
		printf("Stack is Full") ;

	}
	else
	{
		S->items[S->size++] = item;
	}
	return ;
}

void pop(Stack *S)
{
	if(S->size == 0)
	{
		printf("Stack is Empty cant pop");
		return ;
	}
	else
	{
		S->size--;
	}
	return ;
}

void* top(Stack *S)
{
	if(S->size==0)
	{
		printf("Stack is Empty");
		exit(0);
	}
	else
	{
		return S->items[S->size-1];
	}

}
