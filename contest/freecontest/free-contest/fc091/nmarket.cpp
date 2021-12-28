
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Dec 28 19:17:45 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

/*
loang từ tiệm -> nhà
*/

const int N = 1e6+7;
int n, m, k;
vector<int> adj[N];

deque<int> q;
bool visited[N];
int dist[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	memset(dist, -1, n*sizeof(dist[0]));
	for (int i = 0; i < k; i++) {
		int a; cin >> a;
		q.push_back(--a);
		visited[a] = true;
		dist[a] = 0;
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[v-1].push_back(u-1);	// loang ngược từ tiệm -> nhà
	}
	// bfs
	while (q.size()) {
		int u = q.front(); q.pop_front();
		for (int v: adj[u]) if (!visited[v]) {
			visited[v] = true;
			dist[v] = dist[u] + 1;
			q.push_back(v);
		}
	}
	//
	for (int i = 0; i < n; i++)
		cout << dist[i] << "\n";
	return 0;
}
