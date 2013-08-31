/*
 * PascalTriangle.cpp
 *
 *  Created on: Jan 20, 2013
 *      Author: indresh
 */

// Kth row of the Pascal Triangle
// Only O(k extara) space
#include<iostream>
using namespace std;
 void nCr(int r){
	 int C[2][r+1];
	 for(int i=0;i<=r;i++){
		 for(int j=0;j<=i;j++)
		 { if(i==j || j==0)
			 C[(i&1)?1:0][j]=1;
		  else
			  C[(i&1)?1:0][j]=C[((i-1)&1)?1:0][j]+C[((i-1)&1)?1:0][j-1];

		 }
	 }
	for(int j=0;j<r+1;j++)
		cout<<" "<<C[(r&1)?1:0][j];
 }
 //n rows of the Pascal Triangle
 vector<vector<int> > generate(int r) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > C(r,vector<int>(1,1));


     for(int i=1;i<r;i++){
         for(int j=1;j<i;j++)
		   C[i].push_back(C[i-1][j-1]+C[i-1][j]);
    	C[i].push_back(1);
     }
	return C;
    }
int main(){
	int n;
	cin>>n;
	nCr(n);
	return 0;
}
