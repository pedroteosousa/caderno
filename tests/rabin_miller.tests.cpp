#include <bits/stdc++.h>
#include "gtest/gtest.h"
using namespace std;

const int N = 1e5;
#include "../code/rabin_miller.cpp"

TEST(Simple, Small) {
	for (int p : {2,3,5,7,11,13,19,292911197,1000000007,1000000009}) {
		EXPECT_EQ(isProbablyPrime(p), true);
	}
	for (int p : {1,4,10,21,278,1000000011}) {
		EXPECT_EQ(isProbablyPrime(p), false);
	}
}
