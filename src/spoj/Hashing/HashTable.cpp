/*
 * HashTable.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/spoj/Hashing/HashTable.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 27, 2013
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
#include<list>

using namespace std;

#define FOR(_i,a,b) for(int _i=a;_i<b;_i++)
#define REP(_i,n)    for(int _i=0;_i<n;_i++)
#define debug(x) cout<<#x" "<<x;
#define nl cout<<"\n";
#define tab cout<<"		";
void driver();
void printArray(int A[],size_t size){
	printf("values= [");
   for(int i=0;i<size-1;i++)
	   printf("%d ,",A[i]);
   printf("%d]\n",A[size-1]);
}
template<class T>
ostream& operator<<(ostream &out,const vector<T>& V){
	out<<"[";
	for(typename vector<T>::const_iterator it=V.begin();it!=V.end();it++){
	 out<<" "<<*it;
	}
	out<<"]"<<endl;
	return out;
}
void getInput(vector<int> &v)
{
#define ARRAYSIZE(A) sizeof(A)/sizeof(A[0])
	int arr[] = {-1,-1,-1,1,1};
	int size = ARRAYSIZE(arr) ;
	for(int iter = 0 ; iter < size ; ++iter)
	{
		v.push_back(arr[iter]);
	}
}

namespace hashing {

template <typename _Tp>
struct hash {
	template <typename _Tp>
	unsigned int hash(const _Tp &k) const
	{
		return &k ;
	}
};


}  // namespace name

template <typename _Key , typename _Value, typename _Hash = hashing::hash<_Key> >
class HashTable
{
	struct entry
	{
		_Key key ;
		_Value value ;
		entry(const _Key &key_, const _Value &value_):key(key_),value(value_){}
	};

  _Hash  hash_fn;
  list<entry*>& find_bucket(_Key key)
	{

	  size_t bucket_no = hash_value(key) & buckets.size() ;
	  return buckets[bucket_no] ;
	}

public :
  typedef HashTable::entry MapEntry ;

  void set(_Key key , _Value value) {
		list<HashTable::entry*> &bucket = find_bucket(key) ;
		HashTable::entry *old_entry = find_entry(bucket, key);
	}
 private :

	 HashTable::entry* find_entry(list<MapEntry*> &bucket , _Key &key)
	  {
	           list<MapEntry*>::const_iterator it = bucket.begin() ;
	           for(; it != bucket.end() ; ++it)
	           {
	        	   MapEntry entry = *(*it) ;
	        	   if(!(entry.key < key) && !(key < entry.key) )
	        		   return (*it) ;
	           }
	           return 0 ;
	  }
	size_t entry_count ;
	hash_fn<_Key>  hash_value ;
	vector<list<MapEntry*> > buckets ;
};



class Solution
{
	public :
   
};

void driver()
{
  fstream fin("input.txt");	
  Solution solver ;
}
/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
