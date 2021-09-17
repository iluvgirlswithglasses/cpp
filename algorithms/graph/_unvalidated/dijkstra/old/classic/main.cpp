#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

//
const int N = 1e3 + 7;
const int E = 1e5 + 7;
int n, mat[N][N];
//
bool spt[N];
int dist[N];

int getMin() {
	int minIndex, minVal = E;
	for (int i = 0; i < n; i++) {
		if (!spt[i] && dist[i] < minVal) {
			minIndex = i;
			minVal = dist[i];
		}
	}
	return minIndex;
}

void calc(int src) {
	for (int i = 0; i < n; i++) dist[i] = E;
	dist[src] = 0;
	//
	for (int i = 0; i < n-1; i++) {
		int u = getMin();
		spt[u] = true;
		for (int v = 0; v < n; v++) {
			if (mat[u][v] == 0) continue;
			dist[v] = min(dist[v], dist[u] + mat[u][v]);
		}
	}
	//
	for (int i = 0; i < n; i++) cout << dist[i] << " "; cout << endl;
}

/**
 * drivers
 * */
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	//
	calc(0);
	//
	system("pause");
	return 0;
}
