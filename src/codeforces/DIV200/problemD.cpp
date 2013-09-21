/*
 * problemD.cpp
 *
 *  Created on: Sep 20, 2013
 *      Author: Indresh Gahoi
 */


#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>
#include <string.h>
using namespace std;

#define REP(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(int i=a;i>b;i--)
#define SET(x,a) memset(x,a,sizeof(x));
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define tr(i,a) for( __typeof__(a.begin()) i=a.begin();i!=a.end();i++)
#define pb push_back
#define sz(a) (int)(a.size())
#define INF 100000000000000000LL
#define EPS (double)1e-9
#define is istringstream
#define os ostringstream
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
typedef unsigned long long ULL;
typedef long long LL;
typedef set <int> si;
typedef pair< int,int > ii;
typedef pair< int, ii > pi;
typedef vector< ii > vii;
typedef vector < vii > vvii;
typedef vector< int > vi;
typedef vector< vi > vvi;



/* Main code Start */
char buf[100000];
stack<char> st;

void input(){
	scanf("%s",buf);
}
void output(){

}

void solve(){
 char *str=buf;
 char ch;
 char *result;
 while((ch=*str++)!='\0'){
	 if(!st.empty() && st.top()==ch)
		 st.pop();
	 else
		 st.push(ch);
 }
	if(st.empty()){
	  result="YES";
	}
	else{
		result="NO";
	}
	cout<<result;
}
int main(){
	input();
	solve();
	//output();
	return 0;
}


