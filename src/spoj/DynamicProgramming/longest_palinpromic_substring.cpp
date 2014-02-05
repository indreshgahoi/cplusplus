/*
 * longest_palinpromic_substring.cpp
 *
 *  Created on: Oct 23, 2013
 *      Author: Indresh Gahoi
 */



#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include <cstdio>
using namespace std;

pair<int,int> longest_palindromic_substring(string &seq){

	int size=seq.size();
	int maxlen=1 , start=0;
	bool **table;

	table= new bool*[size];

	for(int i=0;i<size;++i){
		table[i]=new bool[size];
	}
	// tabel initialization
	for(int i=0;i<size;++i){
		table[i][i]=true;
		if(i!=size && seq[i]==seq[i+1]){
			table[i][i+1]=true;
			maxlen=2;
			start=i;
		}
	}

	// filling tabel
	for(int l=3 ; l<=size;++l){
		for(int s=0;s<size-l+1;++s){
			int e=s+l-1;
			if(table[s+1][e-1] && seq[s]==seq[e]){
				table[s][e]=true;
				if(l>maxlen){
					maxlen=l;
					start = s;
				}
			}
		}
	}

	return make_pair(maxlen,start);
}


/*
 *   DP[i][j] = true if Si....Sj is Plaindrome
 *   DP[i][j] = false if Si...Sj is not Palindrome
 *
 *
 *
 */

class Solution {
public:
	string longestPalindromic(string &str , int c1 ,int c2)
	{
		int size = str.size() ;
		while(c1 >=0 && c2<=(size-1) && str[c1]==str[c2])
		{
			c1--;
			c2++ ;
		}
		return str.substr(c1+1,c2-c1-1) ;
	}

	string longestPalindrome(string s) {

		size_t size = s.size();
		if(size==0) return "";
		string longest = s.substr(0,1);
		for(int i = 0  ; i < size-1 ; ++i)
		{
			string p = longestPalindromic(s,i,i) ;
			if(p.size()>longest.size())
			{
				longest = p ;
			}
			p = longestPalindromic(s,i,i+1) ;
			if(p.size()>longest.size())
			{
				longest = p ;
			}
		}
		return longest ;
	}
};


/*
 *
 *  Go Through Center
 *
 *
 */

class Solution1 {
public:
	string longestPalindrome(string s) {

		size_t size  = s.size() ;
		int maxLen = 1;
		int begin = 0 ;
		vector<vector<bool> > DP(size,vector<bool>(size,false)) ;

		for(int l=1 ;l<=size ;++l)
			DP[l-1][l-1] = true ;
		for(int i = 0 ; i <size-1;i++)
		{
			if(s[i]==s[i+1])
			{
				DP[i][i+1] = true ;
				maxLen = 2;
				begin = i ;
			}
		}

		for(int len = 3 ; len<= size ;++len)
		{
			for(int i = 0 ;i<(size-len+1);++i)
			{
				int j = i+len-1 ;
				if(s[i]==s[j] && DP[i+1][j-1])
				{
					DP[i][j] = true ;
					if(maxLen<len)
					{
						begin = i ;
						maxLen = len ;
					}
				}
				else
					DP[i][j] = false ;
			}
		}
		return s.substr(begin,maxLen) ;
	}
};

void printSubStr(char* str, int low, int high)
{
    for( int i = low; i <= high; ++i )
        printf("%c", str[i]);
}

// This function prints the longest palindrome substring (LPS)
// of str[]. It also returns the length of the longest palindrome
int longestPalSubstr(char *str)
{
    int maxLength = 1;  // The result (length of LPS)

    int start = 0;
    int len = strlen(str);

    int low, high;

    // One by one consider every character as center point of
    // even and length palindromes
    for (int i = 1; i < len; ++i)
    {
        // Find the longest even length palindrome with center points
        // as i-1 and i.
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }

        // Find the longest odd length palindrome with center
        // point as i
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }

    printf("Longest palindrome substring is: ");
    printSubStr(str, start, start + maxLength - 1);

    return maxLength;
}



int main(){

	string str ;
	Solution solver ;
	freopen("input.txt","rw",stdin) ;
	while(cin>>str)
	{
		cout<<str<<"====> ";
		cout<<solver.longestPalindrome(str)<<"\n" ;
	}
	return 0;
}

