//
//  Stack.cpp
//  practice
//
//  Created by Chiranjit on 4/4/13.
//  Copyright (c) 2013 TCS. All rights reserved.
//

#include "Stack.h"
#include <sstream>
Stack::Stack(){
    top=-1;
}

void Stack::push(int ele){
    if(top==(MAXSIZE-1)){
        printf("overflow");
    }
    else
    {
    top++;
        container[top]=ele;
    }
}

int Stack::pop(){
    int res=-1;
    if(top==-1){
        printf("underflow");
    }
    else{
        res=container[top];
        top--;
    }
    return res;
}


bool Stack::isFull(){
    if(top==(MAXSIZE-1)){
        return true;
    }
    return false;
}

bool Stack::isEmpty(){
    if(top==-1){
        return true;
    }
    return false;
}

void Stack::addAtBottom(int x){
	if(isEmpty()){
		push(x);
		return;
	}
	int y=pop();
	addAtBottom(x);
	push(y);
}

void Stack::reverse(){
	if(isEmpty()) return;
	int x=pop();
	reverse();
	addAtBottom(x);
}


