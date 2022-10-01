
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct  1 15:48:51 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5+7;
int n, q, cnt[N];
vector<int> adj[N];

int dfs(int u) {
	if (adj[u].size() == 0) 
		return 1;
	for (int v: adj[u])
		cnt[u] += dfs(v);
	return cnt[u] + 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[--u].push_back(--v);
	}
	dfs(0);
	while (q--) {
		int u; cin >> u;
		cout << cnt[u-1] << "\n";
	}
	return 0;
}
