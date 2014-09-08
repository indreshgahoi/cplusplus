/*
 * ByteLandCoinDp.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/codechef/practice/ByteLandCoinDp.cpp -o /usr/build/Main.o
 *
 *  Created on: Mar 16, 2014
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

#define debug(x) cout<<#x" "<<x;
#define nl cout<<"\n";
#define tab cout<<"		";

void printArray(int A[], size_t size) {
	printf("values= [");
	for (int i = 0; i < size - 1; i++)
		printf("%d ,", A[i]);
	printf("%d]\n", A[size - 1]);
}

template<class T>
ostream& operator<<(ostream &out, const vector<T>& V) {
	out << "[";
	for (typename vector<T>::const_iterator it = V.begin(); it != V.end();
			it++) {
		out << " " << *it;
	}
	out << "]" << endl;
	return out;
}

void getInput(vector<int> &v) {
#define ARRAYSIZE(A) sizeof(A)/sizeof(A[0])
	int arr[] = { -1, -1, -1, 1, 1 };
	int size = ARRAYSIZE(arr);
	for (int iter = 0; iter < size; ++iter) {
		v.push_back(arr[iter]);
	}
}
/*
 Link :-  
 Question :-
 
 
 */
class Solution {
public:

	map<int, int> State;

	int solve(int x) {
		if (x == 1)
			return 1;
		if (State.find(x) != State.end())
			return State[x];
		int ans = 1 + solve(x - 1);
		ans = min(ans, solve(x >> 1));
		ans = min(ans, solve(x / 3));
		State[x] = ans;
		return ans;
	}

};

int nextInt() {
	int t;
	scanf("%d", &t);
	return t;
}
void printInt(int t) {
	printf("%d", t);
}
int main() {

	Solution solver;
	int t = nextInt();
	while (t-- > 0) {
		int x = nextInt();
		int ans = solver.solve(x);
		printInt(ans);
	}

	return 0;
}
