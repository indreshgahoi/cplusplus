/*
 * RandomShuffle.cpp
 * run command
 * g++ /Algorithm/src/CrackingCode/Hard/RandomShuffle.cpp -o /usr/build/Main.o
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
 *  Write a method to shuffle a deck of cards. It must be a perfect shuffle - in
 *  other words, each 52! permutations of the deck has to be equally likely.
 *  Assume that you are given a random number generator which is perfect.
 *
 * Link :- http://www.geeksforgeeks.org/shuffle-a-given-array/
 *
 *
 */

void ShuffleArray(vector<int> V)
{



	for(int i = 0 ; i < V.size() ; ++i)
	{
		// select randoom position int(i....V.size()-1)
		// we are on i then we already processed i element an remaining size is
		//  V.size() - i
		int selectedIndex = (rand() % (V.size()-i)) + i;
		printf("selected= %d ",selectedIndex);
		swap(V[i],V[selectedIndex]);
		srand(time(NULL));
		sleep(1);
	}

	cout<<"Randon Shuffle :"<<V<<"\n";
}


/*
 *  Generate Random SubSet
 *
 *
 */

int random(int l ,int r)
{
	return l+ (rand()%(r-l+1));
}


vector<int> RandonSubset(vector<int> V,int m) // subset size is m
{

    vector<int> subset(m);

	for(int i = 0 ; i < m ; ++i)
	{
		// select randoom position int(i....V.size()-1)
		// we are on i then we already processed i element an remaining size is
		//  V.size() - i
		int selectedIndex = random(i,V.size()-1);
		printf("selected= %d ",selectedIndex);
		swap(V[i],V[selectedIndex]);
		subset[i] = V[i] ;
		srand(time(NULL));
		sleep(1);
	}

	cout<<"Randon subset :"<<subset<<"\n";
	return subset ;
}

void driver()
{
	vector<int>  input ;
	input.push_back(2);
	input.push_back(3);
	input.push_back(5);
	input.push_back(7);
	input.push_back(8);
	input.push_back(9);
	cout<<input<<"\n";
	int i = 0 ;
	while(i < 5)
	{

		//ShuffleArray(input);
		RandonSubset(input,4);

		i++;
	}
}

int main(){
	driver();
	cout<<"\n";
	return 0;
}
