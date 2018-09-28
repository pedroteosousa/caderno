struct dinic {
	struct edge {
		int from, to;
		ll c, f;
	};
	vector<edge> edges;
	vector<int> adj[N];

	void addEdge(int i, int j, ll c) {
		edges.push_back({i, j, c, 0}); adj[i].push_back(edges.size() - 1);
		edges.push_back({j, i, 0, 0}); adj[j].push_back(edges.size() - 1);
	}

	int turn, seen[N], dist[N], st[N];
	bool bfs (int s, int t) {
		seen[t] = ++turn;
		dist[t] = 0; 
		queue<int> q({t});
		while (q.size()) {
			int u = q.front(); q.pop();
			st[u] = 0;
			for (auto e : adj[u]) {
				int v = edges[e].to;
				if (seen[v] != turn && edges[e^1].c != edges[e^1].f) {
					seen[v] = turn;
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}
		return seen[s] == turn;
	}

	ll dfs(int s, int t, ll f) {
		if (s == t || f == 0)
			return f;
		for (int &i = st[s]; i < adj[s].size(); i++) {
			int e = adj[s][i], v = edges[e].to;
			if (seen[v] == turn && dist[v] + 1 == dist[s] && edges[e].c > edges[e].f) {
				if (ll nf = dfs(v, t, min(f, edges[e].c - edges[e].f))) {
					edges[e].f += nf;
					edges[e^1].f -= nf;
					return nf;
				}
			}
		}
		return 0ll;
	}

	ll max_flow(int s, int t) {
		ll resp = 0ll;
		while (bfs(s, t))
			while (ll val = dfs(s, t, inf))
				resp += val;
		return resp;
	}
};
