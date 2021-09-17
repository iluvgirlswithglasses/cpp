#include <algorithm>
#include <list>
#include <iostream>
#include <fstream>
using namespace std;

// basic graph stuffs
int vCount;
list<int> * adj;
// requirements
int placesCount;
int * places;

//
class Inp {
public:
	void get(); 
	void test();
};
void Inp::get() {
	// manifest
	ifstream inp; inp.open("inp.txt");
	inp >> vCount;
	// gen
	adj = new list<int>[vCount];
	// data
	// eCount = vCount - 1
	for (int i = 0; i < vCount - 1; i++) {
		int a, b; inp >> a; inp >> b;
		// trans
		a -= 1; b -= 1;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// requirements
	inp >> placesCount;
	places = new int[placesCount];
	for (int i = 0; i < placesCount; i++) {
		int a; inp >> a;
		// trans
		a -= 1;
		places[i] = a;
	}
}
void Inp::test() {
	// adj
	for (int i = 0; i < vCount; i++) {
		cout << i << ": ";
		for (int v: adj[i]) {
			cout << v << " ";
		} cout << endl;
	}
	// places
	for (int i = 0; i < placesCount; i++) {
		cout << places[i] << " ";
	} cout << endl;
}

// bfs
int bfs(int src, int des) {
	bool * visited = new bool[vCount];
	for (int i = 0; i < vCount; i++) visited[i] = false;
	//
	list<int> queue = {src};
	// simple cost array
	list<int> cost = {0};
	//
	while (!queue.empty()) {
		//
		int cr = queue.front();
		queue.pop_front();
		int ct = cost.front();
		cost.pop_front();
		//
		visited[cr] = true;
		// return condition met
		if (cr == des) {
			return ct;
		}
		// recursion
		for (int v: adj[cr]) {
			if (visited[v]) continue;
			queue.push_back(v);
			cost.push_back(ct + 1);
		}
	}
	return -1;	// if there is no way (due to unconnected graph)
}

// driver
int calc() {
	int s = 0;
	for (int i = 0; i < placesCount - 1; i++) {
		s += bfs(places[i], places[i + 1]);
	}
	return s;
}

int main() {
	//
	Inp inp = Inp(); inp.get();
	//
	cout << calc();
	getchar();
	return 0;
}
