/*
 * LongestConsecutiveSequence.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/strings/LongestConsecutiveSequence.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 18, 2013
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
#include<unordered_map>
#include <unordered_set>

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
Link :-  http://discuss.leetcode.com/questions/1070/longest-consecutive-sequence
Question :-

	Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.


 */

/*
 *

Think as cluster merge, a single number is a length=1 cluster.

    The key factors about a cluster is: lowest, highest, and length.
    Map lowest and highest to length. To merge two neighbor clusters, only need to update it's new lowest and highest, with new length.
    For every a[i], checking its neighbor a[i]-1 and a[i]+1 is enough.

Code in Java:

public int findLongestConsequence(int[] a) {
    HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
    int max = 1;
    for (int i : a) {
        if (map.containsKey(i)) continue;
        map.put(i, 1);
        if (map.containsKey(i - 1)) {
            max = Math.max(max, merge(map, i-1, i));
        }
        if (map.containsKey(i + 1)) {
            max = Math.max(max, merge(map, i, i+1));
        }
    }
    return max;
}

private int merge(HashMap<Integer, Integer> map, int left, int right) {
    int upper = right + map.get(right) - 1;
    int lower = left - map.get(left) + 1;
    int len = upper - lower + 1;
    map.put(upper, len);
    map.put(lower, len);
    return len;
}

 *
 *
 *
 *
 *
 *
 */

int LongestConsecutiveSequence(vector<int> &nums)
{
	map<int,bool> hash;

	for(vector<int>::iterator it=nums.begin();it!=nums.end();++it)
	{
		hash[*it]= true ;
	}

	int max = 1;
	for(vector<int>::iterator it=nums.begin();it!=nums.end();++it)
	{
		if(!hash[*it]) continue ;
		int left = *it- 1;
		int right = *it + 1 ;
		int l = 0,r=0; ;
		while(hash[left])
		{
			l++;
			hash[left] = false;
			left--;
		}

		while(hash[right])
		{
			r++;
			hash[right] = false;
			right--;
		}

		if(max<(r+l+1)) max=(r+l+1);
	}
  return max;
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
