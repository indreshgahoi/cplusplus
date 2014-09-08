/*
 * LetterCombination.cpp
 *
 *  Created on: Jun 26, 2014
 *      Author: Indresh Gahoi
 */


#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std ;


template<class T>
ostream& operator<<(ostream &out,const vector<T>& V){
	out<<"[";
	for(typename vector<T>::const_iterator it=V.begin();it!=V.end();it++){
	 out<<" "<<*it;
	}
	out<<"]"<<endl;
	return out;
}

class Solution{
public :


		vector<vector<char> > map ;
	public:
		vector<string> sol ;
		Solution(){
			map = *new vector<vector<char> >(8);
			map[0].push_back('a');map[0].push_back('b');map[0].push_back('c');
			map[1].push_back('d');map[1].push_back('e');map[1].push_back('f');
			map[2].push_back('g');map[2].push_back('h');map[2].push_back('i');
			map[3].push_back('j');map[3].push_back('k');map[3].push_back('l');
			map[4].push_back('m');map[4].push_back('n');map[4].push_back('o');
			map[5].push_back('p');map[5].push_back('q');map[5].push_back('r');map[5].push_back('s');
			map[6].push_back('t');map[6].push_back('u');map[6].push_back('v');
			map[7].push_back('w');map[7].push_back('x');map[7].push_back('y');map[7].push_back('z');

		}

	void dfs(string &digits, int depth, vector<char> & path) {
		if (depth == digits.size()) {

			string str;
			for (int i = 0; i < path.size(); ++i) {
				str.push_back(path[i]);
			}
			sol.push_back(str);
			return;
		}
		vector<char> &v = map[digits[depth] - '0' - 2];
		for (int i = 0; i < v.size(); ++i) {
			path.push_back(v[i]);
			dfs(digits, depth + 1, path);
			path.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) {
		sol.clear();

		if (digits.size() > 0) {
			vector<char> path;
			dfs(digits, 0, path);
		} else {
			sol.push_back("");
		}
		return sol;
	}
};



int main(){
 Solution sol ;

 cout<<sol.letterCombinations("23");
 return 0 ;

}
