#include <climits>
#include <algorithm>
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

// eCount = vCount - 1 (maximization)
int vCount;
int ** arr;
vector<int*> edges;

list<int> * edges_to_adj(vector<int*> & edges) {
	list<int> * adj = new list<int>[vCount];
	for (int * i: edges) {
		adj[ i[0] ].push_back( i[1] );
		adj[ i[1] ].push_back( i[0] );
	}
	return adj;
}

bool bfs(list<int> & chosen, vector<int*> & edges) {
	//
	vector<int*> col;
	for (int i: chosen) col.push_back(new int[2]{
		edges[i][0], edges[i][1]
	});
	list<int> * adj = edges_to_adj(col);
	//
	list<int> visited = {0};
	list<int> queue = {0};
	//
	while (!queue.empty()) {
		int cr = queue.front();
		queue.pop_front();
		for (int i: adj[cr]) {
			if (find(visited.begin(), visited.end(), i) == visited.end()) {
				visited.push_back(i);
				queue.push_back(i);
			}
		}
	}
	//
	if (visited.size() == vCount) {
		return true;
	} return false;
}

// NOTE
// if we use adj list
// we don't even need to use bfs to check if graph is connected or not.
// however,
// keeping track of number of connected vertices can be challenging in that case

// time complexity: O( ((V * (V - 1))/2) C (V - 1) )
bool recursion(list<int> & chosen, vector<int*> & edges, int & res) {
	// call sum
	// break the branch if sum is already greater than res
	int s = 0;
	for (int i: chosen) s += arr[ edges[i][0] ][ edges[i][1] ];
	if (s >= res) return false;
	
	// return condition
	if (chosen.size() == vCount - 1) {
		// edges count always == vCount - 1 for optimisation
		if (bfs(chosen, edges)) {
			// if (s < res) is ensured before;
			res = s;
			return true;
		} return false;	// met the size, but not connected
	}

	// collection generator
	int lst = 0;
	if (chosen.size() > 0) lst = chosen.back() + 1;

	// backtracking
	int edgeCount = edges.size();
	for (int i = lst; i < edgeCount; i++) {
		// backtracking
		chosen.push_back(i);
		recursion(chosen, edges, res);
		chosen.pop_back();
	}
	return false;
}

void calc() {
	list<int> chosen;
	vector<int*> routeEdges = edges;
	int res = INT_MAX;
	recursion(chosen, routeEdges, res);
	cout << "min cost: " << res;
}

void add_edge(int i, int j) {
	bool con = true;
	for (int * k: edges) {
		if (
			find(k, k + 2, i) != k + 2 &&
			find(k, k + 2, j) != k + 2
		) {
			con = false; 
			break;
		}
	}
	if (con) {
		edges.push_back(new int[2]{
			i, j
		});
	}
}

void get_inp() {
	ifstream inp; inp.open("inp.txt");
	inp >> vCount; 
	arr = new int*[vCount];
	for (int i = 0; i < vCount; i++) {
		arr[i] = new int[vCount];
		for (int j = 0; j < vCount; j++) {
			inp >> arr[i][j];
			// edges
			if (arr[i][j] != 0) add_edge(i, j);
		}
	}
}

int main() {
	get_inp();
	calc();
	// return
	getchar();
	return 0;
}
