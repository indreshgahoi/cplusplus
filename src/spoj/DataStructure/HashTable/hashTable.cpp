/*
 * hashTable.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/spoj/DataStructure/HashTable/hashTable.cpp -o /usr/build/Main.o
 *
 *  Created on: Jan 31, 2014
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

#define MAXSIZE 1000
#define MAXKEY  100

typedef int Key ;
typedef int Value ;

int T[MAXSIZE] ;
Key keys[MAXKEY+1] ;
Value values[MAXKEY+1] ;
size_t total = 0;

// core man - 4.1 ex
// HashTable With Huge Table and with initializationTime is Constant


size_t hash(Key key)
{
	return key ;
}


Value search(Key key)
{
	size_t k = hash(key) ;

	if(T[k]>=1 && T[k]<=total && keys[T[k]]==key)
	{
		return Value[T[k]] ;
	}
	return -1 ;
}

bool insert(Key key , Value val)
{
	size_t k = hash(key) ;
	total++;
	T[k]=total ;
	keys[T[k]]= key ;
	values[T[k]] = val ;
	return 1 ;
}

bool erase()















