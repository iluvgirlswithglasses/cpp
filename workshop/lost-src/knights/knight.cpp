#include <iostream>
using namespace std;

const int n = 8;	// may change if required
// sometimes, simple is better than complex
const int moves = 8;
int x_mov[moves] = {1, 2, 2, 1, -1, -2, -2, -1};
int y_mov[moves] = {2, 1, -1, -2, -2, -1, 1, 2};

//
bool is_safe(int x, int y, int ** arr) {
	return (
		x >= 0 && y >= 0 && x < n && y < n && arr[x][y] == 0
	);
}

// main
bool recursion(int x, int y, int cr, int ** arr) {
	// return condition
	if (cr == n * n) return true;	// or: number of steps performed reach total board cells
	// recursion
	for (int i = 0; i < moves; i++) {
		int nxt_x = x + x_mov[i], 
			nxt_y = y + y_mov[i];
		//
		if (is_safe(nxt_x, nxt_y, arr)) {
			arr[nxt_x][nxt_y] = cr;
			if (recursion(nxt_x, nxt_y, cr + 1, arr)) {
				return true;
			}
			// backtracking
			arr[nxt_x][nxt_y] = 0;
		}
	}
	// no child returned true
	return false;
}

int main() {
	// table generator
	int ** arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++) arr[i][j] = 0;	// 0 == not traveled
	}
	// calc
	// we accept that we'll start with (0; 0)
	arr[0][0] = 1;
	recursion(0, 0, 2, arr);	// 2 looks unfamiliar...
	// prints
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << "\t";
		} cout << endl;
	} cout << endl;
	//
	getchar();
	return 0;
}
