//
//  Stack.h
//  practice
//
//  Created by Chiranjit on 4/4/13.
//  Copyright (c) 2013 TCS. All rights reserved.
//

#ifndef __practice__Stack__
#define __practice__Stack__

#include <iostream>
#include <sstream>
#define MAXSIZE 100
class Stack{

    void addAtBottom(int);
public:
    int top;
    int container[MAXSIZE];
    Stack();
    bool isFull();
    bool isEmpty();
    void push(int);
    int pop();

    void reverse();
    
};

#endif /* defined(__practice__Stack__) */
