/*
 * PalinDromicPartition.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/DP/PalinDromicPartition.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 24, 2013
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
#define trv(it,C)    for(__typeof__ ((C).begin()) it = (C).begin() ;(C).end()!= it ;++it)
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
Link :-  http://discuss.leetcode.com/questions/1266/palindrome-partitioning-ii
Question :-
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
  
  
*/

/*
 *  To attack this problem
 *   define DP state
 *   S[0 ..i..S.length]
 *  DP[0...i..S.length]
 *
 *  if we traverse from right to left
 *  worst case for palindromic cut is that when each string is split into 1 lenght
 *
 *  what DP[i] means minimum palindromic cut for string S[i.....S.length]
 *
 *  P[i][j] = true if string S[i.....j] is Palindromic other wise false
 *  So DP[i] ={ 0 , S[i]==S[S.length] && P[i+1][S.length-1]
 *				Min(DP[k]+S[i...k])  if(P[i][k]==true)
 *				                         DP[i] = D[k] + 0
 *				                     else
 *				                         DP[i] = D[k] + i-k
 *				i<=k<=S.length
 *  		  }
 *
 */


class Solution
{
#define trv(it,C)    for(__typeof__ ((C).begin()) it = (C).begin() ;(C).end()!= it ;++it)

	public :

	void InitializeDpState(const string& str ,vector<int> &DP)
	{
		int size = str.size();

		trv(it,DP)
		{
	        *it = DP.end()-it-1 ;
		}
		cout<<DP ;
	}
	void InitializePalindromeDp(const string &str,vector<vector<int> > &isPalindrome)
	{
		trv(it,isPalindrome)
		{
			isPalindrome[it-isPalindrome.begin()][it-isPalindrome.begin()] = 1 ;
		}
       cout<<isPalindrome ;
	}
	int minCut(string &str)
	{
		int size = str.size();
		vector<int> DP(size);
		vector<vector<int> > isPalindrome(size,vector<int>(size,false)) ;
		InitializeDpState(str,DP);
		InitializePalindromeDp(str,isPalindrome);
		int i ,j;
		for(i= size-2 ; i >=0 ; --i)
		{
			for(j=1 ; j< size ;++j)
			{

				if(str[i]==str[j] && ((i+1)==j || isPalindrome[i+1][j-1]))
				{
						isPalindrome[i][j] = true ;

				}
				if(isPalindrome[i][size-1])
				{
					DP[i]=0;
					break ;
				}
				else if(isPalindrome[i][j])
				{
					DP[i] = min(DP[i],1+DP[j+1]);

				}

               cout<<DP ;
			}
		}

		return DP[0];
	}

   
};
void driver()
{
  fstream fin("input.txt");	
  Solution solver ;
  string str;
  while(fin>>str)
  {
	  cout<<"Input==> "<<str; nl
	  int len = solver.minCut(str);
	  cout<<" ans = "<<len<<"\n";
  }
}
/*
 input.txt 
 aab
 cdd
 b
 bb

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
