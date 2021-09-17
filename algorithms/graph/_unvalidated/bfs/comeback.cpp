#include <queue>
#include <iostream>
using namespace std;

const int nlim = 1e4;
const int alim = 1e3;
int n, mat[nlim][nlim];
bool visited[nlim];

void bfs(int src) {
	queue<int> q;
	q.push(src);
	visited[src] = true;
	//
	while (!q.empty()) {
		int cr = q.front();
		cout << cr << " ";
		q.pop();
		// finding for adj
		for (int i = 0; i < n; i++) {
			if (!visited[i] && mat[cr][i] > 0) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
	cout << endl;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	//
	bfs(0);
	//
	system("pause");
	return 0;
}
