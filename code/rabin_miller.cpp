long long llrand(long long mn, long long mx) {
	long long p = rand();
	p <<= 32ll;
	p += rand();
	return p%(mx-mn+1ll)+mn;
}

long long mul_mod(long long a, long long b, long long m) {
	long long x = 0, y = a%m;
	while (b) {
		if (b % 2)
			x = (x+y)%m;
		y = (2*y)%m;
		b >>= 1;
	}
	return x%m;
}

long long exp_mod(long long e, long long n, long long m) {
	if (n == 0)
		return 1ll;
	long long temp = exp_mod(e, n/2, m);
	if (n & 1)
		return mul_mod(mul_mod(temp, temp, m), e, m);
	else
		return mul_mod(temp, temp, m);
}

// complexity: O(t*log2^3(p))
bool isProbablyPrime(long long p, long long t=64) {
	if (p <= 1) return false;
	if (p <= 3) return true;
	srand(time(NULL));
	long long r = 0, d = p-1;
	while (d % 2 == 0) {
		r++;
		d >>= 1;
	}
	while (t--) {
		long long a = llrand(2, p-2);
		a = exp_mod(a, d, p);
		if (a == 1 || a == p-1) continue;
		for (int i=0; i<r-1; i++) {
			a = mul_mod(a, a, p);
			if (a == 1) return false;
			if (a == p-1) break;
		}
		if (a != p-1) return false;
	}
	return true;
}
