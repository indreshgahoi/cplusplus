/*
 * EditDistance.cpp
 *
 *  Created on: Mar 28, 2013
 *      Author: indresh
 */
#include<iostream>
#include<cstdio>
#include <sstream>
#include<vector>

using namespace std;
int minDistance(string word1, string word2) {
	vector<vector<int> > mem(2,vector<int>(word2.size()+1,0));
	int n=word2.size()+1,m=word1.size()+1;

	for(int j=0;j<n;j++){
		mem[0][j]=j;
	}

	for(int i=1;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j==0)
			{
				mem[0][i]=i;
				continue;
			}
			if(word1[i]!=word2[j])
			{
				mem[i%2][j]=(min(mem[(i-1)%2][j],mem[i%2][j-1])+1);
			}
			else
			{
				mem[i%2][j]=mem[i-1][j-1];
			}
		}
	}
	return mem[(m-1)%2][n-1];
}


