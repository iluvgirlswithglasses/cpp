#include <iostream>
using namespace std;

//
const int WALL = 0;
const int PATH = 1;
const int VIST = 2;	// visited

//
bool calc(int n, int m, int ** arr) {
	// ensured that arr[0][0] is path
	arr[0][0] = 2;
	// col == 0
	for (int i = 1; i < n; i++) {
		if (arr[i][0] == PATH) arr[i][0] = arr[i-1][0];
	}
	// row = 0
	for (int i = 1; i < m; i++) {
		if (arr[0][i] == PATH) arr[0][i] = arr[0][i-1];
	}
	// the rest of the matrix
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			// use the result of pre cell
			// just like best shared-substring algorithm
			if (arr[i][j] != WALL) arr[i][j] = max(arr[i][j-1], arr[i-1][j]);
		}
	}
	//
	//
	return arr[n-1][m-1] == VIST;
}

// drivers
int main() {
	int n = 5, m = 5;
	int ** arr = new int*[n]{
		new int[m]{1, 0, 1, 1, 1},
		new int[m]{1, 0, 1, 0, 1},
		new int[m]{1, 0, 1, 0, 1},
		new int[m]{1, 0, 1, 0, 1},
		new int[m]{1, 1, 1, 0, 1},
	};
	//
	cout << calc(n, m, arr);
	//
	system("pause");
	return 0;
}
