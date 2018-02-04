#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;
const int N = 2e3;
const ll inf = 1e12;

struct dinitz {
	struct edge {
		int from, to;
		ll c, f;
	};
	vector<edge> edges;
	vector<int> adj[N];
	
	void addEdge(int i, int j, ll c) {
		edges.pb({i, j, c, 0ll});
		adj[i].pb(edges.size() - 1);
		edges.pb({j, i, 0ll, 0ll});
		adj[j].pb(edges.size() - 1);
	}

	int tbfs, seen[N], dist[N];
	bool bfs (int s, int t) {
		tbfs++;
		queue<int> q; q.push(t);
		dist[t] = 0; 
		while (q.size()) {
			int u = q.front(); q.pop();
			seen[u] = tbfs;
			for (auto a : adj[u]) {
				int v = edges[a].to;
				if (seen[v] == tbfs || edges[a^1].c == edges[a^1].f)
					continue;
				seen[v] = tbfs;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
		return seen[s] == tbfs;
	}

	ll dfs(int u, ll f, int s, int t) {
		if (u == t || f == 0)
			return f;
		for (auto a : adj[u]) {
			int v = edges[a].to;
			if (seen[v] != tbfs || dist[v] + 1 != dist[u] || edges[a].c == edges[a].f)
				continue;
			ll nf = dfs(v, min(f, edges[a].c - edges[a].f), s, t);
			if (nf) {
				edges[a].f += nf;
				edges[a^1].f -= nf;
				return nf;
			}
		}
		return 0ll;
	}

	ll max_flow(int s, int t) {
		ll resp = 0ll;
		while (bfs(s, t)) {
			ll val = 0;
			do {
				resp += val;
				val = dfs(s, inf, s, t);
			} while (val);
		}
		return resp;
	}
};
