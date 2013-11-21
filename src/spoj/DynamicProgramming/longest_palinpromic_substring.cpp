/*
 * longest_palinpromic_substring.cpp
 *
 *  Created on: Oct 23, 2013
 *      Author: Indresh Gahoi
 */



#include<iostream>
#include<string>
#include<vector>


using namespace std;

pair<int,int> longest_palindromic_substring(string &seq){

	int size=seq.size();
	int maxlen=1 , start=0;
	bool **table;

	table= new bool*[size];

	 for(int i=0;i<size;++i){
		 table[i]=new bool[size];
	 }
	// tabel initialization
	for(int i=0;i<size;++i){
		table[i][i]=true;
		if(i!=size && seq[i]==seq[i+1]){
			table[i][i+1]=true;
			maxlen=2;
			start=i;
		}
	}

	// filling tabel
	for(int l=3 ; l<=size;++l){
		for(int s=0;s<size-l+1;++s){
			int e=s+l-1;
			if(table[s+1][e-1] && seq[s]==seq[e]){
				table[s][e]=true;
				if(l>maxlen){
					maxlen=l;
					start = s;
				}
			}
		}
	}

	return make_pair(maxlen,start);
}

int main(){

    string str("forgeeksskeegfor");
	pair<int,int> info = longest_palindromic_substring(str);
	cout<<"Longest length= "<<str.substr(info.second,info.first);
	return 0;
}

