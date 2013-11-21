/*
 * LongestWordsMadeOfOtherWords.cpp
 * run command
 * g++ /Algorithm/src/CrackingCode/Hard/LongestWordsMadeOfOtherWords.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 17, 2013
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
#include<set>
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
Link :-  http://mattcb.blogspot.in/2012/12/find-longest-word-made-of-others.html
Question :- Write a program to find the longest word made of other words
  
  
*/


class Solution{

public :



 struct StringLengthCompare
 {
	 int operator()(const string &s1 , const string &s2)
	 {
		 if(s1.size()<s2.size()) return 1;
		 if(s1.size()>s2.size()) return -1 ;
		 return 0 ;
	 }
 };

 void findLongestWord(vector<string> &strings)
 {
	 set<string> dict ;
	 for(int i = 0 ; i <strings.size();++i)
	 {
		 dict.insert(strings[i]);
	 }
     cout<<strings<<"\n";
	 sort(strings.begin(),strings.end(),StringLengthCompare());
	 for(int i = 0 ; i <strings.size();++i)
	 {
		 dict.erase(strings[i]);
		 if(dfs(dict,strings[i]))
			 cout<<"can combine " << strings[i] <<"\n";
		 dict.insert(strings[i]);
	 }

 }

 bool dfs(set<string> &dict ,string target)
 {
	 if(dict.find(target)!=dict.end() ) return true;

	 for(int i = 0 ; i < target.size() ; ++i)
	 {
		 if(dict.find(target.substr(0,i))!=dict.end() && dfs(dict,target.substr(i)))
			 return true ;
	 }
	 return false ;
 }


};




void driver()
{
 fstream fin("input.txt");
 string t ;
 vector<string> strings ;
 while(fin>>t)
 {
	 strings.push_back(t);
 }
 Solution sl ;
 sl.findLongestWord(strings);
}
/*
 input.txt 
cat
banana
dog
nana
walk
walker
dogwalker
s
catswalker
bigdogwalker
big
catanddog
and
bigcatbananadog


*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
