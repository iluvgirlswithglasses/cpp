#include <climits>
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

// global
int n, m, d, r;		// stations, cables, land-broken, river-broken
int ** connected;	// connected[u][v] == 1 if u & v is connected, 0 otherwise
int ** wire_typ;	// wire_typ[u][v] == 0 if there is no need anymore, == 1 if the cable is ground-type, == 2 if river-type
int ** length;		// length[u][v]: the length of the cable connecting u & v
int ** cables;		// cables[i] = wire i {u, v, l}

// io vars
ifstream inp;

// use this instead of cout in real test
ofstream out;

// initializers
void init() {
	inp.open("cable.inp");
	out.open("cable.out");
}

// validation utils
void dfs_is_safe(int cr, bool * traveled) {
	for (int i = 0; i < n; i++) {
		if (connected[cr][i] && !traveled[i]) {
			traveled[i] = true;
			dfs_is_safe(i, traveled);
		}
	}
}

bool is_safe() {
	bool * visited = new bool[n];
	for (int i = 0; i < n; i++) visited[i] = false; visited[0] = true;
	dfs_is_safe(0, visited);
	//
	return find(visited, visited + n, false) == visited + n;
}

bool dfs_is_connected(int cr, int v, bool * traveled) {
	if (cr == v) return true;
	// dfs
	for (int i = 0; i < n; i++) {
		if (connected[cr][i] && !traveled[i]) {
			traveled[i] = true;
			if (dfs_is_connected(i, v, traveled)) {
				return true;
			}
		}
	}
	return false;
}

bool is_connected(int u, int v) {
	// check if u can travel to v
	bool * traveled = new bool[n];
	for (int i = 0; i < n; i++) traveled[i] = false;
	traveled[u] = true;
	//
	return dfs_is_connected(u, v, traveled);
}

// utils
int using_level = 1;	// 1: fixing ground, 2: fixing water

int * get_min() {
	// if can't find anything in this level => switch level
	bool targeted = false;
	//
	int u, v;
	int shortest = INT_MAX;
	//
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (wire_typ[i][j] == using_level) {
				targeted = true;
				//
				if (length[i][j] < shortest) {
					shortest = length[i][j];
					u = i; v = j;
				}
			}
		}
	}
	//
	if (!targeted) {
		using_level += 1;
		// always success @ level 2
		// given verified
		return get_min();
	}
	return new int[2]{u, v};
}

void apply_val(int ** arr, int i, int j, int val) {
	arr[i][j] = val;
	arr[j][i] = val;
}

void fix_wire(int i, int j) {
	apply_val(connected, i, j, 1);
	apply_val(wire_typ, i, j, 0);
	apply_val(length, i, j, INT_MAX);
}

// perf
int calc() {
	//
	int s = 0;
	while (!is_safe()) {
		//
		int * target = get_min(); 
		int u = target[0], v = target[1];
		//
		if (!is_connected(u, v)) {
			s += length[u][v];
		}
		//
		fix_wire(u, v);
	}
	//
	return s;
}

// io utils
void detach_wire(int wire_id, int typ) {
	int * wire = cables[wire_id];
	int u = wire[0], v = wire[1];
	//
	apply_val(connected, u, v, 0);
	apply_val(wire_typ, u, v, typ);
	apply_val(length, u, v, wire[2]);
}

// io
void init_graph() {
	// init graph arr
	for (int i = 0; i < n; i++) {
		connected[i] = new int[n];
		wire_typ[i] = new int[n];
		length[i] = new int[n];
		for (int j = 0; j < n; j++) {
			connected[i][j] = 0;
			wire_typ[i][j] = 0;
			length[i][j] = INT_MAX;
		}
	}
}

void init_wire() {
	for (int i = 0; i < m; i++) {
		int u, v, l; 
		inp >> u; inp >> v; inp >> l; 
		// shift
		u -= 1; v -= 1;
		// cables
		cables[i] = new int[3]{
			u, v, l
		};
	}
}

void get_broken_wire(int c, int typ, bool * broken) {
	for (int i = 0; i < c; i++) {
		int id; inp >> id; id -= 1;
		detach_wire(id, typ);
		broken[id] = true;
	}
}

void get_inp() {
	inp >> n; inp >> m; inp >> d; inp >> r;
	//
	connected = new int*[n]; wire_typ = new int*[n]; length = new int*[n];
	cables = new int*[m];
	//
	init_graph();
	// import wires
	init_wire();
	// ground wires
	bool * broken = new bool[m];
	for (int i = 0; i < m; i++) broken[i] = false;
	//
	if (d > 0) {
		get_broken_wire(d, 1, broken);
	} else {
		int dummy; inp >> dummy;
	}
	// river wires
	if (r > 0) {
		get_broken_wire(r, 2, broken);
	}
	//
	for (int i = 0; i < m; i++) {
		if (!broken[i]) {
			int * wire = cables[i];
			connected[wire[0]][wire[1]] = 1;
			connected[wire[1]][wire[0]] = 1;
		}
	}
}

// debug
void print_graph(int ** arr) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == INT_MAX) {
				cout << "- ";
			} else {
				cout << arr[i][j] << " ";
			}
		} cout << endl;
	} cout << endl;
}

void test_inp() {
	print_graph(connected);
	print_graph(wire_typ);
	print_graph(length);
}

// drivers
int main() {
	init();
	get_inp();
	// debug
	//
	cout << calc();
	//
	getchar();
	return 0;
}
