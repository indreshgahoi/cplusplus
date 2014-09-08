/*
 * ReverseInteger.cpp
 *
 *  Created on: Jun 11, 2014
 *      Author: root
 */

#include<iostream>
#include<cstdio>
using namespace std;

class Solution {
public:
	int reverse(int x) {
        int sign = 1 ;
        if(x < 0 ){
        	sign = -1 ;
        	x = -x ;
        }
		int res = 0 ;
		while (x > 0) {
			res = (x % 10) + res * 10;
			x /= 10 ;
		}
		return res * sign ;
	}
};

