
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Aug 21 22:41:16 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// if the problem only asks to print one vertice only

#include <iostream>
#include <vector>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 1e6+7;
int n, c[N];
vector<int> adj[N];

bool flag = false;	// flag == true --> a vertice has been cut
int res = 0;

bool dfs(int u, int p, bool cut) {
	// if this vertice was cut & doesn't care about the world anymore
	if (cut) {
		for (int i: adj[u]) if (i != p) {
			if (!dfs(i, u, false)) return false;
		}
		return true;
	}
	// branches that have different colors
	vector<int> s;
	// visit branches with the same color first
	for (int i: adj[u]) if (i != p) {
		if (c[i] == c[u]) {
			if (!dfs(i, u, false)) return false;
		} else {
			// other branches are stored in `s[]`
			s.push_back(i);
		}
	}
	// must cut but can not cut
	if (s.size() && flag)
		return false;
	// must cut and can cut
	bool cut_next = false;
	if (s.size()) {
		flag = true;
		// if s.size() == 1 --> cut the first vertice of the other branch
		if (s.size() == 1) 
			res = s[0], cut_next = true;
		// if s.size() >  1 --> must cut this vertice
		else if (s.size() > 1)
			res = u, cut_next = false;
	}
	// visit the branches with different colors
	for (int i: s) {
		if (!dfs(i, u, cut_next)) return false;
	}
	// dfs through all vertices with the given condition --> return true
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	//
	if (dfs(1, 0, false)) {
		cout << "YES\n" << res << "\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}
