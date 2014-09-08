/*
 * TwoSum.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/Array/TwoSum.cpp -o /usr/build/Main.o
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




class Solution {
public:

	vector<int> *vv ;
	struct Comparator
	{

		 Comparator(const Solution &outer):outerRef(outer)
		 {

		 }

		 int operator() (const int &a , const int &b)
		 {

			 return (*(outerRef.vv))[a] <(*(outerRef.vv))[b];
		 }

		const Solution &outerRef ;
	};

    vector<int> twoSum(vector<int> &v, int target) {

        vector<int> arr ;

        for(int i = 0 ; i < v.size();i++)
        {
            arr.push_back(i);

        }
        vv= &v ;

        sort(arr.begin(),arr.end(),Comparator(*this));
        vector<int> res ;
        int l = 0 , r = v.size()-1;
        while(l<r)
        {
            if(v[arr[l]]+v[arr[r]] < target)
            {
                l++;
            }
            else if (v[arr[l]]+v[arr[r]]>target)
            {
                r--;
            }
            else
            {
                res.push_back(arr[l]+1);
                res.push_back(arr[r]+1) ;
                break ;
            }
        }
        sort(res.begin(),res.end());
        return res ;
    }
};

void driver()
{
  fstream fin("input.txt");	
  vector<int> input ;
  int x ;
  while(fin>>x) {
	  input.push_back(x);
  }
  Solution solver ;
  int target = input[input.size()-1];
  input.pop_back();
  cout<<"Solution "<<solver.twoSum(input,target);
}

/*
 input.txt 
 2 7 11 15 9
*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
