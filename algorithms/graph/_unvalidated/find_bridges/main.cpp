// https://cp-algorithms.com/graph/bridge-searching.html
#include <bits/stdc++.h>
using namespace std;

//
int n, m;
list<int> * adj;

//
void dfs(int u, int parent, int & timer, bool * visited, int * tin, int * low) {
	visited[u] = true;
	tin[u] = low[u] = timer++;				// here
	for (int i: adj[u]) {
		if (i == parent) continue;
		if (visited[i]) {
			low[u] = min(low[u], tin[i]);	// here
		} else {
			dfs(i, u, timer, visited, tin, low);
			low[u] = min(low[u], low[i]);	// here
			if (tin[u] < low[i]) 			// and here
				printf("%d %d\n", u, i);
		}
	}
}

void calc() {
	int timer = 0;
	bool * visited = new bool[n];
	int * tin = new int[n]; 
	int * low = new int[n];
	//
	for (int i = 0; i < n; i++) {
		visited[i] = false;
		tin[i] = -1;
		low[i] = -1;
	}
	//
	for (int i = 0; i < n; i++) {
		if (!visited[i]) dfs(i, -1, timer, visited, tin, low);
	}
	// free memory
	delete[] visited;
	delete[] tin;
	delete[] low;
}

//
void getinp() {
	ifstream inp("inp.txt");
	inp >> n >> m;
	adj = new list<int>[n];
	//
	for (int i = 0; i < m; i++) {
		int a, b; inp >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

int main() {
	getinp();
	calc();
	//
	system("pause");
	return 0;
}
