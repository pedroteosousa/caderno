int t[N<<1];

void build(int n) {
	for(int i = n-1; i > 0; i--) t[i] = min(t[i<<1], t[i<<1|1]);
}

void modify(int pos, int val, int n) {
	for(t[pos += n] = val; pos != 1; pos>>=1)
		t[pos>>1] = min(t[pos], t[pos^1]);
}

int query(int l, int r, int n) { // [l, r)
	int resp = 1000000007;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) resp = min(resp, t[l++]);
		if (r&1) resp = min(resp, t[--r]);
	}
	return resp;
}
