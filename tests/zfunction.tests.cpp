#include <bits/stdc++.h>
#include "gtest/gtest.h"
using namespace std;

const int N = 1e5;
#include "../code/zfunction.cpp"

void brutao(string s) {
	Z(s);
	for (int i = 1; i < (int)s.size(); i++) {
		int match = 0;
		while (i + match < (int)s.size() && s[i + match] == s[match]) match++;
		EXPECT_EQ(z[i], match);
	}
}

TEST(Simple, Random) {
	int num_tests = 10, alf = 26, n = 10000;
	while (num_tests--) {
		string s;
		while ((int)s.size() < n) {
			s.push_back('a' + (rand()%alf));
		}
		brutao(s);
	}
}
