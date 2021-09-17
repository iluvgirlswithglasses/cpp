// thuật toán tìm bridge hơi bị ngu
// làm như vậy chúng ta sẽ phải dfs 2 lần
// thế tại sao không thử xóa edge(u, v)...
// ...rồi tìm một path khác dẫn từ v đến u ?
// nếu tìm được => edge(u, v) không phải bridge
// lại chỉ cần dfs 1 lần, và lần đó không phải duyệt hết cả đồ thị
// chưa hết, cách này còn thực hiện được trong euler có hướng
// vì cái cầu ngu này làm gì được trong tìm euler path có hướng ?!?!

#include <bits/stdc++.h>
using namespace std;

//
int n, m;
vector<int> * adj;

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

bool is_safe(int u, int v) {
	// được phép di chuyển qua cạnh (u, v) khi một trong 2 điều kiện thỏa mãn:
	// 1. đó là cạnh duy nhất còn lại chứa đỉnh u
	// 2. cạnh đó không phải là bridge

	// điều kiện 1
	if (adj[u].size() == 1) return true;

	// điều kiện 2
	rmv_edge(u, v);
	bool * visited = new bool[n];
	for (int i = 0; i < n; i++) visited[i] = false; visited[v] = true;
	bool not_bridge = dfs(v, u, visited);
	add_edge(u, v);
	return not_bridge;
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
