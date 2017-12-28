// This solves problem MAIN74 on SPOJ
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

template <int n> struct matrix {
	long long mat[n][n];
	matrix () {
		memset (mat, 0, sizeof (mat));
	}
	matrix (long long temp[n][n]) {
		memcpy (mat, temp, sizeof (mat));
	}
	void identity() {
		memset (mat, 0, sizeof (mat));
		for (int i=0;i<n;i++)
			mat[i][i] = 1;
	}
	matrix<n> operator* (const matrix<n> &a) const {
		matrix<n> temp;
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				for (int k=0; k<n; k++)
					temp.mat[i][j] += mat[i][k]*a.mat[k][j];
		return temp;
	}
	matrix<n> operator% (long long m) {
		matrix<n> temp(mat);
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				temp.mat[i][j] %= m;
		return temp;
	}
	matrix<n> pow(long long e, long long m) {
		matrix<n> temp;
		if (e == 0) {
			temp.identity();
			return temp%m;
		}
		if (e == 1) {
			memcpy (temp.mat, mat, sizeof (temp.mat));
			return temp%m;
		}
		temp = pow(e/2, m);
		if (e % 2 == 0)
			return (temp*temp)%m;
		else
			return (((temp*temp)%m)*pow(1, m))%m;
	}
};

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		long long n;
		scanf("%lld", &n);
		matrix<2> m;
		memcpy (m.mat, (const long long [][2]){{1, 1}, {1, 0}}, sizeof (m.mat));
		m = m.pow(n+2, mod);
		if (n == 0) m.mat[0][0] = 0;
		if (n == 1) m.mat[0][0] = 2;
		printf("%lld\n", m.mat[0][0]);
	}
    return 0;
}

