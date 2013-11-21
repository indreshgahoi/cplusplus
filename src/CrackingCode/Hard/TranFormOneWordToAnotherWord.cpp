/*
 * TranFormOneWordToAnotherWord.cpp
 * run command
 * g++ /Algorithm/src/CrackingCode/Hard/TranFormOneWordToAnotherWord.cpp -o /usr/build/Main.o
 *
 *  Created on: Nov 17, 2013
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<climits>
#include<string>
#include <queue>
#include <cstring>
#include<list>
#include<set>
#include<pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include<time.h>
#include <map>

using namespace std;

#define FOR(_i,a,b) for(int _i=a;_i<b;_i++)
#define REP(_i,n)    for(int _i=0;_i<n;_i++)

typedef int Integer ;

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

template<class T>
ostream& operator<<(ostream &out,const list<T>& V){
	out<<"[";
	for(typename list<T>::const_iterator it=V.begin();it!=V.end();it++){
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
/*
Link :-  http://tianrunhe.wordpress.com/2012/06/10/transform-one-word-into-another-by-changing-only-one-letter-at-a-time/
Question :-
	Given two words of equal length that are in a dictionary, write a method to transform one word into
	another word by changing only one letter at a time. The new word you get in each step must be in the dictionary.
EXAMPLE
Input: DAMP, LIKE
Output: DAMP -> LAMP -> LIMP -> LIME -> LIKE


 */

/*
 *  BFS Approach :-
 *
 *  Design DataStructure :-
 *  We need a Queue
 *  map set to visited state
 *  We nedd A dictionary to look upword
 *  LinkList For store Solution
 *  map to store parent ;
 *
 */



void generateAllPossible(string &str,list<string> &list,set<string> &dict)
{
	for(int i = 0 ; i < str.size() ; ++i)
	{
		for(char ch='A' ; ch <='Z' ; ++ch)
		{
			string cur = str.substr(0,i)+ch+str.substr(i+1);
			if(dict.find(cur)!=dict.end())
			{
				list.push_back(cur);
			}
		}
	}
}



void convert(string &word1 ,string &word2 ,set<string> &dict)
{
	queue<string> Q ;
	list<string> result ;
	map<string,bool> visited ;
	map<string,string> route;

	Q.push(word1);
	visited[word1] = true ;
	while(!Q.empty())
	{
		string curr = Q.front();
		Q.pop() ;

		if(word2==curr)
		{
			string &parent = curr;

			while(parent!="")
			{
				result.push_front(parent);
				parent = route[parent];
			}
		}
		else
		{
			list<string> neighbourList ;
			generateAllPossible(curr,neighbourList,dict);
			for(list<string>::iterator it=neighbourList.begin() ; it!= neighbourList.end() ; ++it)
			{
				if(!visited[*it])
				{
					visited[*it] = true ;
					Q.push(*it);
					route[*it]=curr;
				}
			}

		}
	}

	cout<<result;

	//	for(list<string>::iterator it=result.begin() ; it!= result.end() ; ++it)
	//	{
	//     cout<<"[ "<<*it<<" ]-->";
	//	}
	//	cout<<"NULL"<<"\n";
}


void prepareDictionary(set<string> &dict)
{
	dict.insert("LAMP");
	dict.insert("LIMP");
	dict.insert("DAMP");
	dict.insert("TAKE");
	dict.insert("SINK");
	dict.insert("DUCK");
	dict.insert("DABP");
	dict.insert("LINK");
	dict.insert("LIME");
	dict.insert("LIKE");
}

void driver()
{
	set<string> dict;
	string word1("DAMP");
	string word2("LIKE");
	prepareDictionary(dict);
	convert(word1,word2,dict);
}
/*
 input.txt 

DAMP, LIKE
Output: DAMP -> LAMP -> LIMP -> LIME -> LIKE
 */
int main(){
	driver();
	cout<<"\n";
	return 0;
}
