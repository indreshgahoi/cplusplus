/*
 * FourSum.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/Array/FourSum.cpp -o /usr/build/Main.o
 *
 *  Created on: Jan 20, 2014
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

// O((n^4)
class Solution {
public:

	void FourSum(int A[], int n, int targetSum) {

		for (int i = 0; i < n - 3; ++i) {
			for (int j = i + 1; j < n - 2; ++j) {
				for (int k = j + 1; k < n - 1; ++k) {
					for (int l = k + 1; i < n; ++l) {
						if (A[i] + A[j] + A[k] + A[l] == targetSum) {
							printf("%d %d %d %d \n", i, j, k, l);
						}
					}
				}
			}
		}

	}

};

// o(n^3) solution

class Solution1 {

public:

	void FourSum(int A[], int n, int targetSum) {
		sort(A, A + n);

		for (int i = 0; i < n - 3; ++i) {
			for (int j = i + 1; j < n - 2; ++j) {
				int l = j + 1;
				int r = n - 1;
				while (l < r) {
					int t = (A[i] + A[j] + A[l] + A[r]);
					if (targetSum == t) {
						printf("%d %d %d %d \n", i, j, l, r);
						l++;
						r--;
					} else if (t < targetSum)
						l++;
					else
						r--;
				}
			}
		}
	}

};

// O(n^2logn) method

struct Pair {
	int f;
	int s;
	int sum;
	int operator<(const Pair &other) const {

		return sum <= other.sum;
	}
};

class Solution2 {
public:
	vector<vector<int> > result;
	void FourSum(int A[], int n, int targetSum) {
		sort(A, A + n);
	vector<int> solSet(4);

		for (int i = 0; i < n - 3; ++i) {
			 if(i > 0 && A[i-1]==A[i]) continue ;
			for (int j = i + 1; j < n - 2; ++j) {
				 if(j > i+1 && A[j-1]==A[j]) continue ;
				int l = j + 1;
				int r = n - 1;
				while (l < r) {
					int t = (A[i] + A[j] + A[l] + A[r]);
					if(l > j+1 && A[l-1]==A[l]) {
						l++ ; continue ;
					}
					if(r < n-1 && A[r]==A[r+1]) {
						r-- ;
						continue ;
					}
					if (targetSum == t) {
						//printf("%d %d %d %d \n", i, j, l, r);
						solSet[0] = A[i];
						solSet[1] = A[j];
						solSet[2] = A[l];
						solSet[3] = A[r];
						sort(solSet.begin(),solSet.end());
						result.push_back(solSet);
						l++;
						r--;
					} else if (t < targetSum)
						l++;
					else
						r--;
				}
			}
		}
	}

	vector<vector<int> > fourSum(vector<int> &num, int target) {
		result.clear();
		FourSum(&num[0], num.size(), target);
		return result;
	}

};
void driver() {
	fstream fin("input.txt");
	vector<int> input;
	input.push_back(2);
	input.push_back(1);
	input.push_back(0);
	input.push_back(-1);
	int target = 2;

	Solution2 solver;
	cout << solver.fourSum(input, target);
}
/*
 input.txt 

 */
int main() {
	driver();
	cout << "\n";
	return 0;
}
