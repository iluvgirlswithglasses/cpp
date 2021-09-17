#include <climits>
#include <list>
#include <iostream>
#include <fstream>
using namespace std;

//
int vCount;
int ** arr;
int src, des;
void get_path(int v, int src, int * parent, list<int> & res);

// printer
void print_solution(int des, int src, int * parent) {
	list<int> path;
	get_path(des, src, parent, path);
	for (int i: path) {
		// translator
		cout << i + 1 << " ";
	} cout << endl;
	// delete traveled edges
	for (int i = 0; i < path.size() - 1; i++) {
		arr[i][i + 1] = 0;
	}
}

//
void get_path(int v, int src, int * parent, list<int> & res) {
	res.push_front(v);
	if (v != src) {
		get_path(parent[v], src, parent, res);
	}
}

int get_min(int * dist, bool * spt) {
	int minVal = INT_MAX, minIndex;
	for (int i = 0; i < vCount; i++) {
		// if not included in spt and ...
		if (!spt[i] && dist[i] < minVal) {
			//
			minVal = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}

void dijkstra(int src, int des, int & s) {
	// core
	int * dist = new int[vCount];
	bool * spt = new bool[vCount];
	int * parent = new int[vCount];
	// init
	for (int i = 0; i < vCount; i++) {
		dist[i] = INT_MAX;
		spt[i] = false;
		parent[i] = -1;
	}
	dist[src] = 0;
	//
	for (int k = 0; k < vCount - 1; k++) {
		int u = get_min(dist, spt);
		spt[u] = true;
		if (u == des) break;	// now move immediately to printing stuffs
		// the min is the MAX VALUE, surely broke
		if (dist[u] == INT_MAX) break;
		//
		for (int v = 0; v < vCount; v++) {
			// if included in spt or u and v are not connected => break
			if (spt[v] || arr[u][v] == 0) continue;
			// cost(src, u) + cost(u, v) give better result than cost current cost(src, v)
			if (dist[u] + arr[u][v] < dist[v]) {
				dist[v] = dist[u] + arr[u][v];
				parent[v] = u;
			}
		}
	}
	// printer
	if (dist[des] != -1) {
		s += dist[des];
		print_solution(des, src, parent);
	}
}

// inp
class Inp {
	int trans_in(int i);
	int trans_out(int i);
public:
	void get();
	void test();
};

int Inp::trans_in(int i) {
	return i - 1;
}

int Inp::trans_out(int i) {
	return i + 1;
}

void Inp::get() {
	ifstream inp; inp.open("inp.txt");
	inp >> vCount;
	//
	int eCount; inp >> eCount;
	inp >> src; inp >> des;
	src = trans_in(src); des = trans_in(des);
	// init graph
	arr = new int*[vCount];
	for (int i = 0; i < vCount; i++) {
		arr[i] = new int[vCount];
		for (int j = 0; j < vCount; j++) {
			arr[i][j] = 0;
		}
	}
	//
	for (int i = 0; i < eCount; i++) {
		// create graph here
		int a, b, c;
		inp >> a; inp >> b; inp >> c;
		arr[ trans_in(a) ][ trans_in(b) ] = c;
		arr[ trans_in(b) ][ trans_in(a) ] = c;
	}
};

void Inp::test() {
	printf("%d %d %d\n", vCount, src, des);
	for (int i = 0; i < vCount; i++) {
		for (int j = 0; j < vCount; j++) {
			cout << arr[i][j] << " ";
		} cout << endl;
	}
}

// driver
int main() {
	Inp inp = Inp(); inp.get();
	// we can store path to print it after sum
	// but nah
	// it's for the test
	// we just practicing
	// we won't waste time
	int s = 0;
	for (int i = 0; i < 2; i++) {
		dijkstra(src, des, s);
	} 
	if (s == 0) {
		cout << "no solution\n";
	} else {
		cout << s;
	}
	//
	getchar();
	return 0;
}
