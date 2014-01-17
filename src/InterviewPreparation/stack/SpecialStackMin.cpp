//
//  SpecialStack.cpp
//  practice
//
//  Created by Chiranjit on 4/4/13.
//  Copyright (c) 2013 TCS. All rights reserved.
//

#include "SpecialStack.h"

void SpecialStack::push(int x){
    if(isFull()){
        printf("Over flow");
        
    }
    else{
        if(isEmpty()){
            min.push(x);
           
        }
        else{
            int y=min.pop();
            min.push(y);
            if(x<=y)
                min.push(x);
          
        }
          Stack::push(x);
    }
    
}

int SpecialStack::pop(){
    int res=-1;
    if(!isEmpty()){
        res=Stack::pop();
        int y=min.pop();
       
        if(res!=y){
            min.push(y);
        }
    }
    return res;
}


int SpecialStack::getMin(){
    int res=INT_MAX;
    if(!isEmpty()){
        res=min.pop();
    }
    return res;
}
