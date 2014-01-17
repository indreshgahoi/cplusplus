/*
 * IsArrayElementareConsecutive.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/Array/geeksforgeeks/IsArrayElementareConsecutive.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 16, 2013
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
	int arr[] = {5,7,10,3,8,1,6,9,2,4};
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
/* Link :- http://www.geeksforgeeks.org/check-if-array-elements-are-consecutive/
 *  Question : -
		Check if array elements are consecutive | Added Method 3

 *  To attack the problem
 *  Lest Array A[1.....A.length]
 *  find max
 *  fin min
 *  if (max-min + 1) == A.lengh
 *   {
 *    now the problem change
 *     	if there are repeating element return false
 *
 *   }
 *   return true ;
 *
 */

bool isArrayConsecutive(vector<int> &A)
{
	int max=A[0] , min=A[0] ;

	for(int i = 1 ; i < A.size() ; ++i)
	{
		if(A[i] < min)
		{
			min = A[i];
		}
		else if(A[i] > max)
		{
			max = A[i] ;
		}
	}

	if((max-min+1)==A.size())
	{
		// check there are unique elements
		vector<bool> visited(A.size(),false);

		for( int i = 0 ; i < A.size() ; ++i)
		{
			if(!visited[abs(A[i]-min)])
			{
				visited[abs(A[i]-min)] = true ;
			}
			else
			{
				return false ;
			}

		}
		return true ;

	}
	return false ;
}


/* The function checks if the array elements are consecutive
  If elements are consecutive, then returns true, else returns
  false */
bool areConsecutive(int arr[], int n)
{

    if ( n <  1 )
        return false;
    int max=arr[0] , min=arr[0] ;

    	for(int i = 1 ; i < n ; ++i)
    	{
    		if(arr[i] < min)
    		{
    			min = arr[i];
    		}
    		else if(arr[i] > max)
    		{
    			max = arr[i] ;
    		}
    	}

    /* 3) max – min + 1 is equal to n then only check all elements
     * */

    	if (max – min + 1 == n)
    	{
    		int i;
    		for(i = 0; i < n; i++)
    		{
    			int j;

    			if (arr[i] < 0)
    				j = -arr[i] – min;
    			else
    				j = arr[i] – min;

            // if the value at index j is negative then
            // there is repitition
    			if (arr[j] > 0)
    				arr[j] = -arr[j];
    			else
    				return false;
    		}

        /* If we do not see a negative value then all elements
           are distinct */
    		return true;
    }

    return false; // if (max – min  + 1 != n)
}





void driver()
{
	vector<int> v ;
	getInput(v) ;
	cout<<v;

	if(isArrayConsecutive(v))
	{
		cout<<"Consecutive\n";
	}
	else
	{
		cout<<"It's not\n";
	}
}




int main(){
	driver();
	cout<<"\n";
	return 0;
}
