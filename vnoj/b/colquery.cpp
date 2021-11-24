
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Nov 23 17:56:17 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <map>
using namespace std;

/** vars */
#define st first
#define nd second
const int N = 1e5+7;
int n, a[N];

/** dsu */
int p[N];
map<int, int> cnt[N];

void init() {
	for (int i = 0; i < n; i++) {
		cnt[i][ a[i] ] = 1;
		p[i] = i;
	}
}

int find(int u) {
	if (p[u] == u) return u;
	p[u] = find(p[u]);
	return p[u];
}

void merge(int a, int b) {	// b -> a
	p[b] = a;
	for (pair<const int, int> &p: cnt[b]) {
		cnt[a][p.st] += p.nd;
	}
}

bool join(int u, int v) {
	int a = find(u), b = find(v);
	if (a == b) return false;
	if (cnt[b].size() < cnt[a].size()) {
		merge(a, b);
	} else {
		merge(b, a);
	}
	//
	return true;
}

int query(int u, int c) {
	return cnt[ find(u) ][c];
}

/** drivers */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q, t, u, v;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	//
	init();
	while (q--) {
		cin >> t >> u >> v;
		if (t == 1) {
			join(--u, --v);
		} else {
			cout << query(--u, v) << "\n";
		}
	}
	return 0;
}
