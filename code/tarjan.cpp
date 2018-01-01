#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int inf = 1791791791;

vector<int> conn[N];

// time complexity: O(V+E)
stack<int> ts;
int tme = 0, ncomp = 0, low[N], seen[N];
int comp[N]; // nodes in the same scc have the same color
int scc_dfs(int n) {
	seen[n] = low[n] = ++tme;
	ts.push(n);
	for (auto a : conn[n]) {
		if (seen[a] == 0)
			scc_dfs(a);
		low[n] = min(low[n], low[a]);
	}
	if (low[n] == seen[n]) {
		int node;
		do {
			node = ts.top(); ts.pop();
			comp[node] = ncomp;
			low[node] = inf;
		} while (n != node && ts.size());
		ncomp++;
	}
	return low[n];
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);	
		conn[a].push_back(b);
	}
	map<int, vector<int> > comps;
	for (int i=0;i<n;i++) {
		if (!seen[i]) scc_dfs(i);
		comps[comp[i]].push_back(i);
	}
	for (auto a : comps) {
		printf("%d: ", a.first);
		for (auto v : a.second)
			printf("%d ", v);
		printf("\n");
	}
}
