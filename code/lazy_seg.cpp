typedef long long ll;

const ll N = 1e5 + 5;
const ll inf = 1791791791;

struct seg_tree {
	ll seg[4*N];
	ll lazy[4*N];

	seg_tree() {
		memset(seg, 0, sizeof(seg));
		memset(lazy, 0, sizeof(lazy));
	}

	void do_lazy(ll root, ll left, ll right) {
		seg[root] += lazy[root];
		if (left != right) {
			lazy[2*root+1] += lazy[root];
			lazy[2*root+2] += lazy[root];
		}
		lazy[root] = 0;
	}

	// sum update
	ll update(ll l, ll r, ll val, ll left = 0, ll right = N-1, ll root = 0) {
		do_lazy(root, left, right);
		if (r < left || l > right) return seg[root];
		if (left >= l && right <= r) {
			lazy[root] += val;
			do_lazy(root, left, right);
			return seg[root];
		}
		ll update_left = update(l, r, val, left, (left+right)/2, 2*root+1);
		ll update_right = update(l, r, val, (left+right)/2+1, right, 2*root+2);
		return seg[root] = min(update_left, update_right);
	}

	ll query(ll l, ll r, ll left = 0, ll right = N-1, int root = 0) {
		do_lazy(root, left, right);
		if (r < left || l > right)
			return inf;
		if (left >= l && right <= r) return seg[root];
		ll query_left = query(l, r, left, (left+right)/2, 2*root+1);
		ll query_right = query(l, r, (left+right)/2+1, right, 2*root+2);
		return min(query_left, query_right);
	}
};
