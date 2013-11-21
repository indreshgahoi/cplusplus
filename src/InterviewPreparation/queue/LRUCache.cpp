/*
 * LRUCache.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/queue/LRUCache.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 18, 2013
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<climits>
#include<string>
#include <cstring>
#include<pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include<time.h>

using namespace std;


class Cache{

typedef struct cache_node
{

	size_t ID ;
	cache_node *next;
	cache_node *pre ;

      cache_node(size_t pageId):ID(pageId),next(NULL),pre(NULL){}
};

public:
 Cache(size_t capacity):_capacity(capacity)
 {
	 size=0;
 }


private :
size_t _cacpcity;
size_t size ;

};
int main(){
	driver();
	cout<<"\n";
	return 0;
}
