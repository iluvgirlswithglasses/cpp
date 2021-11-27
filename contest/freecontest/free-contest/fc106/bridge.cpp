
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 27 12:12:32 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * defs
 * */
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second
const int N = 2e5+7;

/**
 * dsu
 * */
struct DSU {
	// s[i]: vertices in group `i`
	int p[N], s[N];

	DSU(int n) {
		for (int i = 0; i < n; i++) {
			p[i] = i;
			s[i] = 1;
		}
	}

	int find(int u) {
		if (p[u] == u) return u;
		p[u] = find(p[u]);
		return p[u];
	}

	ll join(int u, int v) {
		int a = find(u), b = find(v);
		if (a == b) return 0;
		ll conn = (ll) s[a] * s[b];
		p[a] = b;
		s[b] += s[a];
		return conn;
	}
};

/**
 * drivers
 * */
int n, m, u, v;
ll  base, cr;
stack<ll> res;
pi edge[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	base = cr = ((ll) n * (n - 1)) >> 1;
	res.push(base);
	DSU dsu(n);
	//
	//
	for (int i = 0; i < m; i++) {
		cin >> edge[i].st >> edge[i].nd;
	}
	for (int i = m-1; i > 0; i--) {
		cr -= dsu.join(edge[i].st - 1, edge[i].nd - 1);
		res.push(cr);
	}
	//
	while (res.size()) {
		cout << res.top() << "\n";
		res.pop();
	}
	return 0;
}
