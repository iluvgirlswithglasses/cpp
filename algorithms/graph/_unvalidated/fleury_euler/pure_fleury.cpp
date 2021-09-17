#include <bits/stdc++.h>
using namespace std;

//
int n, m;
vector<int> * adj;

// utils
void add_edge(int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void rmv(int u, int val) {
	vector<int>::iterator p = find(adj[u].begin(), adj[u].end(), val);
	adj[u].erase(p);
}

void rmv_edge(int u, int v) {
	rmv(u, v);
	rmv(v, u);
}

void dfs_count(int u, bool * visited) {
	for (int i: adj[u]) {
		if (!visited[i]) {
			visited[i] = true;
			dfs_count(i, visited);
		}
	}
}

int dfs_count(int u) {
	//
	bool * visited = new bool[n];
	for (int i = 0; i < n; i++) visited[i] = false;
	visited[u] = true;
	dfs_count(u, visited);
	//
	return count(visited, visited + n, true);
}

bool is_safe(int u, int v) {
	// được phép di chuyển qua cạnh (u, v) khi một trong 2 điều kiện thỏa mãn:
	// 1. đó là cạnh duy nhất còn lại chứa đỉnh u
	// 2. cạnh đó không phải là bridge

	// điều kiện 1
	if (adj[u].size() == 1) return true;

	// điều kiện 2
	// nếu xóa cạnh mà số đỉnh truy cập giảm => brigde
	int c1 = dfs_count(u);
	rmv_edge(u, v);
	int c2 = dfs_count(u);
	add_edge(u, v);
	return c1 == c2;
}

//
void euler(int u) {
	//
	for (int i: adj[u]) {
		if (is_safe(u, i)) {
			rmv_edge(u, i);
			printf("(%d -> %d)\n", u, i);
			euler(i);
			return;
		}
	}
}

void euler() {
	int u = 0;
	// nếu là bậc lẻ => phải đi từ nó trước
	for (int i = 0; i < n; i++) {
		if (adj[i].size() & 1) {
			u = i;
			break;
		}
	}
	// nếu không có bậc lẻ chắc chắn sẽ sinh ra euler circuit, bắt đầu & kết thúc tại u
	euler(u);
}

//
void getinp() {
	ifstream inp("inp.txt");
	inp >> n >> m;
	//
	adj = new vector<int>[n];
	for (int i = 0; i < m; i++) {
		int a, b; inp >> a >> b;
		add_edge(a, b);
	}
}

int main() {
	getinp();
	euler();
	//
	cout << "\ndone";
	system("pause");
	return 0;
}
