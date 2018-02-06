int kmp[N];

void build(string p) {
	int n = p.size(), k = -1;
	kmp[0] = k;
	for (int i = 1; i < n+1; i++) {
		while (k >= 0 && p[k] != p[i-1]) k = kmp[k];
		kmp[i] = ++k;
	}
}

vector<int> match(string p, string s) {
	int n = s.size(), m = p.size(), j = 0;
	vector<int> matches;
	for (int i = 1; i < n+1; i++) {
		while (j >= 0 && p[j] != s[i-1]) j = kmp[j];
		if (++j == m) {
			matches.push_back(i-j+1);
			j = kmp[j];
		}
	}
	return matches;
}
