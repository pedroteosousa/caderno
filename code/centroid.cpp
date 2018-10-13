vector<int> adj[N], centroid[N];
int sze[N];

int dfs(int v, int p = 0) {
    sze[v] = 1;
    for (int u: adj[v])
        if (u != p && sze[u] != -1) sze[v] += dfs(u, v);
    return sze[v];
}

// returns root of centroid tree
int build(int v) {
    int n = dfs(v, v);
    int w = v;
    do {
        v = w;
        for (int u: adj[v])
            if (sze[u] != -1 && sze[u] < sze[v] && 2 * sze[u] >= n)
                w = u;
    } while (v != w);
    sze[v] = -1;
    for (int u: adj[v])
        if (sze[u] != -1)
            centroid[v].push_back(build(u));
    return v;
}