/*
 * strStr.cpp
 *
 *  Created on: Jun 26, 2014
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

class Solution {
public:
	char *strStr(char *haystack, char *needle) {
		if (*needle == '\0')
			return haystack;
		char *found = 0;
		while (*haystack) {
			char *i = haystack, *j = needle;
			while (*i && *j && *j == *i++)
				j++;
			if (!*j) {
				found = haystack;
				break;
			} else if (!(*i))
				return 0;
			haystack++;
		}
		return found;
	}
};

int main() {
	char str1[50] = "a";
	char str2[50] = "a";
	Solution sol;
	puts(sol.strStr(str1, str2));
	return 0;
}
