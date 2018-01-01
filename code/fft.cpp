// This solves VFMUL on SPOJ
#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265359

const int N = 3e5 + 5;
typedef complex<double> base;

// p[0]*x^0 + p[1]*x + ...
void fft(vector<base> &p, bool inverse) {
	if (p.size() == 1)
		return;
	int n = p.size();

	vector<base> a[2];
	for (int i=0; i<n; i++) 
		a[i%2].push_back(p[i]);
	
	for (int i=0; i<2; i++)
		fft(a[i], inverse);

	double theta = (2*PI/n)*(inverse ? -1 : 1);
	base w(1), wn(cos(theta), sin(theta));
	for (int i=0; i<n/2; i++) {
		p[i] = (a[0][i] + w * a[1][i]) / (base)(inverse ? 2 : 1);
		p[i+n/2] = (a[0][i] - w * a[1][i]) / (base)(inverse ? 2 : 1);
		w *= wn;
	}
}

// c ends being a*b
void multiply(vector<int> &a, vector<int> &b, vector<int> &c) {
	vector<base> na(a.begin(), a.end()), nb(b.begin(), b.end());
	int n = 1;
	while (n < max(a.size(), b.size())) n <<= 1;
	n <<= 1;
	na.resize(n); nb.resize(n);
	
	fft(na, false); fft(nb, false);
	for (int i=0;i<n;i++) {
		na[i] *= nb[i];	
	}
	fft(na, true);
	
	c.resize(n);
	for (int i=0;i<n;i++)
		c[i] = (int)(na[i].real() + 0.5);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		char s1[N], s2[N];
		scanf("%s %s", s1, s2);
		int n1 = strlen(s1), n2 = strlen(s2);
		vector<int> a, b, c;

		for (int i=n1-1;i>=0;i--)
			a.push_back(s1[i]-'0');
		for (int i=n2-1;i>=0;i--)
			b.push_back(s2[i]-'0');
		multiply(a, b, c);
		
		c.resize(2*c.size());
		for (int i=0;i<c.size()-1;i++) {
			c[i+1] += c[i]/10;
			c[i] %= 10;
		}

		int found = 0;
		for (int i=c.size()-1;i>=0; i--) {
			if (c[i] != 0) found = 1;
			if (found) printf("%c", c[i] + '0');
		}
		if (!found) printf("0");
		printf("\n");
	}
    return 0;
}

