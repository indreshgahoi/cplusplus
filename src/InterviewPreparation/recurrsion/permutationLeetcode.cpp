/*
 * permutationLeetcode.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/recurrsion/permutationLeetcode.cpp -o /usr/build/Main.o
 *
 *  Created on: Dec 29, 2013
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
#include<unordered_map>
#include<unordered_set>

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
Link :-  http://oj.leetcode.com/problems/permutations-ii/
Question :-
   Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
  
*/
class Solution {
public:
	void permuteUniqueHelper(vector<int> &num ,int start,vector<vector<int> > &ret)
	{
		if(start==num.size())
		{
			ret.push_back(num) ;
			return ;
		}
		unordered_set<int> used ;

		for(int i = start+1 ; start < num.size() ; ++i)
		{
			if(used.find(num[i]) == used.end())
			{
				swap(num[start],num[i]) ;
				permuteUniqueHelper(num,start+1);
				swap(num[start],num[i]) ;
				used.insert(num[i]);
			}
		}
	}

    vector<vector<int> > permuteUnique(vector<int> &num) {

    	vector<vector<int> > result ;
    	permuteUniqueHelper(num,0,result) ;
    	return result ;
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
