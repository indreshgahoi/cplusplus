/*
 * StactDriver.cpp
 *
 *  Created on: Apr 5, 2013
 *      Author: root
 */

#include "constant.h"
#include "Stack.h"
#include "Stack.cpp"

std::ostream& operator<<(std::ostream &out,const Stack &s){
        out<<"[";
        for(int i=0;i<s.top+1;i++)
        	out<<" "<<s.container[i];
        out<<"]"<<std::endl;
    	return out;
}

void driver(){

Stack myStack;

myStack.push(1);
myStack.push(4);
myStack.push(3);
myStack.push(6);
myStack.push(8);
myStack.push(5);
cout<<myStack;
myStack.reverse();
cout<<"reverse Stack"<<endl;
cout<<myStack;
}


