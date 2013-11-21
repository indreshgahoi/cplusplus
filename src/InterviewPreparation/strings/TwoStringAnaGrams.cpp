/*
 * TwoStringAnaGrams.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/strings/TwoStringAnaGrams.cpp -o /usr/build/Main.o
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
Link :-  http://www.geeksforgeeks.org/check-whether-two-strings-are-anagram-of-each-other/
Question :-

Check whether two strings are anagram of each other

Write a function to check whether two given strings are anagram of each other or
not. An anagram of a string is another string that contains same characters,
 only the order of characters can be different.
  For example, “abcd” and “dabc” are anagram of each other
  
  
*/

bool aneGrams(string &s1 , string &s2)
{
	int size1 = s1.size();
	int size2 = s2.size();

	if(size1!=size2) return false ;

	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());

	for(int i = 0 ; i < size1 ; ++i)
	{
		if(s1[i]!=s2[i])
			return false ;
	}
	return true ;
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
