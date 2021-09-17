#include <bits/stdc++.h>
using namespace std;

// why am I doing this ?
// well
// I want some recursive / backtracking practice since I didn't do it for weeks

//
int n, m;
vector<int> * adj;

// dfs recursion
bool recursion(int u, int cr, list<int> & path, bool * visited) {
	// if traveled to all vertices
	if (path.size() == n) {
		return true;
	}
	//
	for (int i: adj[cr]) {
		if (!visited[i]) {
			path.push_back(i);
			visited[i] = true;
			// backtracking
			if (recursion(cr, i, path, visited)) {
				return true;
			}
			path.pop_back();
			visited[i] = false;
		}
	}
	//
	return false;
}

list<int> recursion(int u) {
	bool * visited = new bool[n];
	for (int i = 0; i < n; i++) visited[i] = false;
	visited[u] = true;
	list<int> path = {u};
	//
	if (recursion(u, u, path, visited)) {
		return path;
	} return list<int>();
}

//
void getinp() {
	ifstream inp("inp.txt");
	inp >> n >> m;
	//
	adj = new vector<int>[n];
	for (int i = 0; i < m; i++) {
		int a, b; inp >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

//
int main() {
	getinp();
	list<int> res = recursion(3);
	if (res.size() > 0) {
		for (int i: res) cout << i << " "; cout << endl;
	} else {
		cout << "impossible" << endl;
	}
	//
	system("pause");
	return 0;
}
