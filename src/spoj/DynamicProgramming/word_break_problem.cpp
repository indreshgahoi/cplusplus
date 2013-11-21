/*
 * word_break_problem.cpp
 *
 *  Created on: Oct 24, 2013
 *      Author: Indresh Gahoi
 */

/*
 * Given an input string and a dictionary of words, find out if the input string can
 * be segmented into a space-separated sequence of dictionary words. See following
 * examples for more details.This is a famous Google interview question, also being
 *  asked by many other companies now a days.
 *
 */

#include<iostream>
#include<string>
#include <cstring>


using namespace std ;
class Dictionary{
	int noOfChildres;
	struct node{
		bool isEnd ;
		struct node* child[256];
	};
	node *tree ;
	void _add(node **tree,const char *word){
		if((*tree)==0){
			*tree = new node();
			(*tree)->isEnd = false ;
			for(int i = 0 ; i < noOfChildres ; ++i){
				(*tree)->child[i]= 0 ;
			}
		}

		if(*word != '\0'){
			_add(&(*tree)->child[*word],word+1);
		}
		else
		{
			(*tree)->isEnd = true ;
		}
	}
	bool _find(node *tree,const char *word) const{
		if(*word=='\0'){
			return tree->isEnd ;
		}
		if(tree->child[*word]!=0){
			return _find(tree->child[*word],word+1);
		}
		else{
			return false ;
		}
	}
public:
	Dictionary(){
		tree = new node();
		tree->isEnd = true ;
		noOfChildres = 256 ;
		for(int i = 0 ; i < noOfChildres ; ++i){
			tree->child[i]= 0 ;
		}
	}

	void addWord(const std::string &str){
		const char *word = str.c_str();
		_add(&this->tree,word);
	}

	bool find(const std::string &str) const{
		const char *word = str.c_str();
		return _find(tree,word);
	}

};


/*
 * Recurrsive word break problem
 */

bool isWordBreakable(Dictionary &dict ,const std::string &word){

	size_t size = word.size();
	//if(dict.find(word)) return 0 ;
	if(0==size)
		return true ;
	for(int i = 1 ; i <=size ; i++ ){

		if(dict.find(word.substr(0,i)) && isWordBreakable(dict,word.substr(i,size-1)))
			return true ;
	}
	return false;

}


/*
 *  Use Dynamic Programming
 */

bool isWordBreakableDp(const Dictionary &dict ,const std::string &word){

	size_t size = word.size();
	if(size==0)
		return true ;

	bool *dp = new bool [size+1];
	memset(dp,0,sizeof(bool)*(size+1));
	for(int len = 1 ; len <= size ; ++len){

		if(!dp[len] && dict.find(word.substr(0,len)))
			dp[len] = true ;
		if(dp[len]){
			if(len==size)
				return true ;
			for( int j = len+1 ; j<= size ; ++j){

				if(!dp[j] && dict.find(word.substr(len,j-len)))
					dp[j] = true ;
				if(j==size && dp[j])
					return true ;
			}
		}
	}
	//delete dp ;
	return false ;
}

void test_0_word_Break(){
	Dictionary dict;
	std::string text[] ={"mobile","samsung","sam","sung","man","mango",
			"icecream","and","go","i","like","ice","cream"};
	for(int i = 0 ; i <sizeof(text)/sizeof(text[0]) ; ++i){
		dict.addWord(text[i]);
	}
	isWordBreakableDp(dict,"ilikesamsung")? std::cout <<"Yes\n": std::cout << "No\n";
	isWordBreakableDp(dict,"iiiiiiiiii")? cout <<"Yes\n": cout << "No\n";
	isWordBreakableDp(dict,"")? cout <<"Yes\n": cout << "No\n";
	isWordBreakableDp(dict,"ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
	isWordBreakableDp(dict,"samsungandmango")? cout <<"Yes\n": cout << "No\n";

	if(isWordBreakableDp(dict,"samsungandmangok"))
	{
		cout <<"Yes\n";
	}
	else
	{
		cout << "No\n";
	}


}




int main(){
	test_0_word_Break();
	return 0 ;

}



























