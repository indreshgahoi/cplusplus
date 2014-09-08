/*
 * ForgatPassword.cpp
 *
 *  Created on: Jun 11, 2014
 *      Author: Indresh Gahoi
 */

#include <iostream>
#include <cstdio>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;

void solve(char str[], map<char, char> &dcryptTbl) {
	int size = (int) strlen(str);
	int i = 0;
	while (i < size) {
		if(dcryptTbl.find(str[i]) != dcryptTbl.end())
			str[i] = dcryptTbl[str[i]];
		i++;
	}
	int start = 0, end = size - 1, mid = 0;

	i = 0;
	while (i < size && str[i] == '0')
		i++;
	if (i == size) {
		printf("0\n");
		return;
	}
	start = i;
	while (i < size && str[i] != '.')
		i++;
	if (i == size) {
		while (start < size) {
			printf("%c", str[start]);
			start++;
		}
		printf("\n");
		return;
	}
	mid = i;
	while (end > mid && str[end] == '0')
		end--;
	if (end == mid)
		end = mid - 1;
	if (end < start) {
		printf("0\n");
		return;
	} else {
		while (start <= end) {
			printf("%c", str[start]);
			start++;
		}
		printf("\n");
	}

}

int main() {
	int T, R;
	char p, c;
	char str[1000005];
	char tbl[3] ;
	scanf("%d", &T);
	map<char, char> dcryptTbl;
	while (T--) {
		dcryptTbl.clear();
		scanf("%d", &R);
		while (R--) {
			scanf("%s",tbl);
			p = tbl[0];
			scanf("%s",tbl);
			c = tbl[0];
			dcryptTbl[p] = c;
		}
		scanf("%s", str);
		solve(str, dcryptTbl);
	}
	return 0;
}

