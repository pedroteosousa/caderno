struct trie {
	struct node {
		int to[A], freq, end;
	};
	struct node t[N];
	int sz = 0;
	int offset = 'a';
	
	// init trie
	void init() {
		memset(t, 0, sizeof(struct node));
	}
	
	// insert string
	void insert(char *s, int p = 0) {
		t[p].freq++;
		if (*s == 0) {
			t[p].end++;
			return;
		}
		if (t[p].to[*s - offset] == 0)
			t[p].to[*s - offset] = ++sz;
		insert(s+1, t[p].to[*s - offset]);
	}

	// check if string is on trie
	int find(char *s, int p = 0) {
		if (*s == 0)
			return t[p].end;
		if (t[p].to[*s - offset] == 0)
			return false;
		return find(s+1, t[p].to[*s - offset]);
	}
	
	// count the number of strings that have this prefix
	int count(char *s, int p = 0) {
		if (*s == 0)
			return t[p].freq;
		if (t[p].to[*s - offset] == 0)
			return 0;
		return count(s+1, t[p].to[*s - offset]);
	}

	// erase a string
	int erase(char *s, int p = 0) {
		if (*s == 0 && t[p].end) {
			--t[p].end;
			return --t[p].freq;
		}
		if ((*s == 0 && t[p].end == 0) || t[p].to[*s - offset] == 0)
			return -1;
		int count = erase(s+1, t[p].to[*s - offset]);
		if (count == 0)
			t[p].to[*s - offset] = 0;
		if (count == -1)
			return -1;
		return --t[p].freq;
	}
};
