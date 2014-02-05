/*
 * twoStackInArray.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/stack/twoStackInArray.cpp -o /usr/build/Main.o
 *
 *  Created on: Jan 21, 2014
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

class TwoStack
{
private :
	 int *data ;
	 int top1 ;
	 int top2 ;
public :
	TwoStack(int n)
	{
	    data = new int[n] ;
	    top1 = -1 ;
	    top2 = size ;
	}

	void push1(int x)
	{
		if(top1< top2-1)
		{
			top1++;
			data[top1]=x ;
		}
		else
		{
			cerr<<"over flow" ;
			exit(1);
		}
	}
	void push(int x)
	{
		if(top1<top2-1)
		{
			top2--;
			data[top2]=x ;
		}
		else
		{
			cerr<<"over flow" ;
			exit(1);
		}
	}

	int pop1()
	{
		if(top1>=0)
		{
			int retVal = data[top1] ;
			top1--;
			return retVal ;
		}
		else
		{
			cerr<<"stack UnderFlow";
			exit(1) ;
		}

	}
	int pop2()
	{
		if(top2<size)
		{
			int retval = data[top2] ;
			top2++ ;
			return retval ;
		}
		else
		{
			cerr<<"Stack UnderFlow" ;
			exit(1) ;
		}
	}
};



void driver()
{
  fstream fin("input.txt");	

}
/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
