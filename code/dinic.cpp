#include <bits/stdc++.h>

using namespace std;

const int N = 5000;

int nodes = N, src, dest;
int dist[N], q[N], work[N];

struct Edge {
    int to, rev;
    int f, cap;
};

vector<Edge> g[N];

void addEdge(int s, int t, int cap){
    Edge a = {t, 0, 0, cap};
    Edge b = {s, (int)g[s].size(), 0, 0};
    g[s].push_back(a);
    g[t].push_back(b);
}

bool dinic_bfs() {
    fill(dist, dist + nodes, -1);
    dist[src] = 0;
    int qt = 0;
    q[qt++] = src;
    for (int qh = 0; qh < qt; qh++) {
        int u = q[qh];
        for (int j = 0; j < (int) g[u].size(); j++) {
            Edge &e = g[u][j];
            int v = e.to;
            if (dist[v] < 0 && e.f < e.cap) {
                dist[v] = dist[u] + 1;
                q[qt++] = v;
            }
        }
    }
    return dist[dest] >= 0;
}

int dinic_dfs(int u, int f) {
    if (u == dest)
        return f;
    for (int &i = work[u]; i < (int) g[u].size(); i++) {
        Edge &e = g[u][i];
        if (e.cap <= e.f) continue;
        int v = e.to;
        if (dist[v] == dist[u] + 1) {
            int df = dinic_dfs(v, min(f, e.cap - e.f));
            if (df > 0) {
                e.f += df;
                g[v][e.rev].f -= df;
                return df;
            }
        }
    }
    return 0;
}

int maxFlow(int _src, int _dest) {
    src = _src;
    dest = _dest;
    int result = 0;
    while (dinic_bfs()) {
        fill(work, work + nodes, 0);
        while (int delta = dinic_dfs(src, INT_MAX))
            result += delta;
    }
    return result;
}

int main() {
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    map<int, vector<int> > fi, se;
    map<int, string> as;
    for(int i=0;i<n;i++) {
        addEdge(n+m, i, 1);
        string s;
        cin >> s;
        as[i] = s;
        fi[s[0]+s[1]+s[2]].push_back(i);
        se[s[3]+s[4]+s[5]].push_back(i);
    }
    for(int i=0;i<m;i++) {
        addEdge(i+n, n+m+1, 1);
        string s;
        cin >> s;
        as[i+n] = s;
        for(int j=0;j<se[s[0]+s[1]+s[2]].size();j++) {
            addEdge(se[s[0]+s[1]+s[2]][j], i+n, 1);
        }
        for(int j=0;j<fi[s[3]+s[4]+s[5]].size();j++) {
            addEdge(fi[s[3]+s[4]+s[5]][j], i+n, 1);
        }
    }
    int nk = maxFlow(n+m, n+m+1);
    printf("%d\n", nk);
    for(int i=-n;i<0;i++) {
        for(int j=0;j<g[i+n].size(); j++) {
            if (g[i+n][j].f) {
                if (as[i+n][0]+as[i+n][1]+as[i+n][2]==as[g[i+n][j].to][3]+as[g[i+n][j].to][4]+as[g[i+n][j].to][5]) printf("AT %s %s\n", as[i+n].c_str(), as[g[i+n][j].to].c_str());
                if (as[i+n][3]+as[i+n][4]+as[i+n][5]==as[g[i+n][j].to][0]+as[g[i+n][j].to][1]+as[g[i+n][j].to][2]) printf("TA %s %s\n",  as[g[i+n][j].to].c_str(), as[i+n].c_str());
            }
        }
    }

}
