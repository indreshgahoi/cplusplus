/*Tuan Anh
It would be easier if you solve this problem in the array first. 
Then come to the tree and finally, solve it on the connected graph with n edges.

Since exactly one cycle exists in the graph, we still can divides the graph into paths 
like we do in the light-heavy decomposition.
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <vector>
#include <queue>

using namespace std;

#define PI acos(-1)
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define PII pair <int, int>
#define LL long long
#define SET(v,i) memset(v, i, sizeof(v))
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define FORN(i,b) for (int i = 0; i < (b); i++)
#define DOWN(i,a,b) for (int i = a; i >= (b); i--)
#define FIT(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define FITD(it,v) for (typeof(v.rbegin()) it = v.rbegin(); it != v.rend(); it++)

#define maxn 200111

int cs[maxn], pos[maxn], posCycle[maxn], numChild[maxn];
int kthParent[maxn][20], depth[maxn];
vector < PII > adj[maxn];
bool visited[maxn], done[maxn], onCycle[maxn];
int endSeg[maxn];
int trace[maxn];
int n, nCs;
vector <int> cycle;
map < PII, int> cost;

int midle[maxn * 4], reverseMidle[maxn * 4], minLeft[maxn * 4], maxLeft[maxn * 4],
	minRight[maxn * 4], maxRight[maxn * 4], sum[maxn * 4], ok[maxn * 4];

struct intervalTree {
	vector < pair <int, PII > > seg;

	int maxSeg, pr;
	void reverse(int u, int v) {
		if (u >= v) return;
		FOR (i, 1, (v - u + 1) / 2)
			swap(seg[u + i - 1], seg[v - i + 1]);
	}

    //update the information of node s from its children
	void addUp(int s) {
		int s1 = s << 1, s2 = s1 + 1;

		sum[s] = sum[s1] + sum[s2];

		minLeft[s] = min(minLeft[s1], sum[s1] + minLeft[s2]);
		maxLeft[s] = max(maxLeft[s1], sum[s1] + maxLeft[s2]);

		minRight[s] = min(minRight[s2], sum[s2] + minRight[s1]);
		maxRight[s] = max(maxRight[s2], sum[s2] + maxRight[s1]);

		midle[s] = max(midle[s1], midle[s2]);
		midle[s] = max(midle[s], maxRight[s1] + maxLeft[s2]);

		reverseMidle[s] = min(reverseMidle[s1], reverseMidle[s2]);
		reverseMidle[s] = min(reverseMidle[s], minRight[s1] + minLeft[s2]);
	}

    //flip node s
	void cover(int s) {
		ok[s] = (ok[s] + 1) % 2;

		swap(midle[s], reverseMidle[s]);
		swap(minLeft[s], maxLeft[s]);
		swap(minRight[s], maxRight[s]);

		sum[s] = -sum[s];
		midle[s] = -midle[s];
		reverseMidle[s] = -reverseMidle[s];
		minLeft[s] = -minLeft[s];
		maxLeft[s] = -maxLeft[s];
		minRight[s] = -minRight[s];
		maxRight[s] = -maxRight[s];
	}

    //prepare the interval tree
	void makeTree(int s, int l, int r) {
		if (l == r) {
			int tmp;
			int v = cs[l + 1];
			if (l > cycle.size()) v = kthParent[cs[l]][0];
			if (cost.find(MP(cs[l], v)) == cost.end()) tmp = 0;
			else tmp = cost[ MP(cs[l], v) ];

			sum[s] = tmp;
			midle[s] = max(0, tmp);
			reverseMidle[s] = min(0, tmp);
			minLeft[s] = min(0, tmp);
			maxLeft[s] = max(0, tmp);
			minRight[s] = min(0, tmp);
			maxRight[s] = max(0, tmp);
			ok[s] = 0;

			return;
		}

		makeTree(s << 1, l, (l + r) >> 1);
		makeTree((s << 1) + 1, ((l + r) >> 1) + 1, r);

		addUp(s);
	}

    //flip from the position u to position v
	void update(int s, int l, int r, int u, int v) {
		if (v < l || r < u) return;

		if (u <= l && r <= v) {
			cover(s);
			return;
		}

		down(s, l, r);

		update(s << 1, l, (l + r) >> 1, u, v);
		update( (s << 1) + 1, ((l + r) >> 1) + 1, r, u, v);

		addUp(s);
	}

    //lazy update - push the stored information down
	void down (int s, int l, int r) {
		if (ok[s] == 0) return;

		ok[s] = 0;
		if (l == r) return;

		int s1 = s << 1, s2 = s1 + 1;

		cover(s1);
		cover(s2);
	}

    //get the information from position u to position v
	void get(int s, int l, int r, int u, int v) {
		down(s, l, r);

		if (v < l || r < u) return;

		if (u <= l && r <= v) {
			maxSeg = max(maxSeg, midle[s]);
            seg.PB (MP(maxLeft[s], MP(sum[s], maxRight[s])));
			return;
		}

		get(s << 1, l, (l + r) >> 1, u, v);
		get((s << 1) + 1, ((l + r) >> 1) + 1, r, u, v);
	}

    //get the information from position u to position v inversely
	void get_reverse(int s, int l, int r, int u, int v) {
		down(s, l, r);

		if (v < l || r < u) return;

		if (u <= l && r <= v) {
			maxSeg = max(maxSeg, midle[s]);
            seg.PB (MP(maxRight[s], MP(sum[s], maxLeft[s])));
			return;
		}

		get_reverse(s << 1, l, (l + r) >> 1, u, v);
		get_reverse((s << 1) + 1, ((l + r) >> 1) + 1, r, u, v);
	}

    //get the information from vertex u to vertex v
	void doIt(int u, int v) {
		if (depth[endSeg[u]] <= depth[v]) {
			get(1, 1, nCs, pos[u], pos[v]);
			return;
		}

		get(1, 1, nCs, pos[u], pos[endSeg[u]]);
		doIt(kthParent[endSeg[u]][0], v);
	}

    //get the information from vertex u to vertex v inversely
	void doIt_reverse(int u, int v) {
		if (depth[endSeg[u]] <= depth[v]) {
			get_reverse(1, 1, nCs, pos[u], pos[v]);
			return;
		}

		get_reverse(1, 1, nCs, pos[u], pos[endSeg[u]]);
		doIt_reverse(kthParent[endSeg[u]][0], v);
	}

} ITree;

void enter() {
	cin >> n;
	FOR (i, 1, n) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		adj[u].PB(MP(v, c));
		adj[v].PB(MP(u, c));

		cost[ MP(u, v) ] = c;
		cost[ MP(v, u) ] = c;
	}
}

// find the cycle
void dfs(int u) {
	visited[u] = true;

	FORN(i, adj[u].size()) {
		int v = adj[u][i].first;

		if (!visited[v]) {
			trace[v] = u;
			dfs(v);
		}
		else if (trace[u] != v && !done[v]) {
			cycle.clear();
			int t = u;
			while (t != v) {
				cycle.PB(t);
				onCycle[t] = true;
				t = trace[t];
			}
			cycle.PB(v);
			onCycle[v] = true;
		}
	}

	done[u] = true;
}

void findCycle() {
	SET (trace, 0);
	SET (visited, false);
	SET (done, false);
	SET (onCycle, false);
	trace[1] = 1;
	dfs(1);

	/*FOR (i, 1, n) if (onCycle[i]) cout << i << " ";
    cout << endl;


	FORN (i, cycle.size())
	   cout << cycle[i] << " ";
	cout << endl;*/

}

// prepare some information for LCA and Dynamic tree
void DFS_2(int u) {
	numChild[u] = 1;
	trace[u] = 0;
	int t;
	t = 0;

	FORN (i, adj[u].size()) {
		int v = adj[u][i].first;
		if (numChild[v] == 0 && !onCycle[v]) {
			kthParent[v][0] = u;
			depth[v] = depth[u] + 1;
			DFS_2(v);
			numChild[u] += numChild[v];
			if (numChild[t] < numChild[v])
                t = v;
		}
	}

	trace[t] = u;
}

// rearrange the vertices in an array
void prepareCs() {
	SET (numChild, 0);
	SET (kthParent, 0);

	FOR (i, 1, n)
		if (onCycle[i]) {
			kthParent[i][0] = i;
			depth[i] = 1;
			DFS_2(i);
		}

	FOR (i, 1, 19)
		FOR (u, 1, n)
			kthParent[u][i] = kthParent[kthParent[u][i - 1]][i - 1];

	nCs = 0;
	FORN (i, cycle.size())
		cs[++nCs] = cycle[i];
	cs[++nCs] = cycle[0];

	FOR (i, 1, n)
		if (numChild[i] == 1) {
			int u = i;

			do {
				cs[++nCs] = u;
				u = trace[u];
			}
			while (u);

			u = i;
			do {
				endSeg[u] = cs[nCs];
				u = trace[u];
			}
			while (u);
		}

	DOWN (i, nCs, 1) posCycle[cs[i]] = i;
	FOR (i, 1, nCs) pos[cs[i]] = i;


   /*
    FOR (i, 1, nCs) cout << cs[i] << " ";
    cout << endl;
	FOR (i, 1, nCs) cout << endSeg[cs[i]] << " ";
	cout << endl;
	FOR (i, 1, n) cout << depth[i] << " ";
	cout << endl;

	FOR (i, 1, n) {
        FOR (j, 0, 10) cout << kthParent[i][j] << " ";
        cout << endl;
    }*/
}

//flip from vertex u to the its ancestor that belong to the cycle
void flip(int u) {
	while (1) {
		ITree.update(1, 1, nCs, pos[u], pos[endSeg[u]]);
		if (onCycle[endSeg[u]]) break;
		u = kthParent[endSeg[u]][0];
	}
}

int LCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    DOWN (i, 19, 0)
        if (depth[kthParent[u][i]] >= depth[v])
            u = kthParent[u][i];

    if (u == v) return v;

    DOWN (i, 19, 0)
        if (kthParent[u][i] != kthParent[v][i]) {
            u = kthParent[u][i];
            v = kthParent[v][i];
        }

    return kthParent[u][0];
}

//flip from vertex u to vertex v
void flip(int u, int v) {
	if (kthParent[u][19] == kthParent[v][19]) {
        //if u and v belong to the same sub-tree
        //let t = LCA(u, v) so after two flips below, only edges on the path from u to v is flipped
		flip(u);
		flip(v);
	}
	else {
	    //the shortest path from u to v must go through the cycle
		flip (u);
		flip (v);

		int s = kthParent[u][19];
		int t = kthParent[v][19];
		if (posCycle[s] > posCycle[t])
            swap(s, t);

        int z = cycle.size();
        if (posCycle[t] - posCycle[s] + 1 > posCycle[s] + z - posCycle[t] + 1)
            ITree.update(1, 1, nCs, 1, z);

		ITree.update(1, 1, nCs, posCycle[s], posCycle[t] - 1);
	}

}

//answer the query ? u v
void find(int u, int v) {
	ITree.maxSeg = 0;
	ITree.seg.clear();

	if (kthParent[u][19] == kthParent[v][19]) {
        //if u and v belong to the same sub-tree
		int t = LCA(u, v);

		if (t != u) {
			int last = u;
			DOWN (i, 19, 0)
				while (depth[kthParent[last][i]] >= depth[t] + 1)
					last = kthParent[last][i];

            //last is the vertex right before t on the path from u to t
            //consider the path from u to last
			ITree.doIt(u, last);
		}

		if (t != v) {
			int last = v;
			DOWN (i, 19, 0)
				while (depth[kthParent[last][i]] >= depth[t] + 1)
					last = kthParent[last][i];

            //last is the vertex right before t on the path from v to t
            //consider the path from v to last inversely
			int before = ITree.seg.size();
			ITree.doIt_reverse(v, last);
			int after = ITree.seg.size();
			ITree.reverse(before, after - 1);
		}

	}
	else {
        //u and v belong to different sub-trees
		int s = kthParent[u][19];
		int t = kthParent[v][19];

		if (s != u) {
			int last = u;
			DOWN (i, 19, 0)
				while (depth[kthParent[last][i]] >= depth[s] + 1)
					last = kthParent[last][i];
            //last is the vertex right before s on the path from u to s
            //consider the path from u to last
			ITree.doIt(u, last);
		}


        //consider some cases which depend on the position of s and t on vector Cycle
		int ss = s, tt = t, z = cycle.size();
		if (posCycle[ss] > posCycle[tt]) swap (ss, tt);

		if (posCycle[tt] - posCycle[ss] + 1 < posCycle[ss] + z - posCycle[tt] + 1) {
			if (posCycle[s] < posCycle[t])
				ITree.get(1, 1, nCs, posCycle[s], posCycle[t] - 1);
			else {
				int before = ITree.seg.size();
				ITree.get_reverse(1, 1, nCs, posCycle[t], posCycle[s] - 1);
				int after = ITree.seg.size();
				ITree.reverse(before, after - 1);
			}
		}
		else {
			if (posCycle[s] > posCycle[t]) {
				ITree.get(1, 1, nCs, posCycle[s], z);
				ITree.get(1, 1, nCs, 1, posCycle[t] - 1);

			}
			else {
				if (posCycle[s] > 1) {
					int before = ITree.seg.size();
					ITree.get_reverse(1, 1, nCs, 1, posCycle[s] - 1);
					int after = ITree.seg.size();
					ITree.reverse(before, after - 1);
				}

				int before = ITree.seg.size();
				ITree.get_reverse(1, 1, nCs, posCycle[t], z);
				int after = ITree.seg.size();
				ITree.reverse(before, after - 1);
			}
		}


		if (t != v) {
			int last = v;
			DOWN (i, 19, 0)
				while (depth[kthParent[last][i]] >= depth[t] + 1)
					last = kthParent[last][i];

            //last is the vertex right before t on the path from v to t
            //consider the path from v to last inversely
			int before = ITree.seg.size();
			ITree.doIt_reverse(v, last);
			int after = ITree.seg.size();
			ITree.reverse(before, after - 1);
		}
	}

	int pr = 0;
	FORN (i, ITree.seg.size()) {
		ITree.maxSeg = max(ITree.maxSeg, ITree.seg[i].first + pr);
		pr = max(ITree.seg[i].second.second, pr + ITree.seg[i].second.first);
	}

	printf("%d\n", ITree.maxSeg);
}

int main() {
	enter();
	findCycle();
	prepareCs();

	ITree.makeTree(1, 1, nCs);
	int q;
	cin >> q;

	while (q--) {
        char c;
        scanf("%c", &c);
        while (c != '?' && c != 'f')
            scanf("%c", &c);

        int u, v;
        scanf("%d%d", &u, &v);

        if (c == '?')
            find(u, v);
        else flip(u, v);
    }
	return 0;
}