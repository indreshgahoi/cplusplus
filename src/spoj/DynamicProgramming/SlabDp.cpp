/*
 * SlabDp.cpp
 *
 *  Created on: Oct 30, 2013
 *      Author: Indresh Gahoi
 */

/*
 *  You are given many slabs each with a length and a breadth. A slab i can be put on slab j if both
 *  dimensions of i are less than that of j. In this similar manner, you can keep on putting slabs on each other.
 *   Find the maximum stack possible which you can create out of the given slabs
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;


template < class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
    os << "[";
    for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}




typedef struct slab{
	int length ;
	int width ;

}slab;

std::ostream& operator << (std::ostream& os , const slab &s ){
	os <<"("<<s.length<<","<<s.width<<") ";
	return os;
}


int compare(const slab &a ,const slab &b){
	if(a.length > b.length) return 1;
	else if(a.length == b.length && a.width > b.width) return 1;
	else return 0;
}


int MaximumPossibleStack(vector<slab> &V){

   int *res ,maxWidth = -9999;
   res = new int[V.size] ;
   sort(V.begin(),V.end(),compare);
   cout<<V<<std::endl;
    int i , j ;
    for(vector<slab>::iterator it = V.begin() ,i=0 ; it != V.end() ; ++i,++it)
    {
      res[i] = 0 ; j = 0;
      for(vector<slab>::iterator jt = V.begin() ; jt < it ;++j, ++jt){
           if(it->width > jt->width && res[j]+it->width > res[i]){
              res[i] = res[j] + it->width ;
           }
      }
    }
    for(int i = 0 ; i < V.size() ; ++i){
          if(maxWidth < res[i]){
        	  maxWidth = res [i] ;
          }
    }
    return maxWidth ;
}

