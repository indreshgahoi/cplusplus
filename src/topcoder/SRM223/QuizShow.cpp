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

// SRM 223 DIV1 EASY Probability

class QuizShow {
public:
	int wager(vector <int>, int, int);
};

int QuizShow::wager(vector <int> scores, int wager1, int wager2) {
	int bet = 0 , best = 0 ;
	for(int wager = 0 ; wager <= scores[0] ; wager++){
		int odds  = 0 ; 
			for(int i = -1 ; i < 2 ; i = i + 2){
				for(int j = -1 ; j < 2 ; j = j + 2){
					for(int k = -1 ; k < 2 ; k = k + 2){
						if(scores[0] + wager * i > scores[1] + j * wager1 && scores[0] + wager * i > scores[2] + k * wager2) odds++ ;
						if(  odds > best ) { best = odds ; bet = wager ; }
					}
				}
			}
	}
	return bet ;
}


double test0() {
	int t0[] = { 100, 100, 100 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 25;
	int p2 = 75;
	QuizShow * obj = new QuizShow();
	clock_t start = clock();
	int my_answer = obj->wager(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 76;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = { 10, 50, 60 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 30;
	int p2 = 41;
	QuizShow * obj = new QuizShow();
	clock_t start = clock();
	int my_answer = obj->wager(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = { 10, 50, 60 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 31;
	int p2 = 41;
	QuizShow * obj = new QuizShow();
	clock_t start = clock();
	int my_answer = obj->wager(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 10;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = { 2, 2, 12 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 0;
	int p2 = 10;
	QuizShow * obj = new QuizShow();
	clock_t start = clock();
	int my_answer = obj->wager(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = { 10000, 10000, 10000 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 9998;
	int p2 = 9997;
	QuizShow * obj = new QuizShow();
	clock_t start = clock();
	int my_answer = obj->wager(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 9999;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int t0[] = { 5824, 4952, 6230 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 364;
	int p2 = 287;
	QuizShow * obj = new QuizShow();
	clock_t start = clock();
	int my_answer = obj->wager(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 694;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}



//Powered by [KawigiEdit] 2.0!
