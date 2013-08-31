/*
 * matrixSpiralOrder.cpp
 *
 *  Created on: Feb 9, 2013
 *      Author: indresh
 */

#include<iostream>
#include<cstdio>
using namespace std;
int N,val;
int mat[16][16];

void print_spiral(int mat[ ][16], int m, int n, int k) {

	if (m <= 0 || n <= 0)
    return;
  if (m == 1) {
    for (int j = 0; j < n; j++)
    	mat[k+j][k]=val--;
      //cout << mat[k][k+j] << " ";
    return;
  }
  if (n == 1) {
    for (int i = 0; i < m; i++)
     // cout << mat[k+i][k] << " ";
    	mat[k][k+i] =val--;
    return;
  }
  // print from top left
  for (int j = 0; j < n - 1; j++){
   // cout << mat[k][k+j] << " ";
	  mat[k+j][k]=val--;
  }// print from top right
  for (int i = 0; i < m - 1; i++){
    //cout << mat[k+i][k+n-1] << " ";
    mat[k+n-1][k+i] =val--;
  }
  // print from bottom right
  for (int j = 0; j < n - 1; j++){
    //cout << mat[k+m-1][k+n-1-j] << " ";
	  mat[k+n-1-j][k+m-1]=val--;
  // print from bottom left
    }
  for (int i = 0; i < m - 1; i++){
   // cout << mat[k+m-1-i][k] << " ";
	  mat[k][k+m-1-i]=val--;
  }

  print_spiral(mat, m-2, n-2, k+1);
}

int main(){
	cin>>N;
	val=N*N;
	print_spiral(mat, N, N, 0);
 for(int i=0;i<N;i++){
	 for(int j=0;j<N;j++)
		  printf("%-3d ",mat[i][j]);
	 cout<<endl;
 }
   return 0;
}
