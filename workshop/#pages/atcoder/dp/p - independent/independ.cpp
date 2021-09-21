
/*
a similar problem, but easier:
ref/party
*/

#include <iostream>
#include <vector>
using namespace std;

#define u64 unsigned long long
#define pi pair<u64, u64>
#define st first
#define nd second
const int N = 1e5+7;
const u64 R = 1e9+7;

int n; 
vector<int> adj[N];

pi dfs(int u, int p) {
	vector<pi> childs;
	for (int &v: adj[u]) if (v != p) {
		pi c = dfs(v, u);
		childs.push_back({
			(c.st + c.nd) % R, c.st
		});
	}
	//
	pi res = {1, 1};
	for (pi &c: childs) {
		res.st = (res.st * c.st) % R;
		res.nd = (res.nd * c.nd) % R;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	pi res = dfs(0, -1);
	cout << ((res.st + res.nd) % R) << "\n";
	return 0;
}
