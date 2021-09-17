// the idea of checking if directed graph is strongly connected is simple
// first we perform a dfs, 
// if vertice u can travel through every vertice
// then we continue
// otherwise its not strongly connected
// secondly we reverse the graph and perform dfs on u again
// if u can again travel through all others
// then the given graph is a strongly connected graph

// this can help to check if graph has euler circuit
// the conditions for euler circuit is:
//	1. all vertices in graph must be strongly connected
//	2. all vertices' in-degree must equals to out-degree

// btw,
// trong những câu hỏi chỉ cần các cạnh liên thông mạnh, chứ k cần đỉnh
// bọn chơi ác có thể sẽ cho một số đỉnh dư thừa, không liên kết với cạnh nào
// thí dụ như trong việc tìm euler path/circuit
// thế nên, để khắc chế trò này
// chúng ta có thể thêm vào biến n_inuse
// rồi thay "return find(visited, visited + n, false) == visited + n;"...
// ... thành "return count(visited, visited + n, true) == n_inuse;"
// thế là có thể thực hiện euler stuffs kể cả khi đồ thị không liên thông mạnh

#include <fstream>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

//
int n, m;
list<int*> edges;

//
void dfs(int u, int shift, bool * visited) {
	for (int * e: edges) {
		if (e[shift] == u) {
			// an edge connects to u is picked
			int v = e[ (shift + 1) % 2 ];
			if (visited[v]) continue;
			visited[v] = true;
			dfs(v, shift, visited);
		}
	}
}

void init_visited(bool * visited) {
	for (int i = 1; i < n; i++) visited[i] = false;
	visited[0] = true;
}

bool is_strongly_connected() {
	bool * visited = new bool[n];
	init_visited(visited);
	//
	dfs(0, 0, visited);
	if (find(visited, visited + n, false) != visited + n) return false;
	//
	init_visited(visited);
	dfs(0, 1, visited);
	return find(visited, visited + n, false) == visited + n;
}

//
void getinp() {
	ifstream inp("inp.txt");
	inp >> n >> m;
	//
	for (int i = 0; i < m; i++) {
		int a, b; inp >> a >> b;
		edges.push_back(new int[2]{a, b});
	}
}

int main() {
	getinp();
	cout << is_strongly_connected();
	//
	system("pause");
	return 0;
}
