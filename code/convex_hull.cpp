// This solves problem E on codeforces gym 101484
#include <bits/stdc++.h>
using namespace std;

typedef long long type;
double EPS = 1e-12;

struct point {
    type x, y;
    point(type xp = 0, type yp = 0) {
        x = xp;
        y = yp;
    }

    bool operator<(const point &p) const {
		return x < p.x || x == p.x && y < p.y;
	}
};

type cross(point p, point q)  { return p.x*q.y-p.y*q.x; }

double side(point a, point b, point c) {
    return cross(a, b) + cross(b, c) + cross(c, a);
}

vector<point> convex_hull(vector<point> p) {
    int n = p.size(), k = 0;
    if (n == 1) return p;
    vector<point> hull(2*n);

    sort(p.begin(), p.end());

    for(int i=0; i<n; i++) {
		// use <= when including collinear points
        while(k>=2 && (side(hull[k-2], hull[k-1], p[i]) < 0)) k--;
        hull[k++] = p[i];
    }

    for(int i=n-2,t=k+1; i>=0; i--) {
        while(k>=t && (side(hull[k-2], hull[k-1], p[i]) < 0)) k--;
        hull[k++] = p[i];
    }

    hull.resize(k-1);
    return hull;
}

set<point> v1, v2;
int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<point> h;
	for (int i=0;i<n;i++) {
		int a, b; scanf("%d %d", &a, &b);
		point c = point(a, b);
		v1.insert(c); h.push_back(c);
	}
	for (int i=0;i<m;i++) {
		int a, b; scanf("%d %d", &a, &b);
		point c = point(a, b);
		v2.insert(c); h.push_back(c);
	}
	h = convex_hull(h);
	if (v1.find(h[0]) != v1.end()) {
		for (int i=0;i<h.size();i++)
			if (v2.find(h[i]) != v2.end()) {
				printf("NO\n"); return 0;
			}
	}
	else {
		for (int i=0;i<h.size();i++)
			if (v1.find(h[i]) != v1.end()) {
				printf("NO\n"); return 0;
			}
	}
	printf("YES\n");
}
