/*
 * searchIn2DMatrix.cpp
 *
 *  Created on: Mar 27, 2013
 *      Author: indresh
 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<sstream>
using namespace std;



bool searchMatrix(vector<vector<int> > &matrix, int target) {
 if(matrix.size()==0) return false;
 int row=matrix.size(),col=matrix[0].size();
  int j=col-1,i=0;
  while(i<row && j>=0){
	  if(matrix[i][j]==target)
		  return true;
	  if(target>matrix[i][j])
		  i++;
	  else
		  j--;

  }
  return false;

 }


 int main(){
	 return 0;
 }


