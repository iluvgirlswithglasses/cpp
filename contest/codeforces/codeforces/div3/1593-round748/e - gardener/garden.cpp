
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 17 16:28:48 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 4e5+7, K = 2e5+7;
int n, k, dp[N], lo[N];
vector<int> adj[N];

void init() {
	memset(dp, 0, n * sizeof(dp[0]));
	memset(lo, 0, n * sizeof(lo[0]));
	for (int i = 0; i < n; i++)
		adj[i].clear();
}

int calc() {
	deque<int> q;
	for (int i = 0; i < n; i++)
	if (adj[i].size() == 1) {
		q.push_back(i);
		dp[i] = 1;
	}
	//
	while (q.size()) {
		int u = q.front(); q.pop_front();
		for (int &v: adj[u]) if (dp[v] == 0) {
			if (adj[v].size() - ++lo[v] < 2) {
				dp[v] = dp[u] + 1;
				q.push_back(v);
			}
		}
	}
	return count_if(dp, dp+n, [&](int &i){
		return i > k;
	});
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> k;
		init();
		for (int i = 0; i < n-1; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		cout << calc() << "\n";
	}
	return 0;
}

