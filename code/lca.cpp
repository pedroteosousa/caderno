vector<int> adj[N];
int h[N], f[N], seen[N], seg[N << 2], tme = 0;

int cmp(int u, int v) {
	if (u != -1 && (v == -1 || h[u] < h[v])) return u;
	else return v;
}

void build() {
	for(int i = 2*N-1; i > 0; i--) seg[i] = cmp(seg[i<<1], seg[i<<1|1]);
}

int query(int l, int r) {
	int resp = -1;
	for(l += 2*N, r += 2*N; l < r; l >>= 1, r >>= 1) {
		if (l&1) resp = cmp(resp, seg[l++]);
		if (r&1) resp = cmp(resp, seg[--r]);
	}
	return resp;
}

int lca(int u, int v) {
	return query(min(f[u], f[v]), max(f[u], f[v])+1);
}

void dfs(int u, int p = 0) {
	seen[u] = 1; f[u] = tme; h[u] = p;
	seg[2*N + (tme++)] = u;
	for (auto v : adj[u]) {
		if (!seen[v]) {
			dfs(v, p+1);
			seg[2*N + (tme++)] = u;
		}
	}
	if (p == 0) build();
}
