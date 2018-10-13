struct point {
    coord x, y;
    point(): x(0), y(0) {}
    point(coord a, coord b): x(a), y(b) {}

    inline point operator+ (point o) { return {x + o.x, y + o.y}; }
    inline point operator- (point o) { return {x - o.x, y - o.y}; }
    inline point operator* (coord o) { return {x * o, y * o}; }
    inline point operator/ (coord o) { return {x / o, y / o}; }

    inline coord operator* (point o) { return x * o.x + y * o.y; }
    inline coord operator^ (point o) { return x * o.y - y * o.x; }
    
    inline bool operator< (point o) { return make_pair(x, y) < make_pair(o.x, o.y); }

    inline bool operator== (point o) { return abs(x-o.x) < eps && abs(y-o.y) < eps; }

    // cw angle
    inline double ang(point o) {
        point p = *this;
        return atan2(-(p ^ o), p * o);
    }

    inline coord sqr() { return x * x + y * y; }
    inline double len() { return sqrt(sqr()); }

    // rotate cw
    inline point rot90() { return {y, -x}; }
    inline point rotate(double a) { return {cos(a)*x + sin(a)*y, -sin(a)*x + cos(a)*y}; }

    inline int ccw(point o) { coord a = (*this) ^ o; return (eps < a) - (a < -eps); }
    inline int dir(point o) { coord a = (*this) * o; return (eps < a) - (a < -eps); }

    bool in_seg(point a, point b) {
        point p = *this;
        return (p-a).ccw(b-a) == 0 && (p-a).dir(p-b) <= 0;
    }
    double dist_line(point a, point b) {
        point p = *this;
        return (b-a).sqr() <= eps ? (p-a).sqr() : double(abs((a-p) ^ (b-p))) / (b-a).len();
    }
    double dist_seg(point a, point b) {
        point p = *this;
        return (p-a).dir(p-b) <= 0 ? dist_line(a, b) : min((p-a).len(), (p-b).len());
    }
};

struct line {
    point p; coord c;
    line() {}
    line(point s, point e): p((s-e).rot90()), c(p*s) {}
    point inter(line o) {
        if (p.ccw(o.p) == 0) throw 1;
        coord d = (p ^ o.p);
        return point((c * o.p.y - p.y * o.c) / d, (o.c * p.x - o.p.x * c) / d);
    }
};

bool inter_seg(point a, point b, point c, point d) {
    if (a.in_seg(c, d) || b.in_seg(c, d) || c.in_seg(a, b) || d.in_seg(a, b)) return true;
    return ((c-a).ccw(b-a) * (d-a).ccw(b-a) == -1 && (a-c).ccw(d-c) * (b-c).ccw(d-c) == -1);
}