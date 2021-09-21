#include <list>
#include <iostream>
#include <fstream>
using namespace std;

//
int n;
int * val;
list<int> * adj;

//
int * recursion(int v) {
	// res[0] = choose, res[1] = not choose
	int * res = new int[2]{val[v], 0};
	// if there is at least a child
	for (int i: adj[v]) {
		int * childRes = recursion(i);
		// if you choose the parent node
		// you must forsake the children
		res[0] += childRes[1];
		// and otherwise
		res[1] += childRes[0];
	}
	return res;
}

//
class Inp {
public:
	void get();
	void test();
};

void Inp::get() {
	ifstream inp; inp.open("inp.txt");
	inp >> n;
	//
	adj = new list<int>[n];
	val = new int[n];
	//
	for (int i = 0; i < n; i++) {
		inp >> val[i];
	}
	//
	for (int i = 0; i < n - 1; i++) {
		int a, b; inp >> a; inp >> b;
		a -= 1; b -= 1;	// trans
		// these are vectors, not just lines
		adj[b].push_back(a);
	}
}

void Inp::test() {
	for (int i = 0; i < n; i++) cout << val[i] << " "; cout << endl;
	for (int i = 0; i < n; i++) {
		cout << i << ": ";
		for (int j: adj[i]) cout << j << " "; cout << endl;
	}
}

//
int main() {
	Inp inp = Inp(); inp.get();
	//
	cout << recursion(0)[0];
	//
	getchar();
	return 0;
}
