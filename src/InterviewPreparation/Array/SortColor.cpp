/*
 * setColor.cpp
 *
 *  Created on: Mar 27, 2013
 *      Author: indresh
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<sstream>
using namespace std;

/*
 *Given an array with n objects colored red, white or blue, sort them so
 *that objects of the same color are adjacent, with the colors in the
 *order red, white and blue.
 *order.Here, we will use the integers 0, 1, and 2 to represent the
 * color red, white, and blue respectively.
 */

#define red 0
#define white 1
#define blue 2

void sortColors(int A[], int n) {

	int l=0,m=0,r=n-1;
	while(m<=r){
		switch(A[m]){
		case red:
			swap(a[l],a[m]);l++;m++;
		break;
		case white:m++;
			break;
		case blue:
			swap(a[m],a[r]);r--;
		break;

		}
	}


}


int main(){
	return 0;
}


