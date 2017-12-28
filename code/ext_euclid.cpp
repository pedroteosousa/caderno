// This solves 10104 on UVa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ext(ll a, ll b, ll &x, ll &y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	ll x1, y1;
	ll gcd = ext(b%a, a, x1, y1);

	x = y1 - (b/a)*x1;
	y = x1;

	return gcd;
}

int main() {
	ll a, b;
	while (scanf("%lld %lld", &a, &b) != EOF) {
		ll x, y;
		ll gcd = ext(a, b, x, y);
		if (a == b && x > y) swap(x, y);
		printf("%lld %lld %lld\n", x, y, gcd);	
	}
    return 0;
}

