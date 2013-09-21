/*
 * problem500.cpp
 *
 *  Created on: Sep 21, 2013
 *      Author: Indresh Gahoi
 */


#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class ConvertibleStrings {
public:
	string A,B;
	int ans;
	char p[]={'A','B','C','D','E','F','G','H','I'};
	int leastRemovals(string, string);
	void rec(int);
	 void check();
};

int ConvertibleStrings::leastRemovals(string A, string B) {

	this->A=A;
	this->B=B;
	ans=A.size();
	rec(0);
  return ans;
}
void ConvertibleStrings::check(){
	int diff=0;
	for(int i=0;i<A.size();++i){
		if(B[i]!=p[A[i]-'A'])
			diff++;
	}
    ans=diff<ans?diff:ans;
}
void ConvertibleStrings::rec(int x){
	if(x==9){
		check();
	}
	else
	{
		for(int i=x;i<9;++i){
            swap(p+i,p+x);
			rec(x+1);
			swap(p+i,p+x);

		}
	}
}

double test0() {
	string p0 = "DD";
	string p1 = "FF";
	ConvertibleStrings * obj = new ConvertibleStrings();
	clock_t start = clock();
	int my_answer = obj->leastRemovals(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string p0 = "AAAA";
	string p1 = "ABCD";
	ConvertibleStrings * obj = new ConvertibleStrings();
	clock_t start = clock();
	int my_answer = obj->leastRemovals(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string p0 = "AAIAIA";
	string p1 = "BCDBEE";
	ConvertibleStrings * obj = new ConvertibleStrings();
	clock_t start = clock();
	int my_answer = obj->leastRemovals(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string p0 = "ABACDCECDCDAAABBFBEHBDFDDHHD";
	string p1 = "GBGCDCECDCHAAIBBFHEBBDFHHHHE";
	ConvertibleStrings * obj = new ConvertibleStrings();
	clock_t start = clock();
	int my_answer = obj->leastRemovals(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 9;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;

	time = test0();
	if (time < 0)
		errors = true;

	time = test1();
	if (time < 0)
		errors = true;

	time = test2();
	if (time < 0)
		errors = true;

	time = test3();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}


