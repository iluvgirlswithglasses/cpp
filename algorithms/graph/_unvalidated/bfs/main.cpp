#include <algorithm>
#include <list>
#include <fstream>
#include <iostream>
using namespace std;

int n;
list<int> * adj;

list<int> bfs(int v) {
	list<int> res = {v};
	bool * visited = new bool[n];
	for (int i = 0; i < n; i++) visited[i] = false;
	visited[v] = true;
	//
	list<int> queue = {v};
	while (!queue.empty()) {
		// fifo
		int cr = queue.front();
		queue.pop_front();
		// backtracking
		for (int i: adj[cr])
			if (!visited[i]) {
				visited[i] = true;
				res.push_back(i);
				queue.push_back(i);
			}
	}
	delete[] visited;
	return res;
}

void inp() {
	ifstream inp; inp.open("inp.txt");
	inp >> n; adj = new list<int>[n];
	int k; inp >> k;
	//
	int a, b;
	for (int i = 0; i < k; i++) {
		inp >> a; inp >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

int main() {
	inp();
	for (int i: bfs(0)) cout << i << " ";
	system("pause");
	return 0;
}
