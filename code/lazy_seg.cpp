typedef long long ll;

const ll N = 1e5 + 5;

struct seg_tree {
	ll seg[4*N];
	ll lazy[4*N];

	seg_tree() {
		memset(seg, 0, sizeof(seg));
		memset(lazy, 0, sizeof(lazy));
	}

	void do_lazy(int i, int l, int r) {
		seg[i] += (ll)(r - l + 1) * lazy[i];
		if (l != r) {
			lazy[2 * i + 1] += lazy[i];
			lazy[2 * i + 2] += lazy[i];
		}
		lazy[i] = 0;
	}

	void update(int ql, int qr, ll v, int l = 0, int r = N - 1, int i = 0) {
		do_lazy(i, l, r);
		if (qr < l || r < ql)
            return;
		if (ql <= l && r <= qr) {
			lazy[i] += v;
			do_lazy(i, l, r);
			return;
		}
        int mid = (l + r) / 2;
		update(ql, qr, v, l, mid, 2 * i + 1);
		update(ql, qr, v, mid + 1, r, 2 * i + 2);
		seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
	}

	ll query(int ql, int qr, int l = 0, int r = N - 1, int i = 0) {
		do_lazy(i, l, r);
		if (qr < l || r < ql)
			return 0;
		if (ql <= l && r <= qr)
            return seg[i];
        int mid = (l + r) / 2;
		return query(ql, qr, l, mid, 2 * i + 1)
	         + query(ql, qr, mid + 1, r, 2 * i + 2);
	}
};

