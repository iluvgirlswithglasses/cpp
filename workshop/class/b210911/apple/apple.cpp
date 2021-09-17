#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

// this is a less challenging version of dynamic distribution
// see:
// ./classic/triangle
// ./training/ref/party

//
int n, m;
int ** arr;

//
int recursion(int x, int y) {
	// sth is out of this world
	if (x == n || y == m) return 0;
	// return condition met
	if (x == n - 1 && y == m - 1) {
		return arr[x][y];
	}
	return arr[x][y] + max(
		recursion(x + 1, y), recursion(x, y + 1)
	);
}

// drivers
void get_inp() {
	ifstream inp; inp.open("apple.inp");
	inp >> n; inp >> m; arr = new int*[n];
	//
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
		for (int j = 0; j < m; j++) {
			inp >> arr[i][j];
		}
	}
}

void test_inp() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		} cout << endl;
	} cout << endl;
}

int main() {
	get_inp();
	cout << recursion(0, 0);
	//
	getchar();
	return 0;
}
