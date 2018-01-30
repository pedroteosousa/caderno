double EPS = 1e-8;

struct point {
    double x, y;
    
	point (double xp = 0, double yp = 0) { x = xp; y = yp;}
    point (const point &p) { x = p.x; y = p.y; }

    point operator+ (const point &p) const { return point(x+p.x, y+p.y); }
    point operator- (const point &p) const { return point(x-p.x, y-p.y); }
    point operator* (double c) const { return point(c*x, c*y); }
    point operator/ (double c) const { return point(x/c, y/c); }

	double operator* (const point &p) const { return x*p.x+y*p.y; }
	double operator^ (const point &p) const { return x*p.y-y*p.x; }
	
	double len () const { return hypot(x, y); }
    
	bool operator< (const point &p) {
		return x < p.x || x == p.x && y < p.y;
	}
};
