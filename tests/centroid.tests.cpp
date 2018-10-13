#include <bits/stdc++.h>
#include "gtest/gtest.h"
using namespace std;

const int N = 30;
#include "../code/centroid.cpp"

TEST(Simple, Small) {
	int edges[14][2] = {{1, 2}, {3, 2}, {4, 2}, {5, 2}, {5, 6}, {6, 7}, {5, 8}, {8, 9}, {9, 10}, {9, 13}, {13, 14}, {13, 15}, {10, 11}, {10, 12}};
	for (int i=0;i<14;i++) {
		adj[edges[i][0]].push_back(edges[i][1]);
		adj[edges[i][1]].push_back(edges[i][0]);
	}
	build(1);
	vector<int> cent[16] = {{}, {}, {1, 3, 4, 6}, {}, {}, {}, {5, 7}, {}, {2, 9}, {10, 13}, {11, 12}, {}, {}, {14, 15}, {}, {}};
	for (int i=1;i<=15;i++) {
		EXPECT_EQ(cent[i], centroid[i]);
	}
}
