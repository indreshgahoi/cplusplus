/*
 * setZeroInMatrix.cpp
 *
 *  Created on: Mar 27, 2013
 *      Author: indresh
 */
#include<iostream>
#include <cstdio>
#include <vector>
#include <sstream>
using namespace std;

void setZeroes(vector<vector<int> > &matrix) {
 if(matrix.size()==0) return;
 int m=matrix.size(),n=matrix[0].size();

 bool rowHas0=false;
 bool colHas0=false;
 for(int i=0;i<m;i++)
	 if(!matrix[i][0]){
		 rowHas0=true;
		 break;
	 }
 for(int j=0;j<n;j++)
	 if(!matrix[0][j]){
		 colHas0=true;
		 break;
	 }
  for(int i=1;i<m;i++)
	 for(int j=1;j<n;j++){
		 if(!matrix[i][j]){
			 matrix[i][0]=0;
			 matrix[0][j]=0;
		 }
   }
//   for(int i=1;i<m;i++){
//	  if(!matrix[i][0]){
//		 for(int j=1;j<n;j++)
//			matrix[i][j]=0;
//
//	       }
//    }
//	for(int j=1;j<n;j++){
//		if(!matrix[0][j]){
//			for(int i=1;i<m;i++)
//				matrix[i][j]=0;
//
//	         }
//     }


  for(int i = 1 ; i < m ; ++i)
	  for(int j = 1 ; j < n ; ++j)
		  if(matrix[i][0] || matrix[0][j])
			  matrix[i][j] = 0 ;
	if(rowHas0){
		for(int i=0;i<m;i++)
			matrix[i][0]=0;
	}
	if(colHas0){
		for(int j=0;j<n;j++)
			matrix[0][j]=0;
	}
}




 int main(){
	 return 0;
 }



