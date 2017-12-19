long long expr(long long n, long long e, long long m) {
    if (!e) return 1ll;
    else {
        long long t = expr(n, e>>1, m);
        if (e & 1) return (n*t*t)%m;
        else return (t*t)%m;
    }
}
