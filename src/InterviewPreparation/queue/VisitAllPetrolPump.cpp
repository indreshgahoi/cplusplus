/*
 * VisitAllPetrolPump.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/queue/VisitAllPetrolPump.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 24, 2013
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
#define debug(x) cout<<#x" "<<x<<"	";
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
Link :- http://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/
Question :-

Suppose there is a circle. There are n petrol pumps on that circle. You are given two sets of data.

1. The amount of petrol that petrol pump will give.
2. Distance from that petrol pump to the next petrol pump.

Calculate the first point from where a truck will be able to complete the circle (The truck will stop at each petrol pump and it has infinite capacity). Expected time complexity is O(n). Assume for 1 litre petrol, the truck can go 1 unit of distance.

For example, let there be 4 petrol pumps with amount of petrol and distance to next petrol pump value pairs as {4, 6}, {6, 5}, {7, 3} and {4, 5}. The first point from where truck can make a circular tour is 2nd petrol pump. Output should be “start = 1″ (index of 2nd petrol pump).

A Simple Solution is to consider every petrol pumps as starting point and see if there is a possible tour. If we find a starting point with feasible solution, we return that starting point. The worst case time complexity of this solution is O(n^2).

We can use a Queue to store the current tour. We first enqueue first petrol pump to the queue, we keep enqueueing petrol pumps till we either complete the tour, or current amount of petrol becomes negative. If the amount becomes negative, then we keep dequeueing petrol pumps till the current amount becomes positive or queue becomes empty.

Instead of creating a separate queue, we use the given array itself as queue. We maintain two index variables start and end that represent rear and front of queue.
  
  
*/

struct petrolPump
{
	int petrolAmount ;
	int nextDistance ;

};



class Solution
{
	public :

	int printTour(vector<petrolPump> &list , int startIdx)
	{
		int next = startIdx ;
		do {
			cout<<"["<<list[next].petrolAmount<<","<<list[next].nextDistance<<"] ";
			next = (next+1)%list.size();
			//if(next==startIdx)
			//	break ;
		}while(next!=startIdx) ;

  return 0 ;
	}

	int FindTour(vector<petrolPump> &list)
	{
		int size = list.size();

		int start = 0 ;
		int end = 1 ;

	    int canTravelDistance =list[start].petrolAmount-list[start].nextDistance;


	    while(start!=end || canTravelDistance < 0)
	    {


	    	while(start!=end && canTravelDistance < 0)
	    	{
	    	  //queue remove
              canTravelDistance = canTravelDistance-(list[start].petrolAmount-list[start].nextDistance) ;
              start = (start+1)%list.size() ;
              if(start==0)
            	  return - 1;

	    	}
             // queue add
	    	canTravelDistance = canTravelDistance+(list[end].petrolAmount-list[end].nextDistance) ;
	    	end = (end+1) %list.size();
	    }

	    return start ;
	}

   
};
void driver()
{
  fstream fin("input.txt");	
  Solution solver ;
  vector<petrolPump> list ;
  petrolPump p ;
  while(fin>>p.petrolAmount)
  {
	  fin>>p.nextDistance ;
	 list.push_back(p);
	 cout<<"["<<p.petrolAmount<<","<<p.nextDistance<<"] ";
  }
  nl
  int start =  solver.FindTour(list);

  if(start==-1)
  {
	  cout<<"NO tour" ;
  }
  else
  {
	  solver.printTour(list,start);
  }

}
/*
 input.txt 
6 4 3 6 7 3

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
