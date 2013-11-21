/*
 * subsets.cpp
 *
 *  Created on: Mar 24, 2013
 *      Author: indresh
 */


#include<iostream>
#include<cstdio>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;
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
vector<vector<int> > res;
int len=0;
void subsetrec(const vector<int> &S,vector<int> &path,int depth){
	if(depth>=len) return;


	subsetrec(S,path,depth+1); // no choose
	path.push_back(S[depth]);
	res.push_back(path);
	subsetrec(S,path,depth+1); // choose S[depth] element
	path.pop_back();


}


vector<vector<int> > subsets(vector<int> &S) {
	res.clear();
	len=S.size();
	vector<int> path;
	sort(S.begin(),S.end());
	res.push_back(path);
	subsetrec(S,path,0);
	return res;

}

int main(){
	vector<int> S;
	S.push_back(1);
	S.push_back(2);
	cout<<"subsets"<<subsets(S);

	return 0;
}


