#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define pi pair<int, int>
#define st first
#define nd second

struct edge {
	int u, v, c;
	edge(int _u, int _v, int _c) {
		u = _u, v = _v, c = _c;
	}
};

const int N = 307;
int n, mat[N][N];
vector<edge> es;

/**
 * dsu
 * */
int p[N];

void init_dsu() {
	for (int i = 0; i < n; i++) p[i] = i;
}

int find(int i) {
	if (p[i] == i) return i;
	p[i] = find(p[i]);
	return p[i];
}

bool join(int i, int j) {
	int u = find(i), v = find(j);
	if (u == v) return false;
	p[u] = v;
	return true;
}

/**
 * kruskal
 * */
void to_edge() {
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			es.push_back({i, j, mat[i][j]});
		}
	}
	sort(es.begin(), es.end(), [](edge &i, edge &j){
		return i.c < j.c;
	});
}

int kruskal() {
	int res = 0;
	for (edge &i: es) {
		if (join(i.u, i.v)) {
			res += i.c;
		}
	}
	return res;
}

/**
 * drivers
 * */
void getinp() {
	cin >> n; n++;
	for (int i = 1; i < n; i++) {
		cin >> mat[0][i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			cin >> mat[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	getinp();
	init_dsu();
	to_edge();
	cout << kruskal() << "\n";
	//
	return 0;
}
