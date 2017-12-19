const int N = 1e6 + 5;

int p[N];
int w[N];

int find(int x) {
	return p[x] = x==p[x]?x:find(p[x]);
}

void join(int a, int b) {
	if ((a = find(a)) == (b = find(b))) return;
	if (w[a] < w[b]) swap(a, b);
	w[a] += w[b];
	p[b] = a;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++) {
		p[i] = i;
		w[i] = 1;
	} 
	return 0;
}

