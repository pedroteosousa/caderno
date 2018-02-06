double EPS = 1e-12;

struct point {
	double x, y;

	point () {}
	point (double a = 0, double b = 0) { x = a; y = b; }
	point (const point &p) { x = p.x; y = p.y; }

	point operator+ (const point &p) { return {x+p.x, y+p.y}; }
	point operator- (const point &p) { return {x-p.x, y-p.y}; }
	point operator* (double c) { return {c*x, c*y}; }
	point operator/ (double c) { return {x/c, y/c}; }

	double operator^ (const point &p) { return x*p.y - y*p.x; }
	double operator* (const point &p) { return x*p.x + y*p.y; }

	point rotate (double c, double s) {
		return {x*c - y*s, x*s + y*c}; 
	}
	point rotate (double ang) {
		return rotate(cos(ang), sin(ang));
	}

	double len() { return hypot(x, y); }

	bool operator< (const point &p) const {
		return (x < p.x) || (x == p.x && y < p.y);
	}
};

double side(point a, point b, point c) {
	return (a^b) + (b^c) + (c^a);
}

vector<point> convex_hull(vector<point> p) {
	int n = p.size(), k = 0;
	if (n == 1) return p;
	vector<point> hull(2*n);

	sort(p.begin(), p.end());

	for(int i=0; i<n; i++) {
		// use <= when including collinear points
		while(k>=2 && (side(hull[k-2], hull[k-1], p[i]) < 0))
			k--;
		hull[k++] = p[i];
	}

	for(int i=n-2,t=k+1; i>=0; i--) {
		while(k>=t && (side(hull[k-2], hull[k-1], p[i]) < 0))
			k--;
		hull[k++] = p[i];
	}

	hull.resize(k-1);
	return hull;
}
