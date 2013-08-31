#include <iostream>
#include <vector>
using namespace std;
// programmed by Seregi B.
// Josephus permutáció, generátor függvény
// helyes eredmény F(6,5)-re: 5 4 6 2 3 1
int josperm(int n, int m) {
	vector<int> joseph;
	int badguys[50] = {0}, p, j = 0, cx = 0;
	for(int i = n; i > n / 2; i--) badguys[i] = 1;
	for(int i = 1; i <= n; i++) {
		joseph.push_back(i);
	}
	while(joseph.size() > 1) {
		p = 0;
		while(p != m) {
			if(j >= joseph.size()) j = 0;
			p++;
			j++;
		}
		if(badguys[joseph.at(j-1)]) cx++;
		if(!badguys[joseph.at(j-1)] && cx < n / 2 ) return false;
		joseph.erase(joseph.begin()+j-1);
		j--;
	}
	return true;
}
int main() {
	for(int i = 0; i <= 28; i += 2) {
		int m = 1;
		while(!josperm(i,m)) m++;
		cout << i << "-> " << m << endl; 
	}
	system("PAUSE");
}
