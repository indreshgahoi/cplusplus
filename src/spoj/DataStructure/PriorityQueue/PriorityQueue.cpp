/*
 * PriorityQueue.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/spoj/DataStructure/PriorityQueue/PriorityQueue.cpp -o /usr/build/Main.o
 *
 *  Created on: Feb 2, 2014
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

template <typename T,typename _Compare >
class PriOrityQueue
{
   private:
	vector<T> list ;
	_Compare cmp ;

	void heapIfy(size_t location)
	{
		size_t left = (location<<1)+1;
		size_t right = left+1;
		size_t index = location ;
		if(left<list.size() && cmp(list[left],list[index]))
		{
			index = left ;
		}
		if(right<list.size() && cmp(list[right],list[index]))
		{
			index = right ;
		}
		if(index!=location)
		{
			swap(list[index],list[location]);
			heapIfy(index);
		}

	}
	void build()
	{
		int i = list.size()-1 ;
		while(i>=0)
		{
			heapIfy(i);
			i--;
		}
	}


   public :
	PriOrityQueue(_Compare cmp_):cmp(cmp_){}
	PriOrityQueue(vector<T> &v,_Compare cmp_):list(v),cmp(cmp_){build();}
    void push(T item);
    void pop();
    void replace(T item);
    T& top();
    bool isEmpty();
    size_t size();
};

template<typename T,typename _Compare>
void PriOrityQueue<T,_Compare>::push(T item)
{
     size_t now = list.size();
     list.push_back(item);
     while(now>0 && cmp(item,list[(now-1)>>1]))
     {
    	 list[now] = list[(now-1)>>1];
    	 now = (now-1)>>1;
     }
     list[now] = item ;
}

template<typename T,typename _Compare>
void PriOrityQueue<T,_Compare>::pop()
{
	if(list.size())
	{
      list[0] = list[list.size()-1];
      list.pop_back();
      heapIfy(0);
	}
}

template<typename T,typename _Compare>
T& PriOrityQueue<T,_Compare>::top()
{
	if(list.size())
		return list[0] ;
	else
	{
		// handle error
	}
}

template<typename T,typename _Compare>
void PriOrityQueue<T,_Compare>::replace(T item)
{
	if(list.size())
	{
		list[0] = item ;
		heapIfy(0);
	}
}
template<typename T,typename _Compare>
bool PriOrityQueue<T,_Compare>::isEmpty()
{
	return list.size()==0;
}
template<typename T,typename _Compare>
size_t PriOrityQueue<T,_Compare>::size()
{
	return list.size() ;
}

struct ListNode
{
	int val ;
	ListNode *next ;
	ListNode():next(0),val(-1){};
	ListNode(int x):next(0),val(x){};
};

struct Comparator
{
	int operator()(ListNode *l , ListNode *r)
	{
		return l->val < r->val ;
	}
};


class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {

    	ListNode *head, *tail ;
    	 head = tail = 0 ;
    	 size_t k = 0;
    	 for(size_t t = 0  ; t< lists.size();++t)
    	 {
    		 if(lists[t])
    		 {
    			 lists[k]=lists[t];
    			 k++ ;
    		 }
    	 }
    	 lists.resize(k);
         PriOrityQueue<ListNode*,Comparator> PQ(lists,Comparator());
         while(!PQ.isEmpty())
         {
        	 ListNode *min = PQ.top() ;
        	 if(!head)
        	 {
        		 head = min ;
        	 }
        	 else
        		tail->next = min ;
        	 if(min->next)
        	 {
        		 PQ.replace(min->next) ;
        		 min->next = 0;
        	 }
        	 else
        		 PQ.pop();
        	 tail = min ;
         }
         if(tail)
        	 tail->next = 0 ;
         return head ;
    }
};
void driver()
{
   fstream fin("input.txt");
   vector<ListNode*> lists;
   ListNode *head = new ListNode(1);
   head->next = new ListNode(4) ;
   head->next->next = new ListNode(5) ;
   lists.push_back(head);

   ListNode *head1 = new ListNode(10);
   head1->next = new ListNode(15) ;
   head1->next->next = new ListNode(19) ;
   lists.push_back(head1);

   ListNode *head2 = new ListNode(12);
   head2->next = new ListNode(23) ;
   head2->next->next = new ListNode(26) ;
   lists.push_back(head2);

   ListNode *head3 = new ListNode(11);
   head3->next = new ListNode(13) ;
   head3->next->next = new ListNode(16) ;
   lists.push_back(head3);


   Solution solver ;
   ListNode *result = solver.mergeKLists(lists);
   while(result)
   {
	   printf("%d ",result->val);
	   result = result->next ;
   }
}
/*
 input.txt 

*/
int main(){
	driver();
	cout<<"\n";
	return 0;
}
