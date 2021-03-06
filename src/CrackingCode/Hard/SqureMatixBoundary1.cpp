/*
 * SqureMatixBoundary1.cpp
 * run command
 * g++ /Algorithm/src/CrackingCode/Hard/SqureMatixBoundary1.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 17, 2013
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<climits>
#include<string>
#include <cstring>
#include<pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include<time.h>

using namespace std;

#define FOR(_i,a,b) for(int _i=a;_i<b;_i++)
#define REP(_i,n)    for(int _i=0;_i<n;_i++)

typedef int Integer ;

void driver();

void printArray(int A[],size_t size){
	printf("values= [");
   for(int i=0;i<size-1;i++)
	   printf("%d ,",A[i]);
   printf("%d]\n",A[size-1]);
}
template<class T>
ostream& operator<<(ostream &out,const vector<T>& V){
	out<<"[";
	for(typename vector<T>::const_iterator it=V.begin();it!=V.end();it++){
	 out<<" "<<*it;
	}
	out<<"]"<<endl;
	return out;
}
void getInput(vector<int> &v)
{
#define ARRAYSIZE(A) sizeof(A)/sizeof(A[0])
	int arr[] = {-1,-1,-1,1,1};
	int size = ARRAYSIZE(arr) ;
	for(int iter = 0 ; iter < size ; ++iter)
	{
		v.push_back(arr[iter]);
	}
}
/*
Link :-  
Question :-
  
  
*/

class Solution
{

   bool isValidSubSqure(vector<vector<int> > &mat ,int x , int y , int size)
   {

    for(int j = y ; j < y+size;++j)
    {
    	if(mat[x][j]==0) return false ;
    	if(mat[x+size-1][j]==0) return false ;
    }
    for(int j = x ; j<x+size;++j)
    {
    	if(mat[j][y]==0) return false ;
    	if(mat[j][y+size-1]==0) return false ;
    }

    return true ;
   }


   int maxSizeSubSqure(vector<vector<int> > &mat,int &x,int &y)
   {
	   int maxSize = 0;
	   int len = mat.size();
	   for(int col = 0 ; len-col>maxSize;++col)
	   {
		   for(int row=0;len-row>maxSize;++row)
		   {
                for(int size =len-max(row,col);size>maxSize;size--)
                {
                	if(isValidSubSqure(mat,row,col,size))
                	{
                		x= row ;
                		y = col ;
                		maxSize = size ;
                	}
                }
		   }
	   }
	   return maxSize;
   }
};




void driver()
{

}
/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
