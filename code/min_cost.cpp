typedef long long ll;
const ll inf = 1e12;

struct min_cost {
	struct edge {
		int from, to;
		ll cp, fl, cs;
	};
	vector<edge> edges;
	vector<int> adj[N];
	
	void addEdge(int i, int j, ll cp, ll cs) {
		edges.push_back({i, j, cp, 0, cs}); adj[i].push_back(edges.size() - 1);
		edges.push_back({j, i, 0, 0, -cs}); adj[j].push_back(edges.size() - 1);
	}

	ll seen[N], dist[N], pai[N], cost, flow;
	int turn;
	ll spfa(int s, int t) {
		turn++;
		queue<int> q; q.push(s);
		for (int i = 0; i < N; i++) dist[i] = inf;
		dist[s] = 0;
		seen[s] = turn;
		while (q.size()) {
			int u = q.front(); q.pop();
			seen[u] = 0;
			for (auto e : adj[u]) {
				int v = edges[e].to;
				if (edges[e].cp > edges[e].fl && dist[u] + edges[e].cs < dist[v]) {
					dist[v] = dist[u] + edges[e].cs;
					pai[v] = e ^ 1;
					if (seen[v] < turn) {
						seen[v] = turn;
						q.push(v);
					}
				}
			}
		}
		if (dist[t] == inf) return 0;
		ll nfl = inf;
		for (int u = t; u != s; u = edges[pai[u]].to)
			nfl = min(nfl, edges[pai[u] ^ 1].cp - edges[pai[u] ^ 1].fl);
		cost += dist[t] * nfl;
		for (int u = t; u != s; u = edges[pai[u]].to) {
			edges[pai[u]].fl -= nfl;
			edges[pai[u] ^ 1].fl += nfl;
		}
		return nfl;
	}

	void mncost(int s, int t) {
		cost = flow = 0;
		while (ll fl = spfa(s, t))
			flow += fl;
	}
};
