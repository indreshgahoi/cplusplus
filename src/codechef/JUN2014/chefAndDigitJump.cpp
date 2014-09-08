/*
 * chefAndDigitJump.cpp
 *
 * Created on: Jun 12, 2014
 * Author: Indresh Gahoi
 */

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<fstream>
#include<limits.h>
#include<climits>
#include <limits>
#include<set>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<fstream>
#include<limits.h>
#include<climits>
#include <limits>
#include <queue>
#include<set>
using namespace std;
#define MAX 100005

vector<vector<int> > adj(10, vector<int>());
char str[MAX];
int len;
struct state {
	int index;
	int steps;
	state(int ind, int min) {
		this->index = ind;
		this->steps = min;
	}

	int operator <(const state & state) const {
		if (this->steps == state.steps)
			return this->index > state.index;
		else
			return this->steps < state.steps;
	}
};





int minSteps() {
	vector<bool> visited(len, false);
	vector<state> nodes;
	for (int i = 0; i < len; i++) {

		nodes.push_back(*(new state(i, i)));
	}
	queue<state> pq;
	nodes[0].steps = 0;
	state &nextState = nodes[0];
	pq.push(nextState);

	while (pq.size() > 0) {

		state current = pq.front();
// printf("\nStart###############################\n");
// for( ; it != pq.end();it++){
// state st = *it ;
// printf("\nindex : %d steps : %d ",st.index,st.steps);
// }
// printf("\nEnd###############################\n");
		pq.pop();

		if (visited[current.index])
			continue;
		visited[current.index] = true;
		if (current.index == (len - 1)) {
			return current.steps;
		}

		if (current.index > 0) {
			state &nextState = nodes[current.index - 1];
			if (!visited[nextState.index]) {
				nextState.steps = min(current.steps + 1, nextState.steps);
				pq.push(nextState);
			}
		}
		state &nextState = nodes[current.index + 1];
		if (!visited[nextState.index]) {
			nextState.steps = min(current.steps + 1, nextState.steps);
			pq.push(nextState);
		}

		for (int i = 0; i < adj[str[current.index] - '0'].size(); ++i) {
			state &nextState = nodes[adj[(str[current.index] - '0')].at(i)];
			if (!visited[nextState.index]) {
				nextState.steps = min(current.steps + 1, nextState.steps);
				pq.push(nextState);
			}
		}
		adj[str[current.index] - '0'].clear();
	}

	return -1;

}

/*
 *  Dp Solution (by Greay Seraja)
 *
 *  Credit for the solution goes to Sergey Nagin(Sereja).

Let dp[i] denote the number of steps required to go from position 0 to position i.
From the previous observations, we know that we wont need more than 20 steps.
So lets make 20 iterations.

Before starting all the iterations, we will set
     dp[1] = 0            and
     dp[i] = infinity  for all other i > 1.

On each iteration, we will calculate Q[k] where Q[k] is the minimum value of dp[i]
  such that s[i] = k. ie.
  Q[k] denotes the minimum value of dp over the positions where the digit is equal to k.

We can update the dp by following method.

	dp[i] = min(dp[i], dp[i - 1] + 1, dp[i + 1] + 1, Q[s[i]] + 1);

Here the term dp[i - 1] + 1 denotes that we have come from previous position ie (i - 1).
Here the term dp[i + 1] + 1 denotes that we have come from next position ie (i + 1).
The term Q[s[i]] + 1 denotes the minimum number of operations needed to come from a position with same digit as the current i th digit

*
*
*
*/


int minStepsByDp(){
	vector<int> Q(10,50);
	vector<int> dp(len,50);

	dp[0] = 0 ;
	for(int it = 0 ; it < 20 ; ++it){

		for(int i =0 ; i < 10 ; ++i){
			Q[i] = 50 ;
		}

		for(int i = 0 ; i < len ; ++i)
			Q[str[i]-'0'] = min(Q[str[i]-'0'],dp[i]);

		for(int i = 1 ; i < len ; ++i){
			if(i < (len-1)){
				dp[i] = min(min(dp[i-1]+1,dp[i+1]+1),Q[str[i]-'0']+1);
			}else {
				dp[i] = min(dp[i-1]+1,Q[str[i]-'0']+1);
			}
		}
	}
	return dp[len-1];

}



int main() {
	scanf("%s", str);
	int length = strlen(str);
	int end = 0, i = 0, c;
	while (i < length) {
		int j = i;
		c = 0;
		while (j < length && str[i] == str[j]) {
			c++;
			j++;
		}
		if (c == 1) {
			str[end] = str[i];
			end++;
		} else if (c >= 2) {
			str[end] = str[end + 1] = str[i];
			end += 2;
		}
		i = j;
	}
	str[end] = '\0';
	len = end;
//printf("str : %s end : %d \n", str, end);
	i = 0;
	while (i < len) {
		adj[(str[i] - '0')].push_back(i);
		i++;
	}
	printf("%d\n", minStepsByDp());
}
