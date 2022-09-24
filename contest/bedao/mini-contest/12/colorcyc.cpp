
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Sep 23 18:28:12 2022
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

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 2e5+7;
int n, m;
vector<pi> adj[N];	// adj[i]: {adj vertice, edge id}
int color[N];

bool __has_circle(int u, vector<bool> &visited, vector<bool> &internal) {
	if (!visited[u]) {
		visited[u] = internal[u] = true;
		for (pi &p: adj[u])
			if (!visited[p.st] && __has_circle(p.st, visited, internal)) 
				return true;
			else if (internal[p.st]) 
				return true;
	}
	internal[u] = false;
	return false;
}

bool has_circle() {
	vector<bool> visited(n, false);
	vector<bool> internal(n, false);
	for (int i = 0; i < n; i++) if (!visited[i]) {
		if (__has_circle(i, visited, internal)) return true;
	}
	return false;
}

void __dfs(int u, int c, vector<bool> &visited) {
	if (visited[u]) return;
	visited[u] = true;
	for (pi &p: adj[u]) {
		color[p.nd] = c;
		__dfs(p.st, (c+1)%2, visited);
	}
}

void dfs() {
	vector<bool> visited(n, false);
	for (int i = 0; i < n; i++) 
		if (!visited[i]) __dfs(i, 0, visited);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[--u].push_back({--v, i});
	}
	//
	if (m == 0) {
		cout << "0\n";
	} else if (!has_circle()) {
		cout << "1\n";
		for (int i = 0; i < m; i++)
			cout << "1 ";
		cout << "\n";
	} else {
		dfs();
		cout << "2\n";
		for (int i = 0; i < m; i++)
			cout << color[i]+1 << " ";
		cout << "\n";
	}
	return 0;
}
