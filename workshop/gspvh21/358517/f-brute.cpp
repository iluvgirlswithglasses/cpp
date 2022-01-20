
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Jan 20 09:14:53 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long

const int N = 42;
int n;
ll res;
vector<int> narr;
vector<int> nto;
vector<vector<int>> adj;

ll bfs(int i) {
	ll dist = 0;
	deque<int> q;
	deque<int> d;
	//
	q.push_back(i);
	d.push_back(0);
	vector<bool> visited(n, false);
	visited[i] = true;
	//
	while (q.size()) {
		int u = q.front(); q.pop_front();
		int x = d.front(); d.pop_front();
		for (int v: adj[u]) if (!visited[v]) {
			visited[v] = true;
			q.push_back(v);
			d.push_back(x+1);
			dist += x+1;
		}
	}
	return dist;
}

ll bfs() {
	ll res = 0;
	for (int i = 0; i < n; i++)
		res += bfs(i);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("3cay.inp", "r", stdin);
	freopen("3cay.out", "w", stdout);
	//
	int t; cin >> t;
	while (t--) {
		// init
		n = 0;
		res = 0;
		adj.assign(N, vector<int>());
		narr.resize(3);
		nto.resize(4);

		// inp
		for (int i = 0; i < 3; i++) {
			cin >> narr[i];
			for (int j = 1; j < narr[i]; j++) {
				int u, v;
				cin >> u >> v;
				adj[--u + n].push_back(--v + n);
				adj[v+n].push_back(u+n);
			}
			n += narr[i];
			nto[i+1] = n;
		}

		// chọn trung gian
		for (int mid = 0; mid < 3; mid++) {
			// nối với cây kề 1
			for (int u = nto[mid]; u < nto[mid+1]; u++)
			for (int v = nto[(mid+1)%3]; v < nto[((mid+1)%3) + 1]; v++)
			// nối với cây kề 2
			for (int x = nto[mid]; x < nto[mid+1]; x++)
			for (int y = nto[(mid+2)%3]; y < nto[((mid+2)%3) + 1]; y++) {
				adj[u].push_back(v);
				adj[v].push_back(u);
				adj[x].push_back(y);
				adj[y].push_back(x);
				//
				res = max(res, bfs());
				//
				adj[u].pop_back();
				adj[v].pop_back();
				adj[x].pop_back();
				adj[y].pop_back();
			}
		}
		//
		cout << (res>>1) << "\n";
	}
	return 0;
}
