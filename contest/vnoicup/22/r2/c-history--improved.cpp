
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Aug  9 18:32:19 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
an improved version of c-history.cpp
old version: 
	cpp/contest/vnoicup/22/r2/c-history.cpp
	https://oj.vnoi.info/src/1343644
*/

#include <iostream>
#include <vector>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define mk make_pair
#define pi pair<int, int>
#define st first
#define nd second

const int N = 2e5+7;
int n, q, res[N];
vector<pi> adj[N];

struct DSU {
	int p[N];

	void init() {
		for (int i = 0; i <= n; i++) p[i] = i;
	}

	int find(int a) {
		if (a == p[a]) return a;
		return p[a] = find(p[a]);
	}

	bool join(int a, int b) {
		int u = find(a), v = find(b);
		if (u == v) return false;
		if (adj[u].size() < adj[v].size()) swap(u, v);
		// notify every countries linked with this DSU group
		for (pi& p: adj[v]) {
			// because there is no repetitive update
			// so this actually works
			// no need to check like the original submission
			if (u == find(p.nd)) res[p.st]++, res[p.nd]++;
			adj[u].push_back(p);
		}
		p[v] = u;
		return true;
	}
} dsu;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	dsu.init();
	while (q--) {
		int typ, a, b; cin >> typ;
		switch (typ) {
			case 1: {
				cin >> a >> b;
				dsu.join(a, b);
				break;
			}
			case 2: {
				cin >> a >> b;
				int u = dsu.find(a), v = dsu.find(b);
				if (u == v) {
					res[a]++;
					res[b]++;
				} else {
					adj[u].push_back(mk(a, b));
					adj[v].push_back(mk(b, a));
				}
				break;
			}
			case 3: {
				cin >> a;
				cout << res[a] << "\n";
				break;
			}
		}
	}
	return 0;
}
