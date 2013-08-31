#include <iostream>
#include<cstdio>
#include <vector>
using namespace std;
// programmed by Seregi B.
// Josephus permutáció, generátor függvény
// helyes eredmény F(6,5)-re: 5 4 6 2 3 1
int solve(int n, int m) {
	vector<int> joseph;
    int i,j;
	for(int i = 1; i <= n; i++) {
		joseph.push_back(i);
	}


        i=n;
        j=m;
        while(i>1)
        {
           // printf("\n\ncall erase with j=%d steps:%d\n",j,steps);
            //erase_key(1,j);
            joseph.erase(joseph.begin()+j-1);
          // print_tree(1);
            i--;
            j=((j+m-2)%i)+1;
        }
	/*while(joseph.size() > 1) {
		p = 0;
		while(p != m) {
			if(j >= joseph.size()) j = 0;
			p++;
			j++;
		}
		joseph.erase(joseph.begin()+j-1);
		j--;
	}*/
	return joseph.at(j-1);
}
int main() {
	int T,N,M;
	scanf("%d",&T);
	while(T--)
	{
	  scanf("%d%d",&N,&M);
	  printf("%d %d %d\n",N,M,solve(N,M));

	}
}
