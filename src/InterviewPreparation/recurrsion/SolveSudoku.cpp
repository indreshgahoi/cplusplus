/*
 * SolveSudoku.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/recurrsion/SolveSudoku.cpp -o /usr/build/Main.o
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
	vector<vector<bool> > rows ;
	vector<vector<bool> > cols ;
	vector<vector<bool> > block ;


	bool solve(vector<vector<char> > &board,int index)
	{
		while( index<81 && board[index/9][index%9]!='.') index++;

		if(index==81) return true ;

		int row = index/9;
		int col = index%9 ;
		for(int i = 0;i<9;++i)
		{
			if(rows[row][i]||cols[col][i]||block[3*(row/3)+col/3][i]) continue ;

			rows[row][i]=cols[col][i]=block[3*(row/3)+col/3][i] = true ;
			board[row][col]='1'+i;
			if(solve(board,index+1))
				return true ;
			board[row][col]='.';
			rows[row][i]=cols[col][i]=block[3*(row/3)+col/3][i] = false ;

		}
		return false ;
	}


	void solveSudoku(vector<vector<char> > &board)
	{
		rows.clear();
		cols.clear();
		block.clear();
		rows.resize(9,vector<bool>(9,false));
		cols.resize(9,vector<bool>(9,false)) ;
		block.resize(9,vector<bool>(9,false)) ;

		for(int i=0;i<9;++i)
		{
			for(int j=0;j<9;++j)
			{
				char c = board[i][j];
				if(c !='.')
					rows[i][c-'1']=cols[j][c-'1']=block[3*(i/3)+j/3][c-'1']=true;
			}
		}

		solve(board,0);
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
