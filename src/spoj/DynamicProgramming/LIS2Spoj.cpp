/*
 * LIS2Spoj.cpp
 * run command
 g++ /Algorithm/src/spoj/DynamicProgramming/LIS2Spoj.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 1, 2013
 *      Author: Indresh Gahoi
 */


#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<set>
using namespace std ;

struct Pair{
 int x ;
 int y ;
 int operator < (const Pair &p){
	  if(x == p.x) return y < p.y ;
      return x < p.x ;
  }
};

vector<Pair> input ;
set<Pair> M ;


void printV(){
  cout<<" [" ;

  for(set<int>::iterator it= M.begin() ; it != M !=end() ; ++it ){
    cout<<"("<<input[*it].x<<","<<input[*it].y<<") ";
  }
  cout<<" ]\n" ;
}

int check(int k , int xidx){
	Pair key = input[k];
	//Pair x = M.()
}

int myUpperBound(int l ,int r,int key){
	int mid ;
	while(l<r){
		mid = l + (r-l)/2 ;
		if(check(key,mid)){
            r = mid ;
		}
		else{
			l = mid + 1 ;
		}
	}
	return l ;
}

int LIS2spoj(vector<Pair> &v){
	int l,r,mid;
    vector<Pair>::iterator it ;
    set<Pair>::iterator jt;
	sort(v.begin(),v.end(),cmp);
	it = v.begin();
    M.insert(*it);
    Pair p ;
    p.y=-1e9;
    for(; it != v.end(); ++it){
        p.x = it->x ;
       jt = lower_bound(M.begin(),M.end(),p);

    }

  return M.size();
}

int main(){
   freopen("input.txt","r",stdin);
   int n ,x,y,iter;
   Pair p;
   scanf("%d",&n);
   for( iter = 0 ; iter < n ; ++iter){
      scanf("%d%d",&p.x,&p.y);
      input.push_back(p);
   }
   printf("%d\n",LIS2spoj(input));
   return 0 ;
}

