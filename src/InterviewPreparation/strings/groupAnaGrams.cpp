/*
 * groupAnaGrams.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/strings/groupAnaGrams.cpp -o /usr/build/Main.o
 *
 *  Created on: Dec 30, 2013
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
#include<list>
#include<queue>
#include <iterator>

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

    struct info
    {
        string str ;
        int idx ;
        info(string &str_,int idx_):str(str_),idx(idx_){}
    } ;
    struct InfoComparator
    {
        bool operator()(const info &i1 ,const info &i2)
        {
            return i1.str < i2.str ;
        }
    } ;

    vector<string> anagrams(vector<string> &strs) {

        int size = strs.size() ;
        vector<info> infos ;
        vector<string> result ;

        for( int iterator = 0 ; iterator < size ; ++iterator)
        {
            string temp = strs[iterator] ;
            sort(temp.begin(),temp.end()) ;
            info info(temp,iterator) ;
            infos.push_back(info);
        }
        std::sort(infos.begin() , infos.end(),Solution::InfoComparator()) ;
        for(int iterator = 0 ; iterator < size ; ++iterator)
        {
            result.push_back(strs[infos[iterator].idx]) ;
        }
        return result ;
    }
};

// Solution For leetCode
class Solution1 {
public:

    vector<string> anagrams(vector<string> &strs) {

        int size = strs.size() ;
        map<string,list<string> > anaGramsMap ;
        vector<string> result ;

        for( int iterator = 0 ; iterator < size ; ++iterator)
        {
            string temp = strs[iterator] ;
            sort(temp.begin(),temp.end()) ;
            map<string,list<string> >::iterator anaGramsit = anaGramsMap.find(temp) ;
            if(anaGramsit==anaGramsMap.end())
            {
            	list<string> strList ;
            	strList.push_front(strs[iterator]);

            	anaGramsMap[temp] = strList ;
            }
            else
            {
            	list<string > &list = anaGramsit->second ;
            	list.push_front(strs[iterator]) ;
            }


        }
        map<string,list<string> >::iterator anaGramsit = anaGramsMap.begin();
        for( ;anaGramsit != anaGramsMap.end() ; ++anaGramsit)
        {
        	list<string > &strsList = anaGramsit->second ;
        	if(strsList.size()>1)
        	{
        		list<string>::iterator strsListIterator = strsList.begin() ;
        		for(; strsListIterator != strsList.end();++strsListIterator)
        		{
        			result.push_back(*strsListIterator) ;
        		}
        	}
        }

        return result ;
    }
};





void driver()
{
  fstream fin("input.txt");
  string str ;
  vector<string> strs ;
  while( fin >> str)
  {
	  strs.push_back(str) ;
  }
  Solution1 solver ;

  cout<<"[ "<<strs<<" ]\n";

  cout<<" [ "<<solver.anagrams(strs)<<" ] \n";

}
/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
