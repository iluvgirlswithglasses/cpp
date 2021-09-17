#include <climits>
#include <list>
#include <fstream>
#include <iostream>
using namespace std;
// this is dijkstra, but you have the path

// some stuffs
int ** arr;
int vCount;

// some declaration
void get_solution(int v, int src, int * parent, list<int> & res);

// printers
void print_dist(int * dist) {
	for (int i = 0; i < vCount; i++) {
		cout << dist[i] << " ";
	} cout << endl;
}

void print_solution(int * parent, int src) {
	for (int i = 0; i < vCount; i++) {
		// we don't need the solution to src !
		if (i == src || parent[i] == -1) continue;
		// get_solution() doesn't store the destination vertice due to optimisation
		// so we'll do it ourselves
		list<int> path;
		get_solution(i, src, parent, path);
		// if vertice can't be reached
		// now just printer
		cout << i << ": ";
		for (int j: path) {
			cout << j << " ";
		} cout << endl;
	}
}

// pure dijkstra
int min_weight(int * dist, bool * spt) {
    int min = INT_MAX, minIndex; 
  
    for (int v = 0; v < vCount; v++) 
        if (!spt[v] && dist[v] <= min) 
            min = dist[v], minIndex = v; 
  
    return minIndex; 
}

void get_solution(int v, int src, int * parent, list<int> & res) {
	res.push_front(v);
	// if v == src => break recursion
	if (v != src) {
		get_solution(parent[v], src, parent, res);
	}
}

void calc(int src) {
	// operators
	int * dist = new int[vCount];
	bool * spt = new bool[vCount];
	// this store the parent vertice of respective vertice
	int * parent = new int[vCount];
	// initialise
	for (int i = 0; i < vCount; i++) dist[i] = INT_MAX, spt[i] = false, parent[i] = -1;
	dist[src] = 0;	// cost to given source is 0

	// calc
	// we don't need to loop for the last iteration
	for (int i = 0; i < vCount - 1; i++) {
		// with this method,
		// the weights are always calculated from low -> high
		// => perfectness
		int u = min_weight(dist, spt);	// u always == src at first iteration
		spt[u] = true;
		// if one can be updated, let it be
		if (dist[u] == INT_MAX) break;
		// can be replaced with:
		// for (int v: adj[u]) {}
		for (int v = 0; v < vCount; v++) {
			// if we included the vertice v before or 
			// if u and v is not connected
			if (spt[v] || arr[u][v] == 0) continue;
			//
			int crWeight = dist[u] + arr[u][v];
			if (crWeight < dist[v]) {
				dist[v] = crWeight;
				// here we store the parent
				parent[v] = u;
			}
		}
	}

	// can't reach case
	for (int i = 0; i < vCount; i++)
		if (dist[i] == INT_MAX) dist[i] = -1;

	// hello welcome to printer time
	print_dist(dist); cout << endl;
	print_solution(parent, src);
}

int main() {
	// inp
	std::ifstream inp; inp.open("inp.txt");
	inp >> vCount;
	arr = new int*[vCount];
	for (int i = 0; i < vCount; i++) {
		arr[i] = new int[vCount];
		for (int j = 0; j < vCount; j++) {
			inp >> arr[i][j];
		}
	}
	// calc
	calc(0);
	// return
	system("pause");
	return 0;
}
