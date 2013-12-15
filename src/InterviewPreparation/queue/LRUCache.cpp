/*
 * LRUCache.cpp
 * run command
 * g++ /Algorithm/src/InterviewPreparation/queue/LRUCache.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 18, 2013
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<fstream>
#include<map>
#include<set>
#include<string>
#include<cstring>


#define debug(x) cout<<#x" "<<x<<"	";
#define nl cout<<"\n";
#define tab cout<<"		";
#define trv(it,C)    for(__typeof__ ((C).begin()) it = (C).begin() ;(C).end()!= it ;++it)

using namespace std ;

template <typename T>
struct Qnode
{
    T key ;
    Qnode *next ;
    Qnode *pre ;
    Qnode():next(0),pre(0)
    {

    }
    Qnode(T &k):key(k),next(0),pre(0){

    }
};
template <typename T>
ostream& operator<<(ostream &out , Qnode<T> *n)
{
	out<<n->key;;
	return out ;
}


template <typename T>
class Queue
{
private :
    size_t _size ;
    Qnode<T> first;
    Qnode<T> last ;

public:
    Queue();
    bool isEmpty() ;
    Qnode<T>* front();
    const Qnode<T>* end() ;
     Qnode<T>* begin();
    size_t size() ;
    void moveFront(Qnode<T> *t);
    void moveBack(Qnode<T> *t) ;
    bool deattach(Qnode<T> *t) ;
    Qnode<T>* push(T key) ;
    void pop() ;
};

template <typename T>
Queue<T>::Queue()
{
    _size = 0 ;
    first.pre = 0 ;
    first.next = &last ;
    last.pre = &first ;
    first.next = 0 ;
}
template <typename T>
const Qnode<T>* Queue<T>::end()
{
    return  &last ;
}
template <typename T>
 Qnode<T>* Queue<T>::begin()
{
    return  first.next ;
}

template <typename T>
Qnode<T>* Queue<T>::front()
{
    return first.next ;
}
template <typename T>
bool Queue<T>::isEmpty()
{
    return first.next==&last ;
}
template <typename T>
size_t Queue<T>::size()
{
    return _size ;
}
template <typename T>
Qnode<T>* Queue<T>::push(T key)
{

    Qnode<T> *t = new Qnode<T>(key) ;
    last.pre->next = t ;
    t->pre = last.pre ;
    t->next = &last ;
    last.pre = t ;
    _size++ ;
    return t ;
}

template <typename T>
void Queue<T>::pop()
{
    if(first.next==(&last))
    {

    }
    else
    {
        Qnode<T> *t = first.next ;
        first.next = t->next ;
        t->next->pre = &first ;
        _size-- ;
        delete t ;
    }
}

template <typename T>
void Queue<T>::moveFront(Qnode<T> *t)
{
   if(_size>1)
   {
	deattach(t);
    last.pre->next = t ;
    t->pre = last.pre ;
    t->next = &last ;
    last.pre = t ;
    _size++ ;
   }
}
template <typename T>
void Queue<T>::moveBack(Qnode<T> *t)
{
   if(_size>1)
   {
	deattach(t);
	t->next = first.next ;
	first.next->pre = t ;
    t->pre = &first ;
    first.next = t ;
    _size++ ;
   }
}

template <typename T>
bool Queue<T>::deattach(Qnode<T> *t)
{
    if(first.next != (&last))
    {
        t->pre->next = t->next ;
        t->next->pre = t->pre ;
        _size-- ;
    }
    return true ;
}

template <typename T>
ostream& operator<<(ostream &out ,Queue<T> &Q)
{
	Qnode<T> *curr = Q.begin() ;
	cout<<"\n";
	while(curr != Q.end())
	{
		out<<curr;
		curr = curr->next ;
	}
	return out ;
}

struct info
{
    int key ;
    int value ;
    int operator < (const info &o)
    {
        if(key < o.key) return 1 ;
        if(key > o.key) return -1 ;
        return 0 ;
    }

};

ostream& operator<<(ostream &out ,info &i)
{
	out<<"key = "<<i.key<<" value = "<<i.value<<"\n";
	return out ;
}
class LRUCache{
    private :
    int capacity ;
    Queue<info> Q ;
    map<int,Qnode<info>*> H ;
    public:
    friend ostream& operator<<(ostream &out ,LRUCache &cache) ;
    LRUCache(int cap) {
        capacity = cap ;
    }

    int get(int key) {
        map<int,Qnode<info>*>::iterator it = H.find(key) ;
        if(it != H.end())
        {
            Qnode<info> *t = it->second ;
            Q.moveFront(t);
            return t->key.value ;
        }
        return - 1;
    }
    /*
     if Already in cache ;
     update value and move to front
     else
     {
     if cache is full pop front and remove from hash
     then push other wise direct push
     push to queue i
     }
     */

    void set(int key, int value) {
        map<int,Qnode<info>*>::iterator it = H.find(key) ;
        Qnode<info> *t ;
        if(it != H.end())
        {
            t = it->second  ;
            t->key.value = value ;
            Q.moveFront(t);
        }
        else
        {
            if(Q.size()==capacity)
            {
                 t = Q.front() ;
                 it = H.find(t->key.key) ;
                 H.erase(H.find(t->key.key));
                 Q.pop();
            }
            /*
              it already go in front
             */
            info i ;
            i.key = key ;
            i.value = value ;
            H[key] =Q.push(i); ;
        }
    }
};

ostream& operator<<(ostream &out ,LRUCache &cache)
{
	out<<"cache===>"<<cache.Q;
	return out ;
}

void driver()
{
  fstream fin("input.txt");
  int c;
  fin>>c ;
  LRUCache cache(c) ;
  char x ;
  int key , value ;
  while(fin>>x)
  {
	  switch(x)
	  {
	  case 's' :
		  fin>>key>>value ;
          cache.set(key,value);
		  break ;
	  case 'g' :
		  fin>>key;
		  value = cache.get(key);
		  cout<<"get "; cout<<"key = "<<key<<" value="<<value<<" \n";
		  break ;
	  }
	  cout<<cache<<"\n";
  }
}
/*
 input.txt


1
s 2 1
g 2
s 3 2
g 2
g 3

3
s 1 1
s 2 2
s 3 3
s 4 4
g 4
g 3
g 2
g 1
s 5 5
g 1
g 2
g 3
g 4
g 5

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}



