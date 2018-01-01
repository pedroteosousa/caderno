// This solves HORRIBLE on SPOJ
#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const lli N = 1e5 + 5;
const lli inf = 1791791791;

/* type: 0 = min
   		 1 = max
   		 2 = sum */
template <int type> struct seg_tree {
	lli seg[4*N];
	lli lazy[4*N];
	
	seg_tree() {
		memset(seg, 0, sizeof(seg));
		memset(lazy, 0, sizeof(lazy));
	}

	void do_lazy(lli root, lli ll, lli rl) {
		if (type == 2)
			seg[root] += (rl-ll+1)*lazy[root];
		else
			seg[root] += lazy[root];
		if (ll != rl) {
			lazy[2*root+1] += lazy[root];
			lazy[2*root+2] += lazy[root];
		}
		lazy[root] = 0;
	}

	// sum update
	lli update(lli l, lli r, lli val, lli ll = 0, lli rl = N-1, lli root = 0) {
		do_lazy(root, ll, rl);
		if (r < ll || l > rl) return seg[root];
		if (ll >= l && rl <= r) {
			lazy[root] += val;
			do_lazy(root, ll, rl);
			return seg[root];
		}
		lli update_left = update(l, r, val, ll, (ll+rl)/2, 2*root+1);
		lli update_right = update(l, r, val, (ll+rl)/2+1, rl, 2*root+2);
		if (type == 0)	
			return seg[root] = min(update_left, update_right);
		if (type == 1)	
			return seg[root] = max(update_left, update_right);
		if (type == 2)
			return seg[root] = update_left + update_right;
	}

	lli query(lli l, lli r, lli ll = 0, lli rl = N-1, int root = 0) {
		do_lazy(root, ll, rl);
		if (r < ll || l > rl) {
			if (type == 0)
				return inf;
			if (type == 1)
				return -inf;
			if (type == 2)
				return 0;
		}
		if (ll >= l && rl <= r) return seg[root];
		lli query_left = query(l, r, ll, (ll+rl)/2, 2*root+1);
		lli query_right = query(l, r, (ll+rl)/2+1, rl, 2*root+2);
		if (type == 0)
			return min(query_left, query_right);
		if (type == 1)
			return max(query_left, query_right);
		if (type == 2)
			return query_left + query_right;
	}
};

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, c; scanf("%d %d", &n, &c);
		seg_tree <2> t;
		while (c--) {
			int op, l, r;
			scanf("%d %d %d", &op, &l, &r);
			l--; r--;
			if (op == 0) {
				int v; scanf("%d", &v);
				t.update(l, r, v);
			}
			else
				printf("%lld\n", t.query(l, r));
		}
	}
}
