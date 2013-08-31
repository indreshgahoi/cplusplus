/*
 * Pair.cpp
 *
 *  Created on: Feb 17, 2013
 *      Author: indresh
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll Binary_search(vector<ll> v,ll elm,ll l, ll r){

    while(l<=r){

    ll m=(l+r)/2;
        if(v[m]==elm){

        	return m;

        }

     if(v[m]<elm)
         l=m+1;
     else
         r=m-1;


    }
    return -1;
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    ll N,K;
    cin>>N>>K;
    vector<ll> p;
    ll n;
    for(int i=0;i<N;i++)
    {
        cin>>n;
        p.push_back(n);
    }
    sort(p.begin(),p.end());
    ll count =0;
    ll diff;
    for(int i=0;i<N;i++){

        if(K>p[i])
            diff=K-p[i];
        else
            diff=p[i]-K;
        ll g=Binary_search(p,diff,0,N-1);
       if(g!=-1 && g!=i )
           count++;

    }
     cout<<count;


    return 0;
}



