double side(point a, point b, point c) {
    return cross(a, b) + cross(b, c) + cross(c, a);
}

vector<point> convex_hull(vector<point> p) {
    int n = p.size(), k = 0;
    if (n == 1) return p;
    vector<point> hull(2*n);

    sort(p.begin(), p.end());

    for(int i=0; i<n; i++) {
        while(k>=2 && (side(hull[k-2], hull[k-1], p[i]) <= 0)) k--;
        hull[k++] = p[i];
    }

    for(int i=n-2,t=k+1; i>=0; i--) {
        while(k>=t && (side(hull[k-2], hull[k-1], p[i]) <= 0)) k--;
        hull[k++] = p[i];
    }

    hull.resize(k-1);
    return hull;
}