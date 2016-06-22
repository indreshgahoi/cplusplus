/*
 * heap.cpp
 *
 *  Created on: Mar 2, 2013
 *      Author: indresh
 */

#include <cstdio>
#include<vector>
#include <iostream>
#include <sstream>
using namespace std;
typedef int Integer;

struct heap_node {
	Integer priority;
	heap_node(Integer priority) :
			priority(priority) {
	}

	ostream& operator<<(ostream& out, heap_node &node) {
		out << "[ priority=" << priority << "]" << endl;
		return out;
	}
};

class Heap {

	inline Integer parent(Integer i) {
		return ((i - 1) >> 1);
	}

	inline Integer left(Integer i) {
		return ((i << 1) + 1);
	}
	inline Integer right(Integer i) {
		return ((i << 1) + 2);
	}

	void build() {

		for (int i = (size >> 1); i >= 0; i--) {
			heapIFY(i);
		}
	}
	void swap(heap_node &a, heap_node &b) {
		heap_node temp = a;
		a = b;
		b = temp;
	}

	void heapIFY(Integer i) {
		Integer l = left(i);
		Integer r = right(i);
		Integer up = i;
		if (l < size && compare(data[l], data[i])) {
			up = l;
		}

		if (r < size && compare(data[r], data[up])) {
			up = r;
		}
		if (up != i) {
			swap(data[up], data[i]);
			heapIFY(up);
		}

	}

public:

	int size;
	vector<heap_node> data;
	int (*compare)(heap_node obj1, heap_node obj2);

	Heap(int (*compare)(heap_node, heap_node)) :
			compare(compare) {
		size = 0;
	}
	Heap(vector<heap_node> &data, int (*compare)(heap_node, heap_node)) :
			compare(compare) {
		this->data = data;
		size = data.size();
		build();
	}

	void insert(heap_node a) {
		Integer p = size;
		size++;
		data.push_back(a);
		while (p > 0) {
			if (compare(data[p], data[parent(p)]))
				swap(data[p], data[parent(p)]);
			p = parent(p);
		}

	}

	heap_node get() {
		return data[0];
	}

	void erase() {

		data[0] = data[size - 1];
		size--;
		heapIFY(0);

	}

};

int MaxCompare(heap_node a, heap_node b) {
	if (a.priority > b.priority)
		return 1;
	else
		return 0;
}

int MinCompare(heap_node a, heap_node b) {
	if (a.priority < b.priority)
		return 1;
	else
		return 0;
}

int main() {
	vector<heap_node> vec;
	vec.push_back(heap_node(7));
	vec.push_back(heap_node(8));
	vec.push_back(heap_node(4));
	vec.push_back(heap_node(3));
	vec.push_back(heap_node(6));
	vec.push_back(heap_node(9));
	vec.push_back(heap_node(10));
	Heap maxHeap(vec, &MinCompare);
	maxHeap.insert(heap_node(12));
	maxHeap.insert(heap_node(1));
	cout << " value= " << maxHeap.get().priority << " ------" << endl;
	printf("hello");
	return 0;
}

