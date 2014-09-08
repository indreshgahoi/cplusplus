/*
 * isValidSudoku.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/DP/isValidSudoku.cpp -o /usr/build/Main.o
 *
 *  Created on: Feb 11, 2014
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
class Solution {
public:
	 bool isValidSudoku(vector<vector<char> > &board) {

	    	vector<vector<bool> > row(9,vector<bool>(9,false)) ;
	    	vector<vector<bool> > col(9,vector<bool>(9,false)) ;
	    	vector<vector<bool>> block(9,vector<bool>(9,false));

	    	for(int i = 0;i<board.size();++i)
	    	{
	    		for(int j =0;j<board.size();++j)
	    		{
	    			if(board[i][j]=='.') continue ;
	    			char c = board[i][j]-'1' ;
	    			if(row[i][c]||col[j][c]||block[i-i%3+j/3][c]) return false;
	    			row[i][c]=col[j][c]=block[i-i%3+j/3][c]=true ;
	    		}
	    	}
	    	return true ;
	    }
};
void driver()
{
  fstream fin("input.txt");	
  Solution solver ;
}
/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
