
#include<iostream>
#include<cstdio>
#include<vector>
#include<ostream>
#include<fstream>
#include<map>
using namespace std ;


/*
 *  Link :- http://www.geeksforgeeks.org/amazon-interview-set-54-off-campus-for-sde-1/
 *  Question :-
 *   You are given an array of integers(positive and negative). You have to find if there exists any sequence
 *   of numbers in it which has the sum zero. If there is any print the start index else print -1
 *
 *  Answer :-
 *   A[1 2 ..........n-1 n]
 *
 * let us prefix sum  array of length n is P
 *  such that  P[i] = A[1] + A[2] +......A[i]
 *
 *  if i < j  P[i]==P[j]
 *   that means adding elements A[i+1] A[i+2]......A[j] give 0
 * return start index and length
 */

struct info
{
	int start ;
	int length ;
};

info getPosition(const vector<int> &V)
{   // having Information sum -> index
	map<int,vector<int>::const_iterator > preSumHash;
	info res ;
	res.start = -1 ;
	res.length = 0 ;
	vector<int>::const_iterator it ;
	int current_sum = 0 ;
	for(it = V.begin() ; it != V.end() ; ++it)
	{
		current_sum += *it ;
		if(preSumHash.find(current_sum)!=preSumHash.end())
		{
			preSumHash[current_sum] = it ;
		}
		else
		{
			res.start = (preSumHash[current_sum]+1)-V.begin() ;
			res.length = it - preSumHash[current_sum] ;
			break ;
		}
	}
	return res ;
}


void test()
{

}

int main()
{
	return 0 ;
}
