#include <climits>
#include <fstream>
#include <iostream>
using namespace std;

//
int n;
int ** mat;
//
int best;		// best cost
int * bestPath;	// store the best path
// opers
bool * visited;
int * path;		// store all the possible pathes
int * cost;		// store the cost to n vertices relative to path

// utils
void setBest(int val) {
	for (int i = 0; i < n; i++) {
		bestPath[i] = path[i];
	}
	best = val;
}

//
void recursion(int cr) {
	for (int i = 1; i < n; i++) {	// no need to loop to 0
		if (visited[i]) continue;
		path[cr] = i;
		cost[cr] = cost[cr - 1] + mat[ path[cr - 1] ][i];
		// if this doesn't give a better result
		if (cost[cr] >= best) continue;
		// otherwise
		if (cr == n - 1) {
			// reached the end case
			if (cost[cr] + mat[ path[cr] ][0] < best) {
				setBest(cost[cr] + mat[path[cr]][0]);
			}
		} else {
			// backtracking
			visited[i] = true;
			recursion(cr + 1);
			visited[i] = false;
		}
	}
}

//
void getinp() {
	ifstream inp("inp.txt");
	inp >> n;
	//
	mat = new int*[n];
	path = new int[n];
	bestPath = new int[n];
	cost = new int[n];
	visited = new bool[n];
	//
	for (int i = 0; i < n; i++) {
		mat[i] = new int[n];
		for (int j = 0; j < n; j++) {
			inp >> mat[i][j];
		}
	}
}

void init() {
	for (int i = 0; i < n; i++) {
		path[i] = 0;
		bestPath[i] = 0;
		cost[i] = 0;
		visited[i] = false;
	}
	visited[0] = true;
	best = INT_MAX;
}

//
int main() {
	getinp();
	init();
	//
	recursion(1);
	cout << best << endl;
	for (int i = 0; i < n; i++) cout << bestPath[i] << " "; cout << "0\n";
	//
	system("pause");
	return 0;
}
