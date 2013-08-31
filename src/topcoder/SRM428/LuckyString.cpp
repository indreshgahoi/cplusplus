/*
 * LuckyString.cpp
 *
 *  Created on: Jan 14, 2013
 *      Author: indresh
 */
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int len;
bool isLucky(string &s){
	int i=0;
	while(i<(s.length()-1) && s[i]!=s[i+1] )i++;
	if(i==(len-1))
		return true;
	return false;
}
bool myNextPermutedString(string &s){
	int i=len-2;
	while(s[i]>=s[i+1] && i>=0)i--;
	if(i<0){
		return false;
	}
	int j=len-1;
	while(s[i]>=s[j])j--;
	char tmp=s[j];
	s[j]=s[i];
	s[i]=tmp;
	j=len-1;
	i++;
	while(i<j){
		tmp=s[j];
			s[j]=s[i];
			s[i]=tmp;
			i++;j--;
	}
	return true;
}

int count(string s){
	len=s.length();
	sort(s.begin(),s.end());
	int count=0;

	do{
		if(isLucky(s))
		count++;
	}while(myNextPermutedString(s));
	return count;
}

int main(){
	string s;
	cin>>s;

	cout<<count(s);
}


