// ok let try on a directed one
// only apply on graph that have euler path / circuit
#include <bits/stdc++.h>
using namespace std;

//
int n, m;
vector<int> * adj;
int * in;

// utils
bool dfs(int u, int des, bool * visited) {
	for (int i: adj[u]) {
		if (i == des) return true;
		if (!visited[i]) {
			visited[i] = true;
			if (dfs(i, des, visited)) return true;
		}
	}
	return false;
}

bool is_safe(int u, int v) {
	// if this is an only one
	if (adj[u].size() == 1) return true;
	// or its not a bridge

	// ...ok so just because its a bridge doesn't mean you can burn it
	// directed graphes have some differences
	bool * visited = new bool[n];
	for (int i = 0; i < n; i++) visited[i] = false;
	visited[v] = true;
	// if can return
	return dfs(v, u, visited);
}

//
void euler(int u, vector<int*> &path) {
	for (int i: adj[u]) {
		if (is_safe(u, i)) {
			path.push_back(new int[2]{u, i});
			adj[u].erase(find(adj[u].begin(), adj[u].end(), i));
			in[i] -= 1;
			euler(i, path);
			return;
		}
	}
}

vector<int*> get_euler_path() {
	int u = 0;
	for (int i = 0; i < n; i++) {
		if (adj[i].size() - in[i] == 1) {
			u = i; break;
		}
	}
	// always return euler circuit if possible
	vector<int*> path;
	euler(u, path);
	return path;
}

//
void getinp() {
	ifstream inp("inp.txt");
	inp >> n >> m;
	adj = new vector<int>[n];
	in = new int[n];
	for (int i = 0; i < n; i++) in[i] = 0;
	//
	for (int i = 0; i < m; i++) {
		int a, b; inp >> a >> b;
		adj[a].push_back(b);
		in[b] += 1;
	}
}

int main() {
	getinp();
	for (int * i: get_euler_path()) {
		printf("%d -> %d\n", i[0], i[1]);
	}
	//
	system("pause");
	return 0;
}
