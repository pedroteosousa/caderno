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
		edges.pb({i, j, c, 0}); adj[i].pb(edges.size() - 1);
		edges.pb({j, i, 0, 0}); adj[j].pb(edges.size() - 1);
	}

	int turn, seen[N], dist[N];
	bool bfs (int s, int t) {
		turn++;
		queue<int> q; q.push(t);
		dist[t] = 0; 
		while (q.size()) {
			int u = q.front(); q.pop();
			seen[u] = turn;
			for (auto e : adj[u]) {
				int v = edges[e].to;
				if (seen[v] == turn || edges[e^1].c == edges[e^1].f)
					continue;
				seen[v] = turn;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
		return seen[s] == turn;
	}

	ll dfs(int u, ll f, int s, int t) {
		if (u == t || f == 0)
			return f;
		for (auto e : adj[u]) {
			int v = edges[e].to;
			if (seen[v] != turn || dist[v] + 1 != dist[u] || edges[e].c == edges[e].f)
				continue;
			ll nf = dfs(v, min(f, edges[e].c - edges[e].f), s, t);
			if (nf) {
				edges[e].f += nf;
				edges[e^1].f -= nf;
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
