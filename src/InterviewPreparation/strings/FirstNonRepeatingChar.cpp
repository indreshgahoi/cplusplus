/*
 * FirstNonRepeatingChar.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/strings/FirstNonRepeatingChar.cpp -o /usr/build/Main.o
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
Link :-  http://www.geeksforgeeks.org/given-a-string-find-its-first-non-repeating-character/
Question :-
	Given a string, find the first non-repeating character in it. For example,
	 if the input string is “GeeksforGeeks”, then output should be ‘f’ and if input
	 string is “GeeksQuiz”, then output should be ‘G’.
  
  
*/

#define NO_OF_CHAR 256
struct info
{
	int frequency;
	int firstIdx ;
};

int NonRepeatingCharacter(char *str)
{
	char *start = str ;
	info count[NO_OF_CHAR] ;
	for(int i = 0 ; i < NO_OF_CHAR ; ++i){
		count[i].frequency = 0;
		count[i].firstIdx = INT_MAX ;
	}
	while(*s)
	{
		count[*s].frequency++;
		if(count[*s].frequency==1)
			count[*s].firstIdx = s-start;
		s++ ;
	}
	int resultIdx = INT_MAX ;
	for(int i = 0 ; i < NO_OF_CHAR ; ++i)
	{
		if(count[i].frequency==1 && resultIdx > count[i].firstIdx)
		{
			resultIdx = count[i].firstIdx ;
		}
	}
 return resultIdx ;
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
