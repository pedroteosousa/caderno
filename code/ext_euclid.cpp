// This solves 10104 on UVa
#include <bits/stdc++.h>
using namespace std;

long long ext(long long a, long long b, long long &x, long long &y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	long long x1, y1;
	long long gcd = ext(b%a, a, x1, y1);

	x = y1 - (b/a)*x1;
	y = x1;

	return gcd;
}

int main() {
	long long a, b;
	while (scanf("%lld %lld", &a, &b) != EOF) {
		long long x, y;
		long long gcd = ext(a, b, x, y);
		if (a == b && x > y) swap(x, y);
		printf("%lld %lld %lld\n", x, y, gcd);	
	}
    return 0;
}

