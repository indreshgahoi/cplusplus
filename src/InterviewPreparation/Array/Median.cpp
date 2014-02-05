/*
 * Median.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/Array/Median.cpp -o /usr/build/Main.o
 *
 *  Created on: Feb 1, 2014
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
// count while merging

class Solution
{
	public :

	int  Median(int A[],int B[] , int n)
	{
		int m1 , m2 ;
		int i , j ,count  ;
		i = j = 0 ;
		m1 = m2 = - 1;

		for(count = 0 ; count<=n ; ++count)
		{
			if(i==n)
			{
				m2 = m1 ;
				m1 = B[0] ;break ;
			}
			else if(j==n)
			{
				m2 = m1 ;
				m1 = A[0] ;
				break ;
			}
			if(A[i]<B[j])
			{
				m2 = m1 ;
				m1 = A[i] ;
				i++;
			}
			else
			{
				m2 = m1 ;
				m1 = B[j] ;
				j++;
			}
		}
		return (m1+m2)/2;
	}

};

 // By Comparing median
//

class Solution1
{
public :

	int getMedian(int A[],int n)
	{
		if(n&1)
		{
			return A[n/2];
		}
		else
			return (A[n/2-1]+A[n/2])/2;
	}
	int Median(int A[],int B[],int n)
	{
		if(n<=0) return -1 ;

		if(n==1) return (A[0]+B[0])/2;

		if(n==2) return (max(A[0],B[0])+min(A[1],B[1]))/2;

		int m1 = getMedian(A,n);
		int m2 = getMedian(B,n);
		if(m1==m2) return m1;


		if(m1<m2)
		{
			if(n&1)
			{
				return Median(A+n/2,B,n-n/2);
			}
			else
				return Median(A+n/2-1,B,n-n/2+1);
		}
		else
		{
			if(n&1)
			{
				return Median(B+n/2,A,n-n/2);
			}
			else
			{
				return Median(B+n/2-1,A,n-n/2+1);
			}
		}
	}
};



/* To find out the median in Array A and B
 *  A[0...i...n-1] B[0...j...n-1]
 *
 *  A[i] and A[j]
 *   i+1 element in A
 *   j+1 element in B
 *  To find out the median we have should observer n+1 element
 *   mean of (n and n+1) element is median
 *
 *  i+j+1+1 = n+1
 *  i+j+1 = n
 *  i = (l+r)/2
 *  j = n-i-1
 *
 *  if B[j]<=A[i]<=B[j+1]
 *  then m1 = A[i] is n+1 element
 *  m2 = Max(B[j],A[i-1]) is the n th element
 *
 *  Median = (m1+m2)/2 ;
 *
 *
 */


class Solution3
{
	public:

	int getMedianUtil(int A[],int B[],int left , int right,int n)
	{
		if(left>right)
		{
		  printf("Change the Value \n");
		  debug(left)
		  debug(right)
          return getMedianUtil(B,A,0,n-1,n);
		}
		else
		{
			int i = left+(right-left)/2;
			int j = n-i-1 ; //  max val of j when i is min i = 0

			if(A[i]> B[j] && (j==n-1 || A[i]<=B[j+1]))
			{
				if(i==0) return (A[i]+B[j])/2 ;
				return (A[i]+max(A[i-1],B[j]))/2 ;
			}

			if(A[i]>B[j] && j!=n-1 && A[i]>B[j+1])
				return getMedianUtil(A,B,left,i-1,n);
			else
				return getMedianUtil(A,B,i+1,right,n);
		}
	}

	/*
	   *  We can optmize the case
	   *  1 2 3
	   *  4 5 6
	   *   to O(1) case
	   */
     int Median(int A[],int B[],int n)
     {
    	 int m ;
    	 if(A[n-1]<B[0])
    		 m= (A[n-1]+B[0])/2 ;
    	 else if(B[n-1]<A[0]) m = (B[n-1]+A[0])/2 ;
    	 else
         m= getMedianUtil(A,B,0,n-1,n);
         printf("median = %d \n",m);
         return m ;
     }


};

// for unequal length
/*
 * There are two sorted arrays A and B of size m and n respectively.
 * Find the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 */
class Solution4
{
 public :

    double MO4(int a, int b,int c,int d)
    {
    	return ((a+b+c+d)-max(max(a,b),max(c,d))-min(min(a,b),min(c,d)))/2.0 ;
    }
    double MO3(int a,int b,int c)
    {
    	return (a+b+c)-max(a,max(b,c))-min(a,min(b,c));
    }
    double MO2(int a ,int b)
    {
    	return (a+b)/2.0;
    }

    double getMedian(int A[],int m ,int B[],int n)
    {

    	if(m==0)
    	{
    		if(n&1)
    			return B[n/2]*1.0;
    		else
    			return MO2(B[n/2],B[n/2-1]);
    	}

    	if(m == 1)
    	{
    		if(n==1)
    			return MO2(A[0],B[0]) ;
    		if(n & 1)
    		 return MO2(B[n/2],MO3(A[0],B[n/2-1],B[n/2+1])) ;
    		return MO3(B[n/2-1],B[n/2],A[0]);
    	}
    	if(m==2)
    	{
    		if(n==2)
    			return MO4(A[0],A[1],B[0],B[1]);
    		if(n & 1)
    			return MO3(max(B[n/2-1],A[0]),B[n/2],min(B[n/2+1],A[1]));
    		return MO4(B[n/2],B[n/2-1],max(B[n/2-2],A[0]),min(B[n/2+1],A[1]));
    	}
    	int i = (m-1)/2;
    	int j = (n-1)/2 ;

    	if(A[i]<B[j])
    	{
    			return getMedian(A+i,m-i,B,n-i);
    	}
    	else {
    	return getMedian(A,m-i,B+i,n-i);
    	}
    }

    double findMedianSortedArrays(int A[],int m ,int B[],int n)
    {
    	if(m<n)
    		return getMedian(A,m,B,n);
    	return getMedian(B,n,A,m);
    }

};
void driver()
{
  fstream fin("input.txt");	
  int m,n ;
  fin>>m;
  vector<int> A,B;
  for(int t = 0 ; t<m;++t)
  {
	  int x ;
	  fin>>x;
	  A.push_back(x);
  }
  fin>>n ;
  for(int t = 0 ; t<n;++t)
  {
  	  int x ;
  	  fin>>x;
  	  B.push_back(x);
  }

  Solution4 solver ;
  cout<<"median = "<<solver.findMedianSortedArrays(&A[0],m,&B[0],n);
}
/*
 input.txt 

3
1 2 5
3
3 4 6


3
1 2 3
4
4 5 6 7

3
1 5 6
3
2 4 6


3
1 5 6
3
2 3 4

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
