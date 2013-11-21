/*
 * DivideStringNEqualParts.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/strings/DivideStringNEqualParts.cpp -o /usr/build/Main.o
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
Link :-  http://www.geeksforgeeks.org/divide-a-string-in-n-equal-parts/
Question :-

Divide a string in N equal parts

Question:
Write a program to print N equal parts of a given string.

Solution:
1) Get the size of the string using string function strlen() (present in string.h)
2) Get size of a part.

  
     part_size = string_length/n

3) Loop through the input string. In loop, if index becomes multiple of part_size then put a part separator(“\n”)

  
*/

void printStringNEqualParts(char *str ,int n)
{
	int len = strlen(str);

	if(!(len % n)==0)
	{
		cout<<"can't be partioned\n";
	}
	int i = 0 ;
    int partSize = len / n ;
	while(*str)
	{
		if((i%partSize)==0)
			cout<<"\n";
		cout<<*str;
		str++;
		i++;
	}


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
