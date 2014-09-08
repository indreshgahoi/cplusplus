/*
 * IsPalindrome.cpp
 *
 *  Created on: Jun 10, 2014
 *      Author: Indresh Gahoi
 */

#include<iostream>
using namespace std;

class Solution {
public:

	bool isPalindromeHelper(int x, int &number) {
		if (x < 10) {
			return (number% 10) == x;
		}
		bool ret = isPalindromeHelper(x / 10, number);
		number = number / 10;

		if (ret) {
			ret = ret & ((x % 10) == (number % 10));
		}
		return ret;

	}
	bool isPalindrome(int x) {
		int dup = abs(x) ;
		return isPalindromeHelper(abs(x), dup);
	}
};

class Solutio1 {
public :
	bool isPalindromeHelper(int x , int y){
		if(x < 0) return false ;
		if( x == 0 ) return true ;

		if(isPalindromeHelper(x/10,y) && (x %10) == (y % 10)){
			y /= 10 ;
			return true ;
		}
		return false ;
	}
	bool isPalindrome(int x){
     return isPalindromeHelper(x,x);
	}
};

int main() {

}

