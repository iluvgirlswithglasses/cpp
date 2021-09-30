#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

// this is an easier version of party problem
// see: ./training/ref/party'
// the party one reflect the true strength of dynamic distribution
// mean while...
// this is just a dumb
// wasting calculating power on comparison in each loop

//
int n;
int ** arr;

// for the test
int c = 0;

// main
// this just reminded us how shit our code once was
// now, look at this,...
// elegant
int recursion(int x, int y) {
	c += 1;
	// met the max depth
	if (y == n - 1) {
		return arr[y][x];
	}
	// just some shit
	int res = arr[y][x] + max(
		recursion(x, y + 1), recursion(x + 1, y + 1)
	);
	//
	return res;
}

//
void get_inp() {
	ifstream inp; inp.open("inp.txt");
	inp >> n; arr = new int*[n];
	//
	for (int i = 0; i < n; i++) {
		arr[i] = new int[i + 1];
		for (int j = 0; j < i + 1; j++) {
			inp >> arr[i][j];
		}
	}
	// test code
	/* 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << arr[i][j] << " ";
		} cout << endl;
	}
	*/
}

int main() {
	get_inp();
	cout << recursion(0, 0);
	//
	printf("\n\ncost: %d\n", c);
	getchar();
	return 0;
}
