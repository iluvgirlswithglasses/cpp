#include <climits>
#include <algorithm>
#include <list>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

// main vars
int ** arr; int n;
bool ** cr_arr;			// matrix graph for edges
vector<int*> edges;
// io
ofstream out;

// utils
void dfs(int cr, bool * visited);
bool can_travel(int a, int b) {
	// if there is a solution to go from vertice a to b => no more road needed
	// call dfs
	bool * visited = new bool[n];
	for (int i = 0; i < n; i++) visited[i] = false;
	visited[a] = true;
	dfs(a, visited);
	// returns
	return visited[b];
}

int * get_min_loc() {
	// get the min cost in arr
	int m = INT_MAX, 
		y = -1, x = -1; // it will never return -1 tho
	//
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// if can build road from i to j
			// if there is no way to travel from i to j yet
			// if arr[i][j] gives the min cost
			if (arr[i][j] != 0 && !can_travel(i, j) && arr[i][j] < m) {
				y = i; x = j; m = arr[i][j];
			}
		}
	}
	return new int[2]{y, x};
}

// we don't need to know the cost of builded roads
void update_arr() {
	for (int * i: edges) {
		//
		arr[ i[0] ][ i[1] ] = 0;
		arr[ i[1] ][ i[0] ] = 0;
		//
		cr_arr[ i[0] ][ i[1] ] = true;
		cr_arr[ i[1] ][ i[0] ] = true;
	}
}

// if a vertice can travel to all other => fully connected graph
void dfs(int cr, bool * visited) {
	for (int i = 0; i < n; i++) {
		if (cr_arr[cr][i] && !visited[i]) {
			//
			visited[i] = true;
			dfs(i, visited);
		}
	}
}

bool dfs() {
	bool * visited = new bool[n];
	for (int i = 0; i < n; i++) visited[i] = false;
	visited[0] = true;
	dfs(0, visited);
	// check if all vertices are visited
	for (int i = 0; i < n; i++) {
		if (!visited[i]) return false;
	}
	// all visited
	return true;
}

// main
list<int*> additions;
int calc() {
	int cost = 0;
	while (!dfs()) {
		int * loc = get_min_loc();
		cost += arr[ loc[0] ][ loc[1] ];
		edges.push_back(loc);
		additions.push_back(loc);
		//
		update_arr();
	}
	return cost;
}

// drivers
void get_inp() {
	// io
	ifstream inp; inp.open("traffics.inp");
	out.open("traffics.out");
	// init fields
	int k;
	inp >> n; inp >> k;
	// edges
	for (int i = 0; i < k; i++) {
		int a; int b; inp >> a; inp >> b; a -= 1; b -= 1;	// read vertices and shift them by 1
		edges.push_back(new int[2]{
			a, b
		});
	}
	// arr
	arr = new int*[n];
	cr_arr = new bool*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		cr_arr[i] = new bool[n];
		for (int j = 0; j < n; j++) {
			inp >> arr[i][j];
			cr_arr[i][j] = false;
		}
	}
}

void test_inp() {
	// edges
	for (int * i: edges) {
		cout << i[0] << " " << i[1] << endl;
	}
	// arr
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		} cout << endl;
	}
}

int main() {
	//
	get_inp();
	update_arr();	// fix the arr first
	//
	cout << calc() << endl;
	for (int * i: additions) {
		printf("%d %d (%d %d)\n", i[0], i[1], i[0] + 1, i[1] + 1);
	}
	// returns
	getchar();
	return 0;
}
