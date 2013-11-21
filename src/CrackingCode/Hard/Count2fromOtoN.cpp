/*
 * Count2fromOtoN.cpp
 * run command
 * g++ /Algorithm/src/CrackingCode/Hard/Count2fromOtoN.cpp -o /usr/build/Main.o
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
 *  Question :- Write a method to count the number of 2s between 0 and n.
 *
 *  last digit repeated every 10 number
 *  last 2 digit repeated every 100 number
 *  last 3 digit repeated every 10^3 number
 *
 */



/*
 *  So, if there are X 2s between 0 and 99, then we know there are 2x twos between 0 and 199. Between 0 and 299, we have 3x twos from the last two digits, and another 100 2s from the first digit.
In other words, we can look at a number like this:
f(513) = 5 * f(99) + f(13) + 100
To break this down individually:
»»The sequence of the last two digits are repeated 5 times, so add 5 * f(99)
»»We need to account for the last two digits in 500 -> 513, so add f(13)
»»We need to account for the first digit being two between 200 -> 299, so add 100
Of course, if n is, say, 279, we’ll need to account for this slightly differently:
f(279) = 2 * f(99) + f(79) + 79 + 1
To break this down individually:
»»The sequence of the last two digits are repeated 2 times, so add 2 * f(99)
»»We need to account for the last two digits in 200 -> 279, so add f(79)
»»We need to account for the first digit being two between 200 -> 279, so add 79 + 1
Recu rsive
 *
 */

int countdigits(int num ,int digit)
{
	int numOfDigits = 0;
   // base case
	if(num==0)
		return numOfDigits ;

   int power = 1;
   while(power*10 < num) power*=10 ;

   int first = num/power ;
   int remainder = num % power ;

   if(first > digit) numOfDigits += power ;
   else if(first==digit) numOfDigits+= remainder + 1;

   int noOfDigitsOther = first * countdigits(power-1,digit)+countdigits(remainder,digit);
  // cout<<"num= "<<num <<"power ="<<power <<" "<< noOfDigitsOther <<"  "<< numOfDigits<<"\n";
   return numOfDigits + noOfDigitsOther ;

}


void driver()
{
	cout<<"result 1 ="<<countdigits(479,1)<<"\n";
	cout<<"result 2 ="<<countdigits(479,2)<<"\n";
	cout<<"result 3 ="<<countdigits(479,3)<<"\n";
	cout<<"result 4 ="<<countdigits(479,4)<<"\n";
}
int main(){
	driver();
	cout<<"\n";
	return 0;
}
