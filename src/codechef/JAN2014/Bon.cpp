/*
 * Bon.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/codechef/JAN2014/Bon.cpp -o /usr/build/Main.o
 *
 * Created on: Jan 9, 2014
 * Author: Indresh Gahoi
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
#define REP(_i,n) for(int _i=0;_i<n;_i++)
#define debug(x) cout<<#x" "<<x;
#define nl cout<<"\n";
#define tab cout<<" ";
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

typedef long long int Integer ;

struct Interval
{
	Integer si ;
	Integer fi ;

	int operator < (const Interval &other) const
	{
		return fi<other.fi ;
	}
};

class Solution
{
public :
	map<Integer,vector<Interval> > personTime ;
	Integer getSize(vector<Interval> &V)
	{
		std::sort(V.begin(),V.end());
		Integer iter = 0 , size = V.size() ;
		Integer preIndex = 0 ;
        Integer res = 1;
		for( iter = 1 ; iter<size ; ++iter)
		{
			if(V[iter].si>=V[preIndex].fi)
			{
				preIndex = iter ;
				res++;
			}
		}
		return res ;
	}

	void solve()
	{
		map<Integer,vector<Interval> >::iterator it ;
		Integer result = 0 ;
		for( it = personTime.begin() ; it != personTime.end() ;++it)
		{
			result+=getSize(it->second) ;
		}
       printf("%lld\n",result);
	}
};

/*
input.txt
2
3 3
1 3 1
4 6 2
7 10 3
4 2
10 100 1
100 200 2
150 500 2
200 300 2

 */
int main(){
	Integer T ;
	cin>>T ;
	Integer si,fi,pi ,N,K;
	Interval interval ;
	while(T--)
	{
		Solution solver ;
	scanf("%lld%lld",&N,&K);
		while(N--)
		{
			scanf("%lld%lld%lld",&interval.si,&interval.fi,&pi);
			solver.personTime[pi].push_back(interval) ;
		}
		solver.solve();
	}
	return 0;
}
