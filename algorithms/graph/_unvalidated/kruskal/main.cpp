#include <algorithm>
#include <list>
#include <set>
#include <iostream>
#include <fstream>
using namespace std;

// find minimum spanning tree

//
int vCount;
list<int*> edges;

// if there is more than a way from a vertice to another
// the graph is not a tree
bool dfs(int u, int v, bool * visited, list<int> * adj) {
	// cuz its a tree
	// dfs is the best choice
	// there is no breath here

	// return condition
	if (u == v) {
		return true;
	}
	//
	visited[u] = true;
	// we cannot use adj here
	// cuz the thing we using here is a CONNECTED GRAPH
	// we gonna store the constructing tree somewhere else
	for (int i: adj[u]) {
		if (!visited[i]) {
			if (dfs(i, v, visited, adj)) return true;
		}
	}
	return false;
}

void kruskal(list<int*> edges) {
	int chosen = 0;
	list<int*> res;
	// as we choose the edges, this adj list will be updated
	list<int> * adj = new list<int>[vCount];
	bool * visited = new bool[vCount];
	// if choose count == vCount - 1 => tree formed
	while (chosen != vCount - 1 && !edges.empty()) {
		int * e = edges.front(); edges.pop_front();
		// ready for the dfs
		for (int i = 0; i < vCount; i++) visited[i] = false;
		//
		if (!dfs(e[0], e[1], visited, adj)) {
			// update the adj
			adj[e[0]].push_back(e[1]);
			adj[e[1]].push_back(e[0]);
			// the result
			chosen += 1;
			res.push_back(e);
		}
	}
	// if choose count == vCount - 1 => tree formed
	if (chosen == vCount - 1) {
		for (int * e: res) {
			printf("%d %d - cost: %d\n", e[0], e[1], e[2]);
		}
	} else {
		cout << "given graph not connected\n";
	}
}

//
void get_inp() {
	ifstream inp; inp.open("inp.txt");
	inp >> vCount;
	//
	for (int i = 0; i < vCount; i++) {
		for (int j = 0; j < vCount; j++) {
			int a; inp >> a;
			bool rep = (
				find_if(edges.begin(), edges.end(), [&](int * k){
					return k[1] == i && k[0] == j;	// reversed case
				}) == edges.end()
			);
			if (a != 0 && rep) {
				edges.push_back(new int[3]{i, j, a});
			}
		}
	}
	// use for vector & arr: 
	// sort(edges.begin(), edges.end(), [](int * i, int * j){return i[2] < j[2];});
	edges.sort([](int * i, int * j){return i[2] < j[2];});
}

int main() {
	get_inp();
	kruskal(edges);
	//
	system("pause");
	return 0;
}
