#include <iostream>
#include<cmath>
using namespace std;

int m, n;
int original[][];
int longest[][];

int find() {
	int max = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int current = findfor(i, j);
			if (current > max) {
				max = current;
			}
		}
	}
	return max;
}

int findfor(int i, int j) {
	int max = 0;
	if (longest[i][j] == 0) {

		for (int k = -1; k <= 1; k++) {
			for (int l = -1; l <= 1; l++) {
				if (!(k == 0 && l == 0) && i + k >= 0 && i + k < m && j + l >= 0
						&& j + l < n && original[i + k][j + l] > original[i][j])
					int current = findfor(i + k, j + l);
				if (current > max) {
					max = current;
				}
			}
		}
	}
	longest[i][j] = max + 1;

	return longest[i][j];
}

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		cin >> m >> n;
		longest = new int[m][n];
	}
}
