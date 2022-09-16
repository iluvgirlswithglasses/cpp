// đếm số thành phần liên thông mạnh
// tham khảo từ một bài toán tương tự:
// https://cp-algorithms.com/graph/bridge-searching.html
// đầu tiên chúng ta tìm số thành phần liên thông mạnh
// xong rồi hợp
// số tập hợp sau khi hợp các thành phần liên thông cũng chính là đáp án của bài toán

#include <stdio.h>
#include <vector>
using namespace std;

const int N = 807, I = 1e7+7;
int n, m, cnt, timer, low[N], tin[N];
vector<int> adj[N], st;

/**
 * siêu đồ thị
 * */
int group[N];
vector<bool> deg_in;


/**
 * tarzan
 * */
void dfs(int u) {
	low[u] = tin[u] = ++timer;
	st.push_back(u);
	//
	for (int v: adj[u]) {
		// tin[v] > 0 --> visited[v] == true
		if (tin[v]) {
			low[u] = min(low[u], tin[v]);
		} else {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
	}
	// find one !
	if (low[u] == tin[u]) {
		int v;
		do {
			v = st.back(); st.pop_back();
			low[v] = tin[v] = I;
			group[v] = cnt;
		} while (v != u);
		//
		cnt++;
	}
}

int lines() {
	deg_in.resize(cnt);
	//
	for (int i = 0; i < n; i++) {
		int u = group[i];
		//
		for (int j: adj[i]) {
			int v = group[j];
			//
			if (u != v) {
				deg_in[v] = true;
			}
		}
	}
	int lone = 0;
	for (bool i: deg_in) {
		if (!i) lone++;
	}
	return lone;
}

/**
 * drivers
 * */
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
	// deg_in[i] == 0 --> lẻ loi êy
	if (cnt == 1) {
		printf("1\n");
	} else {
		printf("%d\n", lines());
	}
	//
	return 0;
}
