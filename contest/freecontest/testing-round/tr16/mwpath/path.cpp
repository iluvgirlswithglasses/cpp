#include <climits>
#include <list>
#include <iostream>
using namespace std;

//
const int lim = 1e3;
int n, m;
list<int*> * adj;
bool isblack[lim];
int s, t;

//
void dfs(int cr, int cr_w, bool blacked, bool * visited, int &minval) {
	if (isblack[cr]) blacked = true;
	for (int * i: adj[cr]) {
		// found the shit
		if (i[0] == t) {
			minval = min(minval, cr_w + i[1]);
			return;
		}
		//
		if (!visited[ i[0] ]) {
			visited[i[0]] = true;
			dfs(i[0], cr_w + i[1], blacked, visited, minval);
			visited[i[0]] = false;
		}
	}
}

//
int calc() {
	int minval = INT_MAX;
	bool * visited = new bool[n];
	for (int i = 0; i < n; i++) visited[i] = false;
	//
	visited[s] = true;
	dfs(s, 0, false, visited, minval);
	//
	if (minval == INT_MAX) return -1;
	return minval;
}

//
int main() {
	cin >> n >> m;
	//
	adj = new list<int*>[n];
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		a -= 1; b -= 1;
		adj[a].push_back(new int[2]{b, c});
	}
	// blacks
	int k; cin >> k;
	while (k--) {
		int a; cin >> a; a--;
		isblack[a] = true;
	}
	cin >> s >> t; s--; t--;
	//
	cout << calc() << endl;
	//
	return 0;
}
