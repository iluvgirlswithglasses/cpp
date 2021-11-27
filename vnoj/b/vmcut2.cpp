
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 27 22:37:26 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// whenever I include this
// it's mean I'm serious af
#include <bits/stdc++.h>
using namespace std;

/**
 * @defs
 * */
const int N = 1e5+7, I = 1e9+7;

struct pack {
	int weight, cut;

	pack(int w, int c) {
		weight = w;
		cut = c;
	}

	bool operator < (const pack& p) const {
		return weight < p.weight;
	}
};

/**
 * @vars
 * */
int n, k, w[N];
vector<int> adj[N];

/**
 * @perf
 * */
pack dfs(int u, int p, int m) {
	// if this' a leaf
	if (p != -1 && adj[u].size() == 1) {
		return pack(w[u], 0);
	}
	//
	set<pack> child;
	for (int v: adj[u]) if (v != p) {
		child.insert(dfs(v, u, m));
	}
	//
	pack res(w[u], 0);
	for (pack i: child) {
		res.cut += i.cut;
		if (res.weight + i.weight <= m) {
			res.weight += i.weight;
		} else {
			// kiểu gì cũng phải cắt
			// thà cắt cành nhỏ,
			// vớt đc bao nhiêu thì vớt
			res.cut++;
		}
	}
	//
	return res;
}

/**
 * @drivers
 * */
bool valid(int m) {
	return dfs(0, -1, m).cut <= k;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> w[i];
	for (int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	//
	int l = *max_element(w, w+n), r = I;
	while (l < r) {
		int m = (l + r) >> 1;
		if (valid(m)) {
			r = m;		// hạ được thì hạ xuống
		} else {
			l = m+1;	// không được thì vớt lên
		}
	}
	cout << r << "\n";
	return 0;
}
