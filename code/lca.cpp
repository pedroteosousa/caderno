const int N = 1e6 + 5;
const int L = 20;

vector<int> adj[N];
int prof[N], p[N][L+5];

void dfs(int v, int h = 1) {
	prof[v] = h;
	if (h == 1) p[v][0] = v;
	for (auto u : adj[v])
		if (prof[u] == 0) {
			p[u][0] = v;
			dfs(u, h+1);
		}
}

void init(int n) {
	for (int i = 1; i <= L; i++)
		for (int j = 1; j < n; j++)
			p[j][i] = p[p[j][i-1]][i-1];
}

int lca(int u, int v) {
	if (prof[u] < prof[v]) swap(u, v);
	for (int i = L; i >= 0; i--)
		if (prof[p[u][i]] >= prof[v])
			u = p[u][i];
	for (int i = L; i >= 0; i--)
		if (p[u][i] != p[v][i]) {
			u = p[u][i];
			v = p[v][i];
		}
	while (u != v) {
		u = p[u][0];
		v = p[v][0];
	}
	return u;
}
