/*
 * wordSearch.cpp
 *
 *  Created on: Mar 24, 2013
 *      Author: indresh
 */
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int row,col,len;
string *s;
vector<vector<bool> > visit;
vector<vector<char> > *br;
bool solve(int i,int j,int idx)
{
	vector<vector<char> > &b=*(br);
	if(i<0 || j<0 || i>=row || j>=col || idx>=len) return false;
	if(visit[i][j]) return false;
	if(b[i][j]!=(*s)[idx])return false;
	if((idx+1)==len) return true;
	visit[i][j]=true;
	bool flag=solve(i+1,j,idx+1)||solve(i-1,j,idx+1)||solve(i,j+1,idx+1)||solve(i,j-1,idx+1);
	visit[i][j]=false;
	return flag;
}
bool exist(vector<vector<char> > &board, string word)
{
    s=&word;
    len=s->size();
	row=board.size();
	br=&board;
	col=(row!=0)?board[0].size():0;
     visit=*new vector<vector<bool> >(row,vector<bool>(col,false));
	for(int i=0;i<row;i++){
	   for(int j=0;j<col;j++){
		   if(solve(i,j,0))return true;

	   }
   }
	return false;
}
int main(){
	return 0;
}
