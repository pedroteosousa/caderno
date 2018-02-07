#include <bits/stdc++.h>
#include "gtest/gtest.h"
using namespace std;

const int N = 1e4, A = 30;
#include "../code/trie.cpp"

TEST(Simple, Small) {
	trie t;
	t.init();
	char p[N];
	for (string s : {"alo", "alou", "alou", "aloha", "haha"}) {
		strcpy(p, s.c_str());
		t.insert(p);
	}
	strcpy(p, "alo");
	EXPECT_EQ(t.count(p), 4);
	strcpy(p, "alou");
	EXPECT_EQ(t.count(p), 2);
	strcpy(p, "alou");
	EXPECT_EQ(t.find(p), 2);
	strcpy(p, "hah");
	EXPECT_EQ(t.find(p), 0);
	strcpy(p, "alou");
	t.erase(p);
	EXPECT_EQ(t.find(p), 1);
	t.erase(p);
	EXPECT_EQ(t.find(p), 0);
	t.erase(p);
	EXPECT_EQ(t.find(p), 0);
}
