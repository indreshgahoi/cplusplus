/*
 * MedianStream.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/InterviewPreparation/Heap/MedianStream.cpp -o /usr/build/Main.o
 *
 *  Created on: Feb 3, 2014
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

template<typename T, typename _Compare = less<T> >
class PriOrityQueue {
private:
	vector<T> list;
	_Compare cmp;

	void heapIfy(size_t location) {
		size_t left = (location << 1) + 1;
		size_t right = left + 1;
		size_t index = location;
		if (left < list.size() && cmp(list[left], list[index])) {
			index = left;
		}
		if (right < list.size() && cmp(list[right], list[index])) {
			index = right;
		}
		if (index != location) {
			swap(list[index], list[location]);
			heapIfy(index);
		}

	}
	void build() {
		int i = list.size() - 1;
		while (i >= 0) {
			heapIfy(i);
			i--;
		}
	}

public:
	PriOrityQueue(_Compare cmp_) :
			cmp(cmp_) {
	}
	PriOrityQueue(vector<T> &v, _Compare cmp_) :
			list(v), cmp(cmp_) {
		build();
	}
	void push(T item);
	void pop();
	void replace(T item);
	T& top();
	bool isEmpty();
	size_t size();
};

template<typename T, typename _Compare>
void PriOrityQueue<T, _Compare>::push(T item) {
	size_t now = list.size();
	list.push_back(item);
	while (now > 0 && cmp(item, list[(now - 1) >> 1])) {
		list[now] = list[(now - 1) >> 1];
		now = (now - 1) >> 1;
	}
	list[now] = item;
}

template<typename T, typename _Compare>
void PriOrityQueue<T, _Compare>::pop() {
	if (list.size()) {
		list[0] = list[list.size() - 1];
		list.pop_back();
		heapIfy(0);
	}
}

template<typename T, typename _Compare>
T& PriOrityQueue<T, _Compare>::top() {
	if (list.size())
		return list[0];
	else {
		// handle error
	}
}

template<typename T, typename _Compare>
void PriOrityQueue<T, _Compare>::replace(T item) {
	if (list.size()) {
		list[0] = item;
		heapIfy(0);
	}
}
template<typename T, typename _Compare>
bool PriOrityQueue<T, _Compare>::isEmpty() {
	return list.size() == 0;
}
template<typename T, typename _Compare>
size_t PriOrityQueue<T, _Compare>::size() {
	return list.size();
}

class Solution {
public:

	PriOrityQueue<int> maxPQ;
	PriOrityQueue<int, greater<int>> minPQ;

	double getMedian() {
		if (maxPQ.size() == minPQ) {
			return (minPQ.top() + maxPQ.top()) / 2.0;
		} else
			return maxPQ.top();
	}

	/*
	 *          6
	 *   1 2 3     4 5  7
	 *
	 */

	void add(int x) {
		if (maxPQ.size() == minPQ.size()) {
			if (!minPQ.isEmpty() && x > minPQ.top()) {
				maxPQ.push(minPQ.top());
				minPQ.pop();
				minPQ.push(x);
			} else
				maxPQ.push(x);
		} else {
			if (x < maxPQ.top()) {
				minPQ.push(maxPQ.top());
				maxPQ.pop();
				maxPQ.push(x);
			}

		}
	}

};
void driver() {
	fstream fin("input.txt");
	int x;

	Solution solver;
	while (fin >> x) {
		solver.add(x);
		cout << " Median = " << solver.getMedian();
	}
}
/*
 input.txt 

 */
int main() {
	driver();
	cout << "\n";
	return 0;
}
