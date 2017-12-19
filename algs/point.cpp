#include <bits/stdc++.h>

using namespace std;

double EPS = 1e-12;

struct point {
    double x, y;
    point(double xp = 0.0, double yp = 0.0) {
        x = xp;
        y = yp;
    }
    point(const point &p) {
        x = p.x;
        y = p.y;
    }
    point operator+ (const point &p) const {return point(x+p.x, y+p.y);}
    point operator- (const point &p) const {return point(x-p.x, y-p.y);}
    point operator* (double c) {return point(c*x, c*y);}
    point operator/ (double c) {return point(x/c, y/c);}

    bool operator<(const point &p) {return x < p.x || x == p.x && y < p.y;}
};

double dot(point p, point q) {return p.x*q.x+p.y*q.y;}
double dist(point p, point q) {return sqrt(dot(p-q,p-q));}
double cross(point p, point q) {return p.x*q.y-p.y*q.x;}

point projectInLine(point c, point a, point b) {return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);}
point projectInSegment(point c, point a, point b) {
    point lineP = projectInLine(c, a, b);
    double maxDist = max(dist(a, lineP), dist(b, lineP));
    if (maxDist > dist(a, b)) {
        if (dist(a, c) > dist(b, c)) return b;
        else return a;
    }
    else return lineP;
}

vector<point> convex_hull(vector<point> p) {
    int n = p.size(), k = 0;
    if (n == 1) return p;
    vector<point> hull(2*n);

    sort(p.begin(), p.end());

    for(int i=0; i<n; i++) {
        while(k>=2 && (cross(hull[k-2], hull[k-1]) + cross(hull[k-1], p[i]) + cross(p[i], hull[k-2]) <= 0)) k--;
        hull[k++] = p[i];
    }

    for(int i=n-2,t=k+1; i>=0; i--) {
        while(k>=t && (cross(hull[k-2], hull[k-1]) + cross(hull[k-1], p[i]) + cross(p[i], hull[k-2]) <= 0)) k--;
        hull[k++] = p[i];
    }

    hull.resize(k-1);
    return hull;
}


int main() {
    point a = point(0, 0);
    point b = point(1, 1);
    point c = point(1, 0);
    point d = point(0, 1);
    point e = point(0.5, 0.5);
    vector<point> h;
    h.push_back(a);
    h.push_back(b);
    h.push_back(c);
    h.push_back(d);
    h.push_back(e);
    h = convex_hull(h);
    for(int i=0;i<h.size(); i++) {
        printf("%lf %lf\n", h[i].x, h[i].y);
    }
    return 0;
}

