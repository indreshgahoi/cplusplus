/*
 * chefOfTheYear.cpp
 *
 *  Created on: Jan 4, 2013
 *      Author: indresh
 */
#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>
#include <string.h>
#define MAX_INT 1000000
#define FOR(i,s,e) for(int i=s;i<=e;i++)
#define REP(i,n)   for(int i=0;i<n;i++)
#define si(i)      int i; scanf("%d",&i);
#define gi(i)       scanf("%d",&i);
#define tr(c,i)    for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define is istringstream
#define os ostringstream
using namespace std;

int main(){
#ifndef ON_LINE_JUDGE
    //freopen("input.txt","rt",stdin);
   // freopen("output.txt","wt",stdout);
  #endif
	si(n)si(m)
	map<string,string> nc;
	map<string,int>name;
	map<string,int>country;
	string s1,s2;
	FOR(i,1,n)
	{
		cin>>s1>>s2;
		nc[s1]=s2;
		name[s1]=0;
		country[s2]=0;
	}
	FOR(i,1,m)
	{
			cin>>s1;
            name[s1]=name[s1]+1;
			country[nc[s1]]=country[nc[s1]]+1;
	}
     vector<string> ansname;
     vector<string> anscountryname;
     int maX=-1;
     tr(name,it){
    	 if(maX<(it->second)){
    		maX=it->second;
    	}
     }
     tr(name,it){
         	 if(maX==(it->second)){
         		ansname.push_back(it->first);
         	}
          }
     maX=-1;
     tr(country,it){
        	 if(maX<(it->second)){
        		maX=it->second;
        	}
         }
         tr(country,it){
             	 if(maX==(it->second)){
             		anscountryname.push_back(it->first);
             	}
              }

          s1=(*anscountryname.begin());
          tr(anscountryname,it)
               if((*it)<s1)
                  s1=(*it);
          cout<<s1<<endl;

          s1=(*ansname.begin());
          tr(ansname,it)
             if((*it)<s1)
        	    s1=(*it);
          cout<<s1<<endl;
         return 0;
}

