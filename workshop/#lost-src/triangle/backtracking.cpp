#include <climits>
#include <fstream>
#include <iostream>
using namespace std;

//
int n;
int ** arr;

// test
int c = 0;

void recursion(int x, int y, int s, int & res) {
	c += 1;
	if (y == n - 1) {
		res = max(res, s + arr[y][x]);
	} else {
		recursion(x, y + 1, s + arr[y][x], res);
		recursion(x + 1, y + 1, s + arr[y][x], res);
	}
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
}

int main() {
	get_inp();
	//
	int res = INT_MIN;
	recursion(0, 0, 0, res);
	cout << res;
	//
	//
	printf("\n\ncost: %d\n", c);
	getchar();
	return 0;
}