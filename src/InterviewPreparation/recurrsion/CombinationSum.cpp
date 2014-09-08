/*
 * CombinationSum.cpp
 *
 *  Created on: Jul 20, 2014
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<cstdio>

using namespace std ;


template<class T>
ostream& operator<<(ostream &out,const vector<T>& V){
	out<<"[";
	for(typename vector<T>::const_iterator it=V.begin();it!=V.end();it++){
		out<<" "<<*it;

	}
	out<<"]";
	return out;
}



class Solution {
public:

	vector<vector<int> > result ;


	void combinationSumHelper(vector<int> &arr,int start ,int target , int currentSum , vector<int> &path)
	{
		if(currentSum==target){
			result.push_back(path);

		}
		if(currentSum < target){

			for(size_t i = start ; i < arr.size();++i){
				int remian = target - currentSum ;
				if(arr[i] <= remian){
					path.push_back(arr[i]);
					combinationSumHelper(arr,i,target,currentSum+arr[i],path);
					path.pop_back();
				}
			}
		}

	}
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
                    vector<int> path ;
                    result.clear();
         sort(candidates.begin(),candidates.end(),less<int>());
    	 combinationSumHelper(candidates,0,target,0,path);
    	 return result ;
    }
};

class Solution2 {
public:

	vector<vector<int> > result ;


	void combinationSumHelper(vector<int> &arr,size_t start ,int target , int currentSum , vector<int> &path)
	{
		if(currentSum==target){
			result.push_back(path);

		}
		if(currentSum < target){

			for(size_t i = start ; i < arr.size();++i){
				if(i!= start && arr[i]==arr[i-1]) continue ;
				int remian = target - currentSum ;
				if(arr[i] <= remian){
					path.push_back(arr[i]);
					combinationSumHelper(arr,i+1,target,currentSum+arr[i],path);
					path.pop_back();
				}
			}
		}

	}
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
                    vector<int> path ;
                    result.clear();
         sort(candidates.begin(),candidates.end(),less<int>());
    	 combinationSumHelper(candidates,0,target,0,path);
    	 return result ;
    }
};

int main(){
	Solution2 sol ;
	vector<int> can = {1,1}; //{10,1,2,7,6,1,5} ;
	int target = 1 ;
	vector<vector<int> > res = sol.combinationSum(can,target);
    cout<<res ;
   return 0 ;
}
