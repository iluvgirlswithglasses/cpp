#include <algorithm>
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

// operators
int n;
int uniqueCount;
vector<int> arr;
list<int> * adj;

// funcs
int * bfs(int k) {
	//
	int v = arr[k];
	list<int> queue = {v};
	list<int> cost = {0};
	bool visited[n]; for (int i = 0; i < n; i++) visited[i] = false;
	visited[v] = true;
	//
	while (!queue.empty()) {
		// store the cost too !
		// cost is strictly related to vertices in queue
		// its like the HashMap
		int cr = queue.front();
		int ct = cost.front();
		queue.pop_front();
		cost.pop_front();
		// if found a uniqueCount one
		if (find(arr.begin(), arr.begin() + k, cr) == arr.begin() + k) {
			return new int[2] {
				cr, ct
			};
		}
		//
		for (int i: adj[cr]) {
			if (!visited[i]) {
				queue.push_back(i);
				cost.push_back(ct + 1);
				visited[i] = true;
			}
		}
	}
	return new int[2]{-1, -1};
}

int calc() {
	int cost = 0;
	for (int i = uniqueCount; i < n; i++) {
		int * res = bfs(i);
		arr[i] = res[0];
		cost += res[1];
	}
	return cost;
}

// printers
void print_arr() {
	cout << "arr:\n";
	for (int i: arr) {
		cout << i << " ";
	} cout << endl;
}

// inp
void get_inp() {
	ifstream inp; inp.open("inp.txt");
	//
	inp >> n;
	adj = new list<int>[n];
	// temp arr
	// use this to separate uniqueCount number from duplicated number
	int * tempArr; tempArr = new int[n];
	for (int i = 0; i < n; i++) inp >> tempArr[i];
	// record known location
	list<int> known;
	list<int> knownIndex;
	for (int i = 0; i < n; i++) {
		if (find(known.begin(), known.end(), tempArr[i]) == known.end()) {
			known.push_back(tempArr[i]);
			knownIndex.push_back(i);
		}
	}
	// goes to arr
	uniqueCount = known.size();
	arr.insert(arr.end(), known.begin(), known.end());
	for (int i = 0; i < n; i++) {
		if (find(knownIndex.begin(), knownIndex.end(), i) != knownIndex.end()) continue;
		arr.push_back(tempArr[i]);
	}
	// now the adj
	int u, v;
	while (inp >> u) {
		inp >> v;
		// traslator
		// u -= 1; v -= 1;	
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void test_inp() {
	cout << "n = " << n << endl;

	cout << "adj:\n";
	for (int i = 0; i < n; i++) {
		cout << i << ": ";
		for (int j: adj[i]) {
			cout << j << " ";
		} cout << endl;
	}
}

// drivers
int main() {
	//
	get_inp();
	cout << calc();
	//
	getchar();
	return 0;
}
