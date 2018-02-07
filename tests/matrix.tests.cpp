#include <bits/stdc++.h>
#include "gtest/gtest.h"
using namespace std;

const int N = 1e4;
#include "../code/matrix.cpp"

typedef long long ll;

TEST(Simple, Small) {
	matrix<100> m;
	for (int i=0;i<100;i++)
		for (int j=0;j<100;j++)
			m.mat[i][j] = 1e9;

	ll cmod = 1e9+7;
	m = (m.mul(m, cmod))%cmod;
	for (int i=0;i<100;i++)
		for (int j=0;j<100;j++)
			EXPECT_EQ(m.mat[i][j], 4900);
}
