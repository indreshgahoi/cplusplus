/*
 *  Parenthesis checke.cpp
 *
 *  Created on: Oct 30, 2013
 *      Author: Indresh Gahoi
 */


#include<iostream>
#include<stack>
#include<string>

using namespace std ;

bool  ParenthesisChecker(string &exp){

	stack<char> st ;

    int i =0;
    while(exp[i]!='\0'){
    	if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
    	 st.push(exp[i]);
    	}
    	else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
    		if(st.empty()){
    			return false ;
    		}
    		else
    		{
    			char top = st.top();
    			bool valid = false ;
    			st.pop();
    			if((exp[i]==')' && top=='('))
    				valid =  true ;
    			else if((exp[i]=='}' && top=='{'))
    			    valid =  true ;
    			else if((exp[i]==']' && top=='['))
    			    valid =  true ;
    			if(!valid)
    				return false ;

    		}

    	}
       i++ ;
    }

    return st.empty();

}

void test_0_ParenthesisChecker(){
   string str("{()}[]");
   if(ParenthesisChecker(str)){
	   cout<<"test 0 is valid \n";
   }
   else
   {
	   cout<<"test 0 is not valid \n";
   }
}
void test_1_ParenthesisChecker(){
	string str("{()}[");
	   if(ParenthesisChecker(str)){
		   cout<<"test 1 is valid \n";
	   }
	   else
	   {
		   cout<<"test 1 is not valid \n";
	   }
}
int main(){
	test_0_ParenthesisChecker();
	test_1_ParenthesisChecker();
	return 0 ;
}
