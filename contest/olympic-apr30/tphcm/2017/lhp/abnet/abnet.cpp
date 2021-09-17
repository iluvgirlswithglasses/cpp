#include <bits/stdc++.h>
using namespace std;

// so, this is a little reminder
// in c++...
// ...BLOCK VARIABLE DOES NOT OVERIDE GLOBAL VARIABLE
// this took me 20 MIN TO FIGURE IT OUT
// WHAT THE FK

//
int n, m, ac, bc;
int * aa;	// array of a
int * ab;	// array of b
vector<int> * adj;
//
list<int*> bridges;

// utils
void rmv(int a, int b) {
	adj[a].erase(
		find(adj[a].begin(), adj[a].end(), b)
	);
}

bool is_include(int * arr, int len, int v) {
	// if include => return 1; otherwise 0;
	return find(arr, arr + len, v) != arr + len;
}

void dfs(int u, bool * visited, int & lac, int & lbc) {
	visited[u] = true;
	lac += is_include(aa, ac, u);
	lbc += is_include(ab, bc, u);
	//
	for (int i: adj[u]) {
		if (visited[i]) continue;
		dfs(i, visited, lac, lbc);
	}
}

int * dfs(int u) {
	bool * visited = new bool[n];
	for (int i = 0; i < n; i++) visited[i] = false;
	int lac = 0, lbc = 0;
	//
	dfs(u, visited, lac, lbc);
	return new int[2]{lac, lbc};
}

//
void calc() {
	int typ0 = 0;
	int typ1 = 0;
	for (int * e: bridges) {
		int u = e[0], v = e[1];
		rmv(u, v); rmv(v, u);
		//
		for (int i = 0; i < n; i++) {
			bool canBreak = false;
			int * counts = dfs(i);
			if (counts[0] == 0 || counts[1] == 0) {
				typ0 += 1;
				// printf("%d %d typ0, at %d\n", u, v, i);
				canBreak = true;
			}
			if (counts[0] < (double) ac / 2.0 || counts[1] < (double) bc / 2.0) {
				typ1 += 1;
				// printf("%d %d typ1, at %d\n", u, v, i);
				canBreak = true;
			}
			if (canBreak) break;
		}
		//
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	printf("%d %d\n", typ0, typ1);
}

// that O(V + E) bridges finding algorithm
void get_bridges(int u, int p, int & timer, bool * visited, int * tin, int * low) {
	visited[u] = true;
	low[u] = tin[u] = timer++;
	for (int i: adj[u]) {
		if (i == p) continue;
		if (visited[i]) {
			low[u] = min(low[u], tin[i]);
		} else {
			get_bridges(i, u, timer, visited, tin, low);
			low[u] = min(low[u], low[i]);
			if (low[i] > tin[u]) {
				bridges.push_back(new int[2]{i, u});
			}
		}
	}
}

void get_bridges() {
	bool * visited = new bool[n];
	int * tin = new int[n];
	int * low = new int[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
		tin[i] = -1;
		low[i] = -1;
	}
	int timer = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) get_bridges(i, -1, timer, visited, tin, low);
	}
}

//
void getinp() {
	ifstream inp("abnet.inp");
	inp >> n >> m >> ac >> bc;
	//
	adj = new vector<int>[n];
	aa = new int[ac];
	ab = new int[bc];
	//
	for (int i = 0; i < ac; i++) {
		int k; inp >> k; k -= 1; aa[i] = k;
	} for (int i = 0; i < bc; i++) {
		int k; inp >> k; k -= 1; ab[i] = k;
	}
	//
	for (int i = 0; i < m; i++) {
		int k, l; inp >> k >> l; k -= 1; l -=1;
		adj[k].push_back(l);
		adj[l].push_back(k);
	}
}

// debugs
void printadj() {
	for (int i = 0; i < n; i++) {
		cout << i << ": ";
		for (int c: adj[i]) {
			cout << c << " ";
		} cout << endl;
	} cout << endl;
}

void printarr(int * arr, int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	} cout << endl;
}

// drivers
int main() {
	getinp();
	// printadj();
	// printarr(aa, ac); printarr(ab, bc);
	get_bridges();
	calc();
	//
	getchar();
	return 0;
}
