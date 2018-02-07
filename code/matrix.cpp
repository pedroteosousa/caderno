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
	matrix<n> mul (const matrix<n> &a, long long m) const {
		matrix<n> temp;
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				for (int k=0; k<n; k++) {
					temp.mat[i][j] += (mat[i][k]*a.mat[k][j])%m;
					temp.mat[i][j] %= m;
				}
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
			return (temp.mul(temp, m))%m;
		else
			return (((temp.mul(temp, m))%m)*pow(1, m))%m;
	}
};
