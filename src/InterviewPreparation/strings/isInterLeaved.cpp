/*
 * isInterLeaved.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/strings/isInterLeaved.cpp -o /usr/build/Main.o
 *
 *  Created on: Jan 18, 2014
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

/*
 *  This Solution Would not work when there is tie
 *
 *
 */
class Solution
{
public :

	bool isInterLeaved(string &str1 , string &str2 , string &str3)
	{
		size_t l1 ,l2,l3 ;
		int i , j ,k ;
		l1= str1.size() ;
		l2 = str2.size() ;
		l3 = str3.size() ;
		i =j = k = 0 ;
		while(k<l3)
		{
			if(i<l1 && str1[i]==str3[k]) i++ ;
			else if(j<l2 && str2[j]==str3[k]) j++ ;
			else return false ;
			k++ ;
		}
		if(i!=l1 || j != l2) return false ;
		return true ;
	}

};


/*
 *
 * worst case time complexity in 2^n
 *
 *  This Recurrsive Solution
 *   Submission Result: Time Limit Exceeded
 */

class Solution1
{
public :

	bool isImterLeaved(const char *s1,const char *s2,const char *s3)
	{
		if(*s1=='\0' && *s2=='\0' && *s3=='\0') return true ;

		if(*s3=='\0') return false ;

		if(*s1==*s3 && *s2==*s3) return  isInterLeaved(s1+1,s2,s3+1) || isInterLeaved(s1,s2+1,s3+1) ;

		else if(*s1 != '\0' && *s1==*s3) return isInterLeaved(s1+1,s2,s3+1) ;
		else if(*s2 != '\0' && *s2==*s3) return isInterLeaved(s1,s2+1,s3+1) ;
		return false ;
	}


	bool isInterLeaved(string str1 , string str2 , string str3)
	{
		const char *s1 =str1.c_str() ;
		const char *s2 = str2.c_str() ;
		const char *s3  = str3.c_str() ;
		return isInterLeaved(s1,s2,s3);
	}

};

/*
 *  Now come to Dp Solution
 *
 *   Base Case when
 *   S...Si
 *   S....Sj
 *
 *   dp[i][j]
 *
 */
class Solution3 {
public:
	bool isInterleave(string A , string B , string C)
	{
		size_t l1 = A.size() ;
		size_t l2 = B.size() ;
		size_t l3 = C.size() ;

		if(l3-l1-l2) return false ;

		vector<vector<bool> > dp(l1+1,vector<bool>(l2+1,false)) ;

		dp[0][0] = true ;
		for( int i = 1 ; i <=l2; ++i)
			dp[0][i] = dp[0][i-1] & (C[i-1]==B[i-1]) ;
		for(int i = 1;i<=l1;++i)
			for(int j = 0 ; j<=l2 ; ++j)
			{
				if(j==0){
					dp[i][j] = dp[i-1][j] & A[i-1]==C[i-1] ;
					continue ;
				}

				if(A[i-1]==C[i+j-1]) dp[i][j] = dp[i-1][j] ;
				else dp[i][j]= false ;
				if(B[j-1]==C[i+j-1]) dp[i][j] = dp[i][j]| dp[i][j-1] ;
			}
		return dp[l1][l2] ;
	}
};

/*
 *
 *  Make it Memory efficient
 *
 */

class Solution4 {
public:
	bool isInterleave(string A , string B , string C)
	{
		size_t l1 = A.size() ;
		size_t l2 = B.size() ;
		size_t l3 = C.size() ;

		if(l3-l1-l2) return false ;

		vector<vector<bool> > dp(2,vector<bool>(l2+1,false)) ;

		dp[0][0] = true ;
		for( int i = 1 ; i <=l2; ++i)
			dp[0][i] = dp[0][i-1] & (C[i-1]==B[i-1]) ;
		for(int i = 1;i<=l1;++i)
			for(int j = 0 ; j<=l2 ; ++j)
			{
				if(j==0) dp[i&1][j] = dp[(i-1)&1][j] & A[i-1]==C[i-1] ;

				if(A[i-1]==C[i+j-1]) dp[i&1][j] = dp[(i-1)&1][j] ;
				else dp[i&1][j] = 0 ;
				if(B[j-1]==C[i+j-1]) dp[i&1][j] = dp[i&1][j]| dp[i&1][j-1] ;
			}
		return dp[l1&1][l2] ;
	}
};


void driver()
{
	fstream fin("input.txt");
	Solution solver ;
	string str1 ;
	string str2 ;
	string str3 ;

	while(fin>>str1>>str2>>str3)
	{
		if(solver.isInterLeaved(str1,str2,str3))
		{
			printf(" hi it is interleaved\n") ;
		}
		else
		{
			printf("ooh it's not");
		}
	}
}
/*
 input.txt 

 */
int main(){
	driver();
	cout<<"\n";
	return 0;
}
