int kmp[N];

void build(const char *s) {
	int n = strlen(s), k = -1;
	kmp[0] = k;
	for (int i = 1; i < n+1; i++) {
		while (k >= 0 && s[k] != s[i-1]) k = kmp[k];
		kmp[i] = ++k;
	}
}

vector<int> match(const char *p, const char *s) {
	int n = strlen(s), m = strlen(p), j = 0;
	vector<int> matches;
	for (int i = 1; i < n+1; i++) {
		while (j >= 0 && p[j] != s[i]) j = kmp[j];
		if (++j == m) {
			matches.push_back(i-j+1);
			j = kmp[j];
		}
	}
	return matches;
}
