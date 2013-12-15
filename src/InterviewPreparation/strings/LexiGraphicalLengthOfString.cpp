/*
 * LexiGraphicalLengthOfString.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/strings/LexiGraphicalLengthOfString.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 24, 2013
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
Link :-  http://www.geeksforgeeks.org/lexicographic-rank-of-a-string/
Question :-
  Given a string, find its rank among all its permutations sorted lexicographically. For example,
  rank of “abc” is 1, rank of “acb” is 2, and rank of “cba” is 6.

For simplicity, let us assume that the string does not contain any duplicated characters.

One simple solution is to initialize rank as 1, generate all permutations in lexicographic order.
After generating a permutation, check if the generated permutation is same as given string, if same,
 then return rank, if not, then increment the rank by 1. The time complexity of this solution will be
  exponential in worst case. Following is an efficient solution.

Let the given string be “STRING”. In the input string, ‘S’ is the first character.
There are total 6 characters and 4 of them are smaller than ‘S’. So there can be 4 * 5!
smaller strings where first character is smaller than ‘S’, like following

R X X X X X
I X X X X X
N X X X X X
G X X X X X

Now let us Fix S’ and find the smaller strings staring with ‘S’.

Repeat the same process for T, rank is 4*5! + 4*4! +…

Now fix T and repeat the same process for R, rank is 4*5! + 4*4! + 3*3! +…

Now fix R and repeat the same process for I, rank is 4*5! + 4*4! + 3*3! + 1*2! +…

Now fix I and repeat the same process for N, rank is 4*5! + 4*4! + 3*3! + 1*2! + 1*1! +…

Now fix N and repeat the same process for G, rank is 4*5! + 4*4 + 3*3! + 1*2! + 1*1! + 0*0!

Rank = 4*5! + 4*4! + 3*3! + 1*2! + 1*1! + 0*0! = 597

Since the value of rank starts from 1, the final rank = 1 + 597 = 598
  
*/

#define NO_OF_CHAR 256
class Solution
{
    private :

	public :
	vector<int > fact;
	Solution()
	{
		fact.resize(10);
		fact[0]=fact[1] = 1 ;
		for(int i = 2 ;i<fact.size();++i)
			fact[i]=i*fact[i-1];
	}

	void CreateCount(string &str ,vector<int> &count)
	{
		int size = str.size() ;
	    string::iterator ch = str.begin();
	    for(;ch != str.end() ;++ch)
	    {
	    	count[*ch]++;
	    }
	  for(int i = 1 ; i < count.size();++i)
	  {
		  count[i]+=count[i-1];
	  }
	}
	void UpdateCount(char ch ,vector<int> &count)
	{
		for(int i = ch ; i < count.size();++i)
		{
			count[i]--;
		}
	}
#define debug(x) cout<<#x" "<<x;
#define nl cout<<"\n";
#define tab cout<<"		";
	int RankOfString(string &str)
	{
		int size = str.size();
		vector<int> count(NO_OF_CHAR,0);
		int iter = 0 ,rank = 1 ;
		CreateCount(str,count);
		while(iter < size)
		{
			int smaller = count[str[iter]-1];
		    rank+= smaller * fact[size-iter-1];
		    UpdateCount(str[iter],count);
		    iter++;
		}
      return rank ;
	}
};




void driver()
{
    fstream fin("input.txt");
	Solution solver ;
	string str ;
	while(fin>>str)
	{
		cout<<"input==> "<<str;
		cout<<" Rank = "<<solver.RankOfString(str)<<"\n";
	}
}
/*
 input.txt 
STRING
*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
