/*
 * FourSum.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/Array/FourSum.cpp -o /usr/build/Main.o
 *
 *  Created on: Jan 20, 2014
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

// O((n^4)
class Solution
{
	public :
   
	void FourSum(int A[] , int n , int targetSum)
	{

		for(i = 0 ; i<n-3 ; ++i)
		{
			for(int j = i+1 ; j < n-2 ;++j)
			{
				for(int k = j+1 ; k < n-1 ;++k)
				{
					for(int l = k+1 ; i < n ;++l)
					{
						if(A[i]+A[j]+A[k]+A[l]==targetSum)
						{
							printf("%d %d %d %d \n",i,j,k,l) ;
						}
					}
				}
			}
		}

	}

};

// o(n^3) solution


class Solution1
{

 public :

	void FourSum(int A[] , int n , int targetSum)
	{
		sort(A,A+n) ;

		for(int i = 0 ; i < n-3 ; ++i)
		{
			for(int j = i+1 ; j <n-2 ; ++j)
			{
				int l = j+1 ;
				int r = n-1 ;
				while(l<r)
				{
					int t = (A[i]+A[j]+A[l]+A[r]) ;
					if(targetSum == t)
					{
						printf("%d %d %d %d \n",i,j,l,r) ;
						l++ ;
						r-- ;
					}
					else if(t < targetSum )
						l++ ;
					else
						r-- ;
				}
			}
		}
	}

};

// O(n^2logn) method

class Solution2
{
public :

	struct Pair
	{
		int f ;
		int s ;
		int sum ;
		int operator<(const Pair &other)
		{
			return sum<other.sum ;
		}
	};
	bool isSafePair(Pair &p1,Pair &p2)
	{
		if(p1.f==p2.f || p1.f==p2.s || p1.s==p2.f || p1.s==p2.s) return false ;
		return true ;
	}
	void FindFourSum(int A[] , int n , int targetSum)
	{
		int size = n * (n-1)/2 ;
		Pair B[size] ;
		int count = 0 ;
		for(int i = 0 ; i<n-1 ;++i)
		{
			for(int j = i+1 ; j<n ;++j)
			{
				B[count].f = i ;
				B[count].s = j ;
				B[count].sum = A[i]+A[j] ;
				count++ ;
			}
		}

		sort(B,B+size);
		int l = 0 ;
		int r = size-1 ;
		while(l<size && r>=0)
		{
			if(B[l].sum+B[r].sum==targetSum && isSafePair(B[l],B[r]))
			{
               printf("%d %d %d %d \n",B[l].f,B[l].s,B[r].f,B[r].s);
				l++ ;
				r-- ;
			}
			else if(B[l].sum+B[r].sum<targetSum)
			{
				l++ ;
			}
			else
				r-- ;

		}
	}

};
void driver()
{
  fstream fin("input.txt");	
  Solution solver ;
}
/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
