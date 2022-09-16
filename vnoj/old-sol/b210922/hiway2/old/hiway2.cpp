#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * vars
 * */
#define ll long long
const int N = 5e4+7, M = 1e5+7, I = 2e9+7;
int n, m, src, des;
vector<pair<int, ll>> adj[N];


/**
 * utils
 * */
void rmv(vector<pair<int, ll>> &v, int i) {
	v.erase(
		find_if(v.begin(), v.end(), [&](pair<int, int> j){
			return j.first == i;
		})
	);
}


/**
 * dijkstra
 * */
void rmv_edge(vector<int> &parent, int cr) {
	int p = parent[cr];
	if (p == -1) return;
	rmv(adj[p], cr);
	rmv(adj[cr], p);
}

int getMin(vector<bool> &spt, vector<int> &dist) {
	int minIndex; ll minVal = I+1;
	for (int i = 0; i < n; i++) {
		if (!spt[i] && dist[i] < minVal) {
			minIndex = i;
			minVal = dist[i];
		}
	}
	//
	return minIndex;
}

ll traverse() {
	vector<bool> spt(n, false);
	vector<int> dist(n, I);
	vector<int> parent(n, -1);
	dist[src] = 0;
	//
	for (int i = 0; i < n-1; i++) {
		int u = getMin(spt, dist);
		if (u == des) {
			break;
		}
		//
		spt[u] = true;
		for (pair<int, int> j: adj[u]) {
			int v = j.first; ll l = j.second;
			if (!spt[v]) {
				ll d = dist[u] + l;
				if (d < dist[v]) {
					dist[v] = d;
					parent[v] = u;
				}
			}
		}
	}
	// no way
	if (dist[des] == I) return -1;
	// delete this way
	rmv_edge(parent, des);
	//
	return dist[des];
}


/**
 * drivers
 * */
int main() {
	// inp
	cin >> n >> m >> src >> des; src--; des--;
	for (int i = 0; i < m; i++) {
		int u, v, l; cin >> u >> v >> l; u--; v--;
		adj[u].push_back({v, l});
		adj[v].push_back({u, l});
	}
	// calc
	ll a = traverse(), b = traverse();
	if (a == -1 || b == -1) {
		cout << -1 << endl;
	} else {
		cout << a + b << endl;
	}
	//
	system("pause");
	return 0;
}
