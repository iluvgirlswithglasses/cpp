#include <iostream>
using namespace std;

#define INF 9999
#define V 4

int graph[V][V] = {
	{0,   6,   2,   10 },
	{6,   0,   3,   INF},
	{2,   3,   0,   1  },
	{10,  INF, 1,   0  }
};

void print_res(int dist[][V]) {
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			cout << dist[i][j] << " ";
		} cout << endl;
	} cout << endl;
}

//
void floyd() {
	// clone first
	int dist[V][V];
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++) 
			dist[i][j] = graph[i][j];
	// floyd
	// some vector addition trick
	// if one vector is good enough, it won't be replaced
	// if it isn't, the sum of 2 vector gonna replace it
	// if the sum of x vector is better than the one of (x - 1)
	// the better result gonna take the place too !

	// god damn easier than dijkstra
	// only cost more time
	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				// if two connected vectors give better result than
				// the previous one,
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					// let the better one in
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	// res
	print_res(dist);
}

// driver
int main() {
	floyd();
	//
	system("pause");
	return 0;
}
