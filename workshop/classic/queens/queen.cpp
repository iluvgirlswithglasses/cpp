#include <math.h>
#include <iostream>
using namespace std;

//
const int n = 8;

// utils
// somehow this shit has become backtracking + dynamic distribution
bool check(int col, int * arr) {
	// only check from 0 to working column
	for (int i = 0; i < col + 1; i++) {
		for (int j = 0; j < i; j++) {
			// draw it out and you shall understand
			if (
				arr[i] == arr[j] || abs(arr[i] - arr[j]) == i - j
			) return false;
		}
	}
	// all queens legit
	return true;
}

// main
bool recursion(int col, int * arr) {
	// col == n => all columns has been filled
	if (col == n) return true;
	// recursion
	for (int i = 0; i < n; i++) {
		arr[col] = i;
		// check the break right here
		if (check(col, arr)) {
			if (recursion(col + 1, arr)) return true;
		}
	}
	// no child returned true
	arr[col] = -1;
	return false;
}

//
int main() {
	// since the queen can not stay at a same row
	// create 2-dimension array seems stupid
	int * arr = new int[n];
	for (int i = 0; i < n; i++) arr[i] = -1;	// -1 == no queen here !
	// calc
	recursion(0, arr);
	for (int i = 0; i < n; i++) cout << arr[i] << " "; cout << endl;
	//
	getchar();
	return 0;
}
