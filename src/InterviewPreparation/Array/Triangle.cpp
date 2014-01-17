/*
 * Triangle.cpp
 *
 *  Created on: Jan 20, 2013
 *      Author: indresh
 */
/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int row;

 int getMinimumTotal(int i,int j,vector<vector<int> > &triangle){
     if(i>=row || j>=i)
      return 0;
     cout<<"i="<<i<<" j="<<j<<endl;
      return min(triangle[i][j]+getMinimumTotal(i+1,j,triangle),triangle[i][j]+getMinimumTotal(i+1,j+1,triangle));
 }
 int minimumTotal(vector<vector<int> > &triangle) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
      row=triangle.size();
      cout<<"row="<<row;
      return getMinimumTotal(0,0,triangle);
  }

 // it takes only O(n) extar space
 //
 int minimumTotalByDp(vector<vector<int> > &triangle) {

       vector<vector<int> > mem(2,vector<int>(triangle.size(),0));
       int m=999;
       for(int i=0;i<triangle.size();i++){
           for(int j=0;j<=i;j++)
           {
               if(j==0)
                if(i==0)
                 mem[0][0]=triangle[0][0];
                else
                  mem[(i&1)?1:0][0]=triangle[i][0]+mem[((i-1)&1)?1:0][0];
              if(j!=0&&j==i)
               mem[(i&1)?1:0][j]=triangle[i][j]+mem[((i-1)&1)?1:0][j-1];
              else
               mem[(i&1)?1:0][j]=min(triangle[i][j]+mem[((i-1)&1)?1:0][j-1],triangle[i][j]+mem[((i-1)&1)?1:0][j]);




           }


       }
         for(int j=0;j<triangle.size();j++)
           {
            cout<<" "<<mem[((triangle.size()-1)&1)?1:0][j];
            m=min(m,mem[((triangle.size()-1)&1)?1:0][j]);
           }
        return m;
    }
int main(){
	vector<vector<int> > triangle;
	int row;
	cin>>row;

	for(int i=0;i<row;i++){
		vector<int> r;
		for(int j=0;j<i+1;j++){
			int t;
			cin>>t;
			r.push_back(t);
		}
		triangle.push_back(r);
	}
	cout<<" minimum="<<minimumTotalByDp(triangle)<<endl;
	return 0;
}
