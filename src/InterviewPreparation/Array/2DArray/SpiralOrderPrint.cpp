/*
 * SpiralOrderPrint.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/Array/SpiralOrderPrint.cpp -o /usr/build/Main.o
 *
 *  Created on: Dec 28, 2013
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<climits>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>

using namespace std;

#define FOR(_i,a,b) for(int _i=a;_i<b;_i++)
#define REP(_i,n)    for(int _i=0;_i<n;_i++)
#define debug(x) cout<<#x" "<<x;
#define nl cout<<"\n";
#define tab cout<<"		";
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


	void print_matrix_in_spiral(int mat[][6],int m , int n)
	{
        int sr , er , sc, ec ;
        sr = 0 ; er = m ;
        sc = 0 ; ec = n ;

        while(sr < er && sc < ec)
        {
        	// print first row
            for(int i = sc ; i < ec ; ++i)
            {
            	printf("%d ",mat[sr][i]) ;
            }
            sr++ ;
            // print the last column
            for(int i = sr ; i < er ; ++i)
            {
            	printf("%d ",mat[i][ec-1]) ;
            }
            ec-- ;
            // print the last row right to left
            if(sr < er)
            {
            	for(int i = ec-1 ; i >= sc ; --i)
            		printf("%d ",mat[er-1][i]) ;
            	er-- ;
            }
            if(sc < ec)
            {
            	for(int i = er-1 ; i >=sr ; --i)
            		printf("%d ",mat[i][sc]) ;
            	sc++ ;
            }

            // print the first column bottom to top
        }
	}
   

void driver()
{
  //fstream fin("input.txt");
  int a[4][6] = { {1,  2,  3,  4,  5,  6},
                  {7,  8,  9,  10, 11, 12},
                  {13, 14, 15, 16, 17, 18},
                  {19, 20, 21, 22, 23, 24}};
  print_matrix_in_spiral(a,4,6) ;
}
/*
 input.txt 

*/
int main(){
	driver();

	return 0;
}
