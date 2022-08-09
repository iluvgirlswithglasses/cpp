
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Aug  8 16:56:14 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 2e5+7;
int n, q;
/*
adj[i]: 
list of countries that have signed the contrast with `i`
but haven't visited `i` yet
*/
set<int> adj[N];
/*
cache[i]:
number of countries that have signed the contrast with `i`
and have visited `i` at least 1
*/
int cache[N];

struct DSU {
	int p[N];

	void init() {
		for (int i = 0; i <= n; i++)
			p[i] = i;
	}

	bool join(int a, int b) {
		int u = find(a), v = find(b);
		if (u == v) return false;
		p[u] = v;
		return true;
	}

	int find(int a) {
		if (a == p[a]) return a;
		p[a] = find(p[a]);
		return p[a];
	}
} dsu;

void open_airline(int a, int b) {
	dsu.join(a, b);
}

void open_contract(int a, int b) {
	adj[a].insert(b);
	adj[b].insert(a);
}

int query(int u) {
	vector<set<int>::iterator> new_entries;
	for (set<int>::iterator i = adj[u].begin(); i != adj[u].end(); i++) {
		if (dsu.find(*i) == dsu.find(u)) {
			new_entries.push_back(i);
		}
	}
	//
	cache[u] += new_entries.size();
	for (set<int>::iterator i: new_entries) {
		cache[*i]++;
		adj[u].erase(i);
		adj[*i].erase(u);
	}
	return cache[u];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	dsu.init();
	while (q--) {
		int typ, a, b; cin >> typ;
		switch (typ) {
			// there is no repetitive update request
			case 1:
				cin >> a >> b;
				open_airline(a, b);
				break;
			case 2:
				cin >> a >> b;
				open_contract(a, b);
				break;
			case 3:
				cin >> a;
				cout << query(a) << "\n";
				break;
		}
	}
	return 0;
}
