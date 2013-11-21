/*
 * MiniMumDistanceBetWeenTwoWordsInLargestWords.cpp
 * run command
 * g++ /Algorithm/src/CrackingCode/Hard/MiniMumDistanceBetWeenTwoWordsInLargestWords.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 17, 2013
 *      Author: Indresh Gahoi
 */


#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<climits>
#include<string>
#include <cstring>
#include <fstream>
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

class Timer
{
public:
	Timer()
	{
		start = clock();
	}

	long long int elapsed()
	{
		long long int ela = clock() -start ;
		start = clock();
		cout<<"elapsed time = "<<  ela/CLOCKS_PER_SEC;
		return ela/CLOCKS_PER_SEC;
	}
	void reset()
	{
		start = clock();
	}

private :
	clock_t start ;
};

/*
 * You have a large text file containing words. Given any two words,
 * find the shortest distance (in terms of number of words) between them in the file.
 *  Can you make the searching operation in O(1) time? What about the space
 *  complexity for your solution?
 *
 *
 */


int minimumDistance(ifstream &fin ,string &word1 , string &word2)
{
	int distance = INT_MAX/2 , local_distance ;
	int last_word1_position , last_word2_position ;
	last_word1_position = -INT_MAX/2 ;
	last_word2_position = -INT_MAX/2 ;  // To prevent the Over Flow take  MAX= INT_MAX/2
	string current_word ;

	int i = 0 ;
	while(fin >> current_word)
	{

		if(current_word==word1)
		{
			last_word1_position = i ;

			distance = min(distance,i-last_word2_position+1);
			// i-last_word2_position+1 overflow can occur if MAX = INT_MAX
		}
		else if(current_word==word2)
		{
			last_word2_position = i ;

			distance = min(distance,i-last_word1_position+1);
		}
		i++;
	}

 return distance ;
}

/*
 *  input.txt
 *  as was is the as the yahoo you me was the and
 *
 *
 *
 */


void driver()
{
	ifstream fin("input.txt");
	string word1("was");
	string word2("as");
	cout<<"ans= "<<minimumDistance(fin,word1,word2);
}

int main(){
	driver();
	cout<<"\n";
	return 0;
}
