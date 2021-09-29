#include <iostream>
#include <vector>
using namespace std;

#define pi pair<int, int>
#define st first
#define nd second

const int N = 2e5+7;
int n;
vector<pi> adj[N];

int calc() {
	int res = -1;
	return 1 + res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		//
		for (int u = 0, k; u < n; u++) {
			cin >> k;
			adj[u].resize(k);
			//
			for (int i = 0, v; i < k; i++) {
				cin >> v;
				adj[u][i] = {v, u > v ? 0: 1};
			}
		}
		cout << calc() << "\n";
	}
	return 0;
}
