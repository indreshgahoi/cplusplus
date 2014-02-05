/*
 * longest_biotonic_subsequence.cpp
 *
 *  Created on: Oct 23, 2013
 *      Author: Indresh Gahoi
 */


#include<iostream>
#include <vector>
using namespace std;


int longest_biotonic_subsequence(vector<int> &array){

	vector<int> lis(array.size(),1) , lds(array.size(),1);
	//vector<int> lbs(array.size(),1);
    int maxlen=-1;

	for(int i =1; i< array.size() ; ++i){
		for(int j=0;j<i; ++j){

			if(array[i]> array[j] && lis[i]< lis[j]+1)
				lis[i]=lis[j]+1;
		}
	}

	for(int i =array.size()-2;i>=0 ; --i){
		for(int j=array.size()-1;j>i; --j){
			if(array[i]> array[j] && lds[i]< lds[j]+1)
				lds[i]=lds[j]+1;
		}
	}


	for(int i=0 ; i<array.size() ; ++i){
		if(maxlen < (lis[i]+lds[i]-1)){
			maxlen=lis[i]+lds[i]-1;
		}
	}

 return maxlen;
}

void test(){
 vector<int> seq;
  seq.push_back(0);
  seq.push_back(8);
  seq.push_back(4);
  seq.push_back(12);
  seq.push_back(2);
  seq.push_back(10);
  seq.push_back(6);
  seq.push_back(14);
  seq.push_back(1);
  seq.push_back(9);
  seq.push_back(5);
  seq.push_back(13);
  seq.push_back(3);
  seq.push_back(11);
  seq.push_back(7);
  seq.push_back(15);


  cout<<"\nLength :\n"<<longest_biotonic_subsequence(seq);
}


int main(){
	test();
	return 0;
}


