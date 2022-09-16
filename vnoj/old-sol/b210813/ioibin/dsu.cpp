#include <iostream>
#include <random>
using namespace std;

/**
 * dsu
 * */
const int N = 1e4+7;
int p[N];

int find(int u) {
	if (p[u] != u) return find(p[u]);
	return p[u];
}

void join(int u, int v) {
	int a = find(u), b = find(v);
	if (rand() % 2) {
		p[a] = b;
	} else {
		p[b] = a;
	}
}


/**
 * drivers
 * */
bool is_connected(int u, int v) {
	return find(u) == find(v);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (int i = 0; i < N; i++) p[i] = i;
	//
	int q; cin >> q;
	while (q--) {
		int u, v, typ; cin >> u >> v >> typ;
		u--; v--;
		if (typ == 1) {
			join(u, v);
		} else {
			cout << is_connected(u, v) << "\n";
		}
	}
	return 0;
}
