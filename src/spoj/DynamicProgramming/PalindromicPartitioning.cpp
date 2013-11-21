/*
 * PalindromicPartitioning.cpp
 * run command
 * g++ /Algorithm/src/spoj/DynamicProgramming/PalindromicPartitioning.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 18, 2013
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
Link :-  http://www.geeksforgeeks.org/dynamic-programming-set-17-palindrome-partitioning/
Question :-
	Given a string, a partitioning of the string is a palindrome partitioning if
	every substring of the partition is a palindrome.
	 For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of
	 “ababbbabbababa”. Determine the fewest cuts needed for palindrome
	 partitioning of a given string. For example, minimum 3 cuts are needed
	 for “ababbbabbababa”. The three cuts are “a|babbbab|b|ababa”.
	 If a string is palindrome, then minimum 0 cuts are needed.
	 If a string of length n containing all different characters,
	  then minimum n-1 cuts are needed
  
  


*/

/*
 *  S1..Si...Sj...Sn
 *  State C[i][j] = minimum Partition to make Si...Sj palindrome  partition
 *
 *  C[i][j] = 0   i==j    don't need to partitioned
 *  C[i][i] = 0   Si....Sj  is palindrome
 *
 *  otherwise
 *  C[i][j] = Min(C[i][k] + 1 +C[k+1][j]) k=i....j-1
 *
 *   P[i][j] = true if Si...Sj is palindrone
 *
 */
// Now Do The Code Fill Table Bottom Up Manner

/*
 *  O(n^3) Solution
 *
 *
 */
int minCuts(string &str)
{
	int size = str.size();
 vector<vector<int> > C(size,vector<int>(size,0));
 vector<vector<bool> > P(size,vector<bool>(size,false));

 	 for(int i=0 ; i < size ; ++i)
 	 {
 		 C[i][i]=0;
 		 P[i][i]=true;
 	 }

 	 for(int L=2 ; L<=size ; ++L)
 	 {   // For substring of length L, set different possible starting indexes
         for(int i = 0 ; i < size-L+1 ; ++i)
         {
        	 int j = i+l-1 ; //set end index of substring
        	 // solve probLen for L 2

        	 if(L==2) P[i][j] = str[i]==str[i] ;
        	 else
        		 P[i][j] = str[i]==str[j] && P[i+1][j-1] ;

        	 if(P[i][j])
        	 {
        		 C[i][j]=0;
        	 }
        	 else
        	 {
        		 C[i][j]=INT_MAX ;
        		 for(int i = k ; i <=j-1 ; i++)
        		 {
        			 C[i][j] = min(C[i][j],C[i][k]+1+C[k+1][j]);
        		 }
        	 }

         }
 	 }
 	 return C[0][n-1];
}

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
