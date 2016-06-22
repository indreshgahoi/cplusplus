#include<stdio.h>

int maxsubarraysum(int A[], int n, int* pk, int* pl) {
	*pk = 0;
	*pl = 0;
	int s = 1 << 31;
	int t = 0;
	int i, j = 0;
	for (i = 0; i < n; i++) {
		t = t + A[i];
		if (t > s) {
			*pk = j;
			*pl = i;
			s = t;
		}
		if (t < 0) {
			t = 0;
			j = i + 1;
		}
	}
	return s;
}

int main() {

	int i, j;
	int a[] = { -2, -3, -4, -1, -2, -6, -5, -3 };
	int max_sum = maxsubarraysum(a, 8, &i, &j);
	printf("Maximum contiguous sum is %d\n,%d,%d", max_sum, i, j);
	return 0;
}

