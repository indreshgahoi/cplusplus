/*
 * isAnaGram.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/strings/isAnaGram.cpp -o /usr/build/Main.o
 *
 *  Created on: Jan 18, 2014
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
#define NO_OF_CHAR 256

class Solution
{
	public :

	bool isAnaGram(string &str1 , string &str2)
	{
		size_t size1 = str1.size() ;
		size_t size2 = str2.size() ;
		if(size1!=size2)
			return false ;
		std::sort(str1.begin(),str1.end()) ;
		std::sort(str2.begin(),str2.end()) ;
       for(int iter = 0 ; iter<size1 ;++iter)
       {
    	   if(str[iter]!=str2[iter]) return false ;
       }
       return true ;
	}

   
};
class Solution1
{
	public :

	bool isAnaGram(string &str1 , string &str2)
	{
		vector<int> charMap1(NO_OF_CHAR,0) ;
		vector<int> charMap2(NO_OF_CHAR,0) ;
		for(int iter = 0 ; iter < str1.size() ; ++iter)
			charMap1[str1[iter]]++ ;
		for(int iter = 0 ; iter < str2.size() ; ++iter)
					charMap2[str2[iter]]++ ;

		for(int iter = 0 ; iter < NO_OF_CHAR ; ++iter)
			if(charMap1[iter]!= charMap2[iter]) return false ;
		return true ;
	}


};

class Solution2
{
	public :

	bool isAnaGram(string &str1 , string &str2)
	{
		vector<int> charMap(NO_OF_CHAR,0) ;
		size_t size1 = str1.size() ,size2 = str2.size();

		if(size1!=size2) return false ;
		for(int iter = 0 ; iter < str1.size() ; ++iter)
		{
			charMap[str1[iter]]++ ;
			charMap[str2[iter]]-- ;
		}

		for(int iter = 0 ; iter < NO_OF_CHAR ; ++iter)
			if(charMap[iter]) return false ;
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
