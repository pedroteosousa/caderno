#include <bits/stdc++.h>
using namespace std;

typedef double type;
double EPS = 1e-12;

struct point {
    type x, y;
    point(type xp = 0.0, type yp = 0.0) {
        x = xp;
        y = yp;
    }
    point(const point &p) {
        x = p.x;
        y = p.y;
    }
    point operator+ (const point &p) const { return point(x+p.x, y+p.y); }
    point operator- (const point &p) const { return point(x-p.x, y-p.y); }
    point operator* (type c) { return point(c*x, c*y); }
    point operator/ (type c) { return point(x/c, y/c); }

    bool operator<(const point &p) { return x < p.x || x == p.x && y < p.y;}
};

type dot(point p, point q)  { return p.x*q.x+p.y*q.y; }
type dist(point p, point q)  { return sqrt(dot(p-q,p-q)); }
type cross(point p, point q)  { return p.x*q.y-p.y*q.x; }

point projectInLine(point c, point a, point b) { return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a); }

point projectInSegment(point c, point a, point b) {
    point lineP = projectInLine(c, a, b);
    type maxDist = max(dist(a, lineP), dist(b, lineP));
    if (maxDist > dist(a, b)) {
        if (dist(a, c) > dist(b, c)) return b;
        else return a;
    }
    else return lineP;
}

int main() {
	point a(0, 0), b(1, 1), c(1, 0);
	c = projectInSegment(c, a, b);
	printf("%lf %lf\n", c.x, c.y);
}
