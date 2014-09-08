/*
 * JumpGame.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/Array/geeksforgeeks/JumpGame.cpp -o /usr/build/Main.o
 *
 *  Created on: Jan 7, 2014
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

#define FOR(_i,a,b) for(int _i=a;_i<b;_i++)
#define REP(_i,n)    for(int _i=0;_i<n;_i++)
#define debug(x) cout<<#x" "<<x;
#define nl cout<<"\n";
#define tab cout<<"		";
void driver();
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

	int jump(int A[], int n) {
		int steps = 0;

		for (int i = 1, maX = A[0], next = 0; i < n; i++) {
			if (i > next) {
				if (maX < i)
					return -1;
				next = maX;
				steps++;
			}
			maX = max(maX, i + A[i]);
		}
		return steps;
	}
};
void driver() {
	fstream fin("input.txt");
	Solution solver;
}
/*
 input.txt 

 */
int main() {
	driver();
	cout << "\n";
	return 0;
}
