long long expr(long long e, long long n) {
    if (!e) return 1ll;
    return (((n & 1) ? e : 1) * expr((e * e) % mod, n / 2)) % mod;
}