// đếm số thành phần liên thông mạnh
// tham khảo từ một bài toán tương tự:
// https://cp-algorithms.com/graph/bridge-searching.html

#include <stdio.h>
#include <vector>
using namespace std;

const int N = 807, I = 1e7+7;
int n, m, cnt, timer, low[N], tin[N];
vector<int> adj[N], st;

void dfs(int u) {
	low[u] = tin[u] = ++timer;
	st.push_back(u);
	//
	for (int v: adj[u]) {
		// cần cha gì bool visited[]
		// sao hồi trước không nghĩ ra cái này nhỉ
		if (tin[v]) {
			low[u] = min(low[u], tin[v]);
		} else {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
	}
	//
	if (low[u] == tin[u]) {
		cnt++;
		int v = n;
		while (v != u) {
			v = st.back(); st.pop_back();
			low[v] = tin[v] = I;
		}
	}
}

int main() {
	// inp
	scanf("%d %d", &n, &m);
	while (m--) {
		int u, v; scanf("%d %d", &u, &v);
		adj[u-1].push_back(v-1);
	}
	// tính số thành phần liên thông mạnh
	for (int i = 0; i < n; i++) {
		if (!tin[i]) dfs(i);
	}
	//
	printf("%d\n", cnt);
	return 0;
}
