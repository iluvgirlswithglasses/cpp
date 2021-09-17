#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

#define ll long long
#define pl pair<ll, ll>
#define st first
#define nd second

const int N = 5007;
const ll I = 2e18;
int n, m;
vector<pl> adj[N];	// adj[i]: {v, l}

ll d[N], c[N];
priority_queue<pl, vector<pl>, greater<pl>> q;	// q[i]: {v, l}

void calc(int src, int des) {
	for (int i = 0; i < n; i++) {
		d[i] = I;
	}
	d[src] = 0;
	c[src] = 1;
	q.push({src, 0});
	// for (int i = 0; i < n-1; i++)
	while (!q.empty()) {
		pl u = q.top(); q.pop();
		if (u.nd > d[u.st]) continue;
		//
		for (pl &v: adj[u.st]) {
			ll len = u.nd + v.nd;
			if (len < d[v.st]) {
				c[v.st] = c[u.st];
				d[v.st] = len;
				q.push({v.st, len});
			} else if (len == d[v.st]) {
				c[v.st] += c[u.st];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll k, u, v, l;
		cin >> k >> u >> v >> l;
		u--; v--;
		//
		adj[u].push_back({v, l});
		if (k == 2) {
			adj[v].push_back({u, l});
		}
	}
	calc(0, n-1);
	cout << d[n-1] << " " << c[n-1] << "\n";
	return 0;
}
