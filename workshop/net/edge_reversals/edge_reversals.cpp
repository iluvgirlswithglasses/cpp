#include <algorithm>
#include <list>
#include <iostream>
#include <fstream>
using namespace std;

int vCount;
int ** arr;

void dfs(int cr, list<int> & visited, int * stat) {
	// net depth
	for (int i = 0; i < vCount - 1; i++) {
		int * p = find(arr[i], arr[i] + 2, cr);
		if (p == arr[i] + 2) continue;
		//
		int crIndex = distance(arr[i], p);
		int nxt = arr[i][(crIndex + 1) % 2];
		// already known case
		if (find(visited.begin(), visited.end(), nxt) != visited.end()) {
			continue;
		} visited.push_back(nxt);
		// reverse
		if (crIndex == 1) {
			for (int j = 0; j <= cr; j++) 
				stat[j] += 1;
		} else {
			for (int j = cr + 1; j < vCount; j++) 
				stat[j] += 1;
		}
		// backtracking
		dfs(nxt, visited, stat);
	}
}

void calc() {
	// init
	int * stat = new int[vCount];
	for (int i = 0; i < vCount; i++) stat[i] = 0;
	list<int> visited;
	// find top vertex
	int * linked = new int[vCount];
	for (int i = 0; i < vCount; i++) 
		linked[i] = 0;
	for (int i = 0; i < vCount - 1; i++) {
		linked[ arr[i][0] ] += 1;
		linked[ arr[i][1] ] += 1;
	}
	//
	int start;
	for (int i = 0; i < vCount; i++) {
		if (linked[i] == 1) {
			start = i;
			visited.push_back(start);
			break;
		}
	}
	dfs(start, visited, stat);
	// res
	for (int i = 0; i < vCount; i++) {
		cout << i << " " << stat[i] << endl;
	}
}

int main() {
	// init
	// inp
	ifstream inp; inp.open("inp.txt");
	inp >> vCount; 
	arr = new int*[vCount - 1];
	for (int i = 0; i < vCount - 1; i++) {
		arr[i] = new int[2];
		inp >> arr[i][0]; inp >> arr[i][1];
	}
	// calc
	calc();
	// test
	// return
	getchar();
	return 0;
}
