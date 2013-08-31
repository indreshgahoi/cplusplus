/*
 * isValidPalindrome.cpp
 *
 *  Created on: Jan 19, 2013
 *      Author: indresh
 */
#include<iostream>
#include<string>
using namespace std;
#define isLower(a) (((a)<='z' && (a)>='a'))
#define isUper(a) (((a)<='Z' && (a)>='A'))
#define isNumeric(a) (((a)<='9' && (a)>='0'))

 bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

    int i=0,j=s.length()-1;

        while(i<j)
        {
            while(i<s.length() && !(isLower(s[i]) || isUper(s[i]) || isNumeric(s[i])))i++;

            while(j>=0 && !(isLower(s[j]) || isUper(s[j]) || isNumeric(s[j])))j--;

            if(i>=j)
             return true;
            if(!(s[i]==s[j] || s[i]+32==s[j] || s[i]==s[j]+32))
            return false;
            i++;j--;

        }
        return true;
    }
int main(){
	string s;
	while(true){
		cin>>s;
		cout<<"\n"<<isPalindrome(s);
	}
	return 0;
}
