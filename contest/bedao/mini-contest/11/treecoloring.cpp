
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Sep  2 10:59:32 2022
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
#define pi pair<int, int>
#define st first
#define nd second
const int N = 1e5+7;
int n;
bool s[N];	// s[i]: the color of node `i`
vector<pi> adj[N];

void dfs(int u, int p, int c) {
	s[u] = c;
	for (pi &a: adj[u]) if (a.st != p) {
		// switch the state of `c` if the edge's weight is odd, 
		// keep it otherwise
		dfs(a.st, u, (a.nd&1)^c);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0, u, v, w; i < n-1; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	//
	dfs(1, 0, 0);
	for (int i = 1; i <= n; i++)
		cout << s[i] << " ";
	cout << "\n";
	return 0;
}
