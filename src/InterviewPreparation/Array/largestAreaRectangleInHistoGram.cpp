/*
 * largestAreaRectangleInHistoGram.cpp
 *
 *  Created on: Mar 20, 2013
 *      Author: indresh
 */
#include <iostream>
#include <string>
#include<vector>
#include <stack>
using namespace std;
/*
 *  we need to maintain such data-structure
 *  non-decreasing list of bar height
 */
int largestRectangleArea(vector<int> &height) {
	int i=0;
	int maX=0,count=0;;
	stack<int> st;
	while(i<height.size()){
		if(st.empty()|| height[i]>=st.top()){
			st.push(height[i]);
		}
		else{
			count=0;
			while(!st.empty() && st.top()>height[i]){
				int top=st.top();
				st.pop();
				count++;
				maX=max(maX,count*top);
			}
			for(int t=0;t<count+1;t++){
				st.push(height[i]);
			}
		}
		i++;
	}
	count=0;
	while(!st.empty()){
		int top=st.top();
		st.pop();
		count++;
		maX=max(maX,top*count);
	}
	return maX;
}


