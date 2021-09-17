#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

// data vars
int n; int k;
int ** edges;
int ** arr;
vector<int> * adj;

// operator vars
vector<vector<int>> group;

// miscs

// printers
void print_group() {
	cout << "group:\n";
	for (vector<int> i: group) {
		for (int j: i) {
			cout << j << " ";
		} cout << endl;
	}
}

// funcs
void dfs(int v, vector<int> & path, bool * visited) {
	// recorder
	visited[v] = true;
	path.push_back(v);
	// recursion
	for (int i: adj[v]) {
		if (!visited[i]) dfs(i, path, visited);
	}
}

void make_group() {
	// init
	bool * visited = new bool[n];
	for (int i = 0; i < n; i++) visited[i] = false;
	// calc
	for (int i = 0; i < n; i++) {
		// some element in visited will be change inside this loop
		if (visited[i]) continue;
		//
		vector<int> path;
		dfs(i, path, visited);
		group.push_back(path);
	}
}

// inp API
class Inp {
public:
	void get();
	void test();
};

void Inp::get() {
	ifstream inp; inp.open("inp.txt");
	inp >> n; inp >> k;
	//
	arr = new int*[n];
	edges = new int*[k];
	adj = new vector<int>[n];
	// get edges
	for (int i = 0; i < k; i++) {
		edges[i] = new int[2];
		//
		int a, b; inp >> a; inp >> b;
		a -= 1; b -= 1;	// translator
		edges[i][0] = a; edges[i][1] = b;
		//
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// the matrix
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			inp >> arr[i][j];
		}
	}
}

void Inp::test() {
	cout << "edges:\n";
	for (int i = 0; i < k; i++) {
		printf("%d %d\n", edges[i][0], edges[i][1]);
	}

	cout << "arr:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		} cout << "\n";
	} cout << "\n";

	cout << "adj:\n";
	for (int i = 0; i < n; i++) {
		cout << i << ": ";
		for (int j: adj[i]) {
			cout << j << " ";
		} cout << endl;
	} cout << endl;
}

// drivers
int main() {
	Inp inp; inp.get();
	inp.test();
	//
	make_group();
	print_group();
	// returns
	getchar();
	return 0;
}
