#include <list>
#include <iostream>
using namespace std;

/**
 * vars
 * */
const int nlim = 1e5+1;
int n, dp[nlim];
// với đồ thị B (làng Buba) là đồ thị liên thông
// có n đỉnh và n-1 cạnh
// --> B là cây
list<int> adj[nlim];

/**
 * perf
 * */


/**
 * drivers
 * */
int main() {
	// inp
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// returns
	cin >> n;
	return 0;
}

