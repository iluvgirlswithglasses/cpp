// this is like... suprisingly easy
// this should be the first question, ...
// ... meanwhile the first question, due to its difficulty, should be the last
#include <bits/stdc++.h>
using namespace std;

ifstream inp("friends.inp");

//
int n;
set<int> * adj;

//
bool dfs(int a, int b) {
	// true if adj[a].include(b) or
	// adj[a].include(?) in which ?.include(b)
	// oh shit we don't need to write a recursive one
	for (int i: adj[a]) {
		if (i == b) return true;
		for (int j: adj[i]) {
			if (j == b) return true;
		}
	}
	return false;
}

void calc() {
	int queries; inp >> queries;
	for (int i = 0; i < queries; i++) {
		int prc, a, b; inp >> prc >> a >> b;
		prc -= 1; a -= 1; b -= 1;
		if (prc) {
			if (dfs(a, b)) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		} else {
			adj[a].insert(b);
			adj[b].insert(a);
		}
	}
}

//
void getinp() {
	int m;
	inp >> n >> m;
	adj = new set<int>[n];
	//
	for (int i = 0; i < m; i++) {
		int a, b; inp >> a >> b; a -= 1; b -= 1;
		adj[a].insert(b);
		adj[b].insert(a);
	}
}

int main() {
	getinp();
	calc();
	//
	getchar();
	return 0;
}
