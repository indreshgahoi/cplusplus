/*
 * MergeInterval.cpp
 *
 *  Created on: Apr 7, 2013
 *      Author: root
 */

#include "MergeInterval.h"
#include<algorithm>
#include "constant.h"
MergeInterval::MergeInterval() {
	// TODO Auto-generated constructor stub

}

MergeInterval::~MergeInterval() {
	// TODO Auto-generated destructor stub
}

/* Algorithms for merging Interval:-
 * step:- Sort the interval according to start time
 * push first interval on to stack
 * then check next interval let Say next Interval I and stack top interval SI
 *  if(SI.end<I.start) push(I)
 *  if(SI.end<I.end) {temp=pop();temp.end=I.end;push(temp);}
 *
 *After that all stack element are merging interval;
 */

std::ostream& operator<<(std::ostream& out,const Interval &I ){
	 out<<" ["<<I.start<<" "<<I.end<<"]";
	 return out;
 }

std::vector<Interval> MergeInterval::mergeOverLapInterval(std::vector<Interval> intervals){
   std::vector<Interval> S;
   sort(intervals.begin(),intervals.end());

  S.push_back(intervals[0]);

  for(int i=1;i<intervals.size();i++){
	  Interval top=S[S.size()-1];

	  if(top.end<intervals[i].start)
	  {
		  S.push_back(intervals[i]);
	  }
	  else if(top.end< intervals[i].end){
		  top.end=intervals[i].end;
		  S[S.size()-1]=top;
	  }
  }
 return S;
}

// Functions to run test cases
void TestCase1(MergeInterval &delegate)
{
    // Create a set of intervals
    Interval intvls[] = { {6,8}, {1,9}, {2,4}, {4,7} };
    vector<Interval> intervals(intvls, intvls+4);
    cout<<"Test case 1="<<intervals<<endl;
    // Merge overlapping inervals and print result
    cout<<"Test case 1="<<delegate.mergeOverLapInterval(intervals);
}
void TestCase2(MergeInterval &delegate)
{
    // Create a set of intervals
    Interval intvls[] = { {6,8},{1,3},{2,4},{4,7} };
    vector<Interval> intervals(intvls, intvls+4);
    cout<<"Test case 2="<<intervals<<endl;
    // Merge overlapping inervals and print result
    cout<<"Test case 2="<<delegate.mergeOverLapInterval(intervals);
}
void TestCase3(MergeInterval &delegate)
{
    // Create a set of intervals
    Interval intvls[] = { {1,3},{7,9},{4,6},{10,13} };
    vector<Interval> intervals(intvls, intvls+4);

    cout<<"Test case 3="<<intervals<<endl;
    // Merge overlapping inervals and print result
    cout<<"result of Test case 3="<<delegate.mergeOverLapInterval(intervals)<<endl;
}

void driver(){
	MergeInterval delegate;
	TestCase1(delegate);
	TestCase2(delegate);
	TestCase3(delegate);
}
