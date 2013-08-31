/*
 * MaximumRectangle.cpp
 *
 *  Created on: Mar 23, 2013
 *      Author: indresh
 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<sstream>
using namespace std;
template < class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
    os << "[";
    for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}


int maximalRectangle(vector<vector<char> > &matrix) {
	if(matrix.size()==0) return 0;
   int row=matrix.size(),col=matrix[0].size();
   vector<int> H(col,0);
   vector<int> L(col,0);
   vector<int> R(col,col);
   int maxArea=0;

   for(int i=0;i<row;i++){
	   int left=0,right=col-1;
	   for(int j=0;j<col;j++){
		   if(matrix[i][j]=='1'){
			   H[j]=H[j]+1;
			   L[j]=max(L[j],left);
		   }
		   else{
			   left=j+1;
			   L[j]=0;H[j]=0;
		   }

	   }
	   for(int j=col-1;j>=0;j--){
		   if(matrix[i][j]=='1'){
			   R[j]=min(R[j],right);
			   maxArea=max(maxArea,(R[j]-L[j]+1)*H[j]);
		   }
		   else{

			   right=j-1;
			   R[j]=col-1;
		   }

	   }
       cout<<"H="<<H<<endl;
       cout<<"L="<<L<<endl;
       cout<<"R="<<R<<endl;
       cout<<"maxArea="<<maxArea<<endl;

   }

 return maxArea;
}

int main(){
	vector<vector<char> > matrix;
	vector<char> row;
	row.push_back('0');
	row.push_back('0');
	row.push_back('0');
	//row.push_back('0');
	matrix.push_back(row);
    row.clear();
        row.push_back('0');
    	row.push_back('0');
    	row.push_back('0');
    	//row.push_back('0');
    	matrix.push_back(row);
        row.clear();
	row.push_back('1');
	row.push_back('1');
	row.push_back('1');
	//row.push_back('0');
	matrix.push_back(row);

	 cout<<maximalRectangle(matrix);

	return 0;
}
