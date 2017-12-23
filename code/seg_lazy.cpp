const int inf = 1791791791;

const int N = 1e6 + 5;

int seg[4*N];
int lazy[4*N];

void do_lazy(int root, int ll, int rl) {
	seg[root] += lazy[root];
	if (ll != rl) {
		lazy[2*root+1] += lazy[root];
		lazy[2*root+2] += lazy[root];
	}
	lazy[root] = 0;
}

int update(int root, int ll, int rl, int l, int r, int val) {
	do_lazy(root, ll, rl);
	if (r < ll || l > rl) return seg[root];
	if (ll >= l && rl <= r) {
		lazy[root] += val;
		do_lazy(root, ll, rl);
		return seg[root];
	}
	int update_left = update(2*root+1, ll, (ll+rl)/2, l, r, val);
	int update_right = update(2*root+2, (ll+rl)/2+1, rl, l, r, val);
	return seg[root] = min(update_left, update_right);
}

int query(int root, int ll, int rl, int l, int r) {
	do_lazy(root, ll, rl);
	if (r < ll || l > rl) return inf;
	if (ll >= l && rl <= r) return seg[root];
	int query_left = query(2*root+1, ll, (ll+rl)/2, l, r);
	int query_right = query(2*root+2, (ll+rl)/2+1, rl, l, r);
	return min(query_left, query_right); 
}
