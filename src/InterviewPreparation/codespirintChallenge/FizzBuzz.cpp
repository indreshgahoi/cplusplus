/*
 * FizzBuzz.cpp
 *
 *  Created on: Feb 2, 2013
 *      Author: indresh
 */

#include <iostream>
#include<string>

#define p(t) cout<<(t)<<endl
using namespace std;
string r,a="Fizz",b="Buzz";
int main() {
    for(int i=1;i<101;i++){bool f=((i%3)==0),s=((i%5)==0);r="";
    (f && s)?(r=a+b):(f)?(r=a):(s)?(r=b):(r=="")?p(i):p(r);}
    return 0;
}



