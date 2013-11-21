/*
 * ReplaceArrayWithRightCloset.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std ;

template <class T>
std::ostream& operator<< (std::ostream &os ,const vector<T> &V) {
       os<<"[";
       for(typename vector<T>::const_iterator it=V.begin() ; it != V.end() ; ++it)
       {
          os<<" "<< *it ;
       }
       os<<"]\n";
  return os ;
}
vector<int> ReplaceArrayWithRightClosetMaxNumver(vector<int> &V){
   vector<int> res(V.size(),-1);
   int k = V.size()-1;
   stack<int> S;
   S.push(V[V.size()-1]);
   vector<int>::reverse_iterator it = V.rbegin();
   it++;
   k--;
   for(;it != V.rend() ; ++it,--k){

	   while(!S.empty() && S.top()< *it)
		   S.pop();
	   if(!S.empty()){
         res[k] = S.top();
	   }
	   S.push(*it);

  }
   return res ;
}
void test0(){
	vector<int> v ;
	v.push_back(13);
	v.push_back(7);
	v.push_back(6);
	v.push_back(11);
	cout<<"Input ->\n        "<<v;
	cout<<"Output->\n        "<<ReplaceArrayWithRightClosetMaxNumver(v);
}

void test1(){
	vector<int> v ;
	v.push_back(4);
	v.push_back(5);
	v.push_back(2);
	v.push_back(25);
	cout<<"Input ->\n        "<<v;
	cout<<"Output->\n        "<<ReplaceArrayWithRightClosetMaxNumver(v);
}

int main(){
	test0();
	test1();
	return 0 ;
}


