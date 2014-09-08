/*
 * printAllCombinationOfParanthesis.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/recurrsion/printAllCombinationOfParanthesis.cpp -o /usr/build/Main.o
 *
 *  Created on: Dec 25, 2013
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
struct paraenthesis_pair
{
	char open ;
	char close ;
};


class Solution
{
	public :
	vector<string> result ;
    void _all_combination(int noOfPair ,int open_no , int close_no ,vector<char> &comb , paraenthesis_pair &par)
    {
    	if(close_no==noOfPair)
    	{
    		//cout<<" "<<comb ;
    		 string str ;
    		    	    for(int i = 0 ; i < comb.size() ; ++i){
    		    	        str.push_back(comb[i]);
    		    	    }
    		    		result.push_back(str);
    		    		return ;
    		return ;
    	}
        // two possibilities open or close
    	if(open_no < noOfPair)
    	{
    		comb.push_back(par.open) ;
    		_all_combination(noOfPair,open_no+1,close_no,comb,par) ;
    		comb.pop_back() ;
    	}
    	if(open_no > close_no)
    	{
    		comb.push_back(par.close) ;
    		_all_combination(noOfPair,open_no,close_no+1,comb,par);
    		comb.pop_back();
    	}
    }
	void allCombinationParanethesis(int noOfPair ,paraenthesis_pair par_pair)
	{
	  vector<char> comb ;
     _all_combination(noOfPair,0,0,comb,par_pair) ;
	}

	vector<string> generateParenthesis(int n) {
		paraenthesis_pair  par ;
		  par.open =  '(' ;
		  par.close = ')' ;
		  result.clear();
		  allCombinationParanethesis(n,par);
		  return result;
	}

};
void driver()
{
  //fstream fin("input.txt");
  paraenthesis_pair  par ;
  par.open =  '{' ;
  par.close = '}' ;
  Solution solver ;
  solver.allCombinationParanethesis(3,par);
}
/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
