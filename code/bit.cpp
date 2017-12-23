int b[N];

int update(int p, int val, int n) {
	for(;p < n; p += p & -p) b[p] += val;
}

int getsum(int p) {
	int sum = 0;
	for(; p != 0; p -= p & -p) {
		sum += b[p];
	}
	return sum;
}
