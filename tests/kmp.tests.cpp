#include <bits/stdc++.h>
#include "gtest/gtest.h"
using namespace std;

const int N = 1e5;
#include "../code/kmp.cpp"

void brutao(string p, string s) {
	build(p);
	vector<int> matches = match(p, s), matches_brutao;
	for (int i = 0; i < (int)s.size(); i++) {
		bool match = true;
		for (int j = 0; j < (int)p.size() && i+j < (int)s.size(); j++) {
			if (p[j] != s[i+j]) match = false;
			if (j+1 == (int)p.size() && match)
				matches_brutao.push_back(i+1);				
		}
	}
	EXPECT_EQ((int)matches_brutao.size(), (int)matches.size());
	for (int i=0;i<(int)matches.size();i++) {
		EXPECT_EQ(matches[i], matches_brutao[i]);
	}
}

TEST(Simple, Small) {
	brutao("o ", "say hello to my little friend");
	brutao("aba", "abacaba");
	brutao("a", "aaaaaaaaaaaaaaaaaaaaaaaaaaa");
	brutao("b", "aaaaaaaaaaaaaaaaaaaaaaaaaaa");
}

TEST(Simple, Random) {
	int num_tests = 10, alf = 26, n = 1000, m = 100;
	while (num_tests--) {
		string s, p;
		while ((int)s.size() < n) {
			s.push_back('a' + (rand()%alf));
		}
		while ((int)p.size() < m) {
			p.push_back('a' + (rand()%alf));
		}
		brutao(p, s);
	}
}
