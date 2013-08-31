/*
 * TextJustiFication.cpp
 *
 *  Created on: Mar 28, 2013
 *      Author: indresh
 */


#include<iostream>
#include <cstdio>
#include<vector>
using namespace std;

vector<string> res;
void fulljustifyHelper(vector<string> &words,int start,int L){

	int noOfwords=0,totalChar=0,end=0,noOfSpaces=0;
	for(int i=start;i<words.size();i++){
		 noOfwords++;
         totalChar+=words[i].size()+(noOfwords-1);
		if(totalChar>L){
			end=i-1;
			noOfwords--;
			noOfSpaces=L-(totalChar-noOfwords);
		}
		else if(totalChar==L){
			end=i;
		}
	}


}

vector<string> fullJustify(vector<string> &words, int L) {
       res.clear();
	return res;
}

int main(){
return 0;
}

