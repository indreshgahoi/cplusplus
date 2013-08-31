//
//  SpecialStack.h
//  practice
//
//  Created by Chiranjit on 4/4/13.
//  Copyright (c) 2013 TCS. All rights reserved.
//

#ifndef __practice__SpecialStack__
#define __practice__SpecialStack__

#include <iostream>
#include "Stack.h"
#include <climits>
class SpecialStack:public Stack
{
    Stack min;
public:
    
    void push(int);
    int pop();
    int getMin();
};

#endif /* defined(__practice__SpecialStack__) */
