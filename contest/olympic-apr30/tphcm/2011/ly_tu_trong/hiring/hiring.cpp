#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

// since even in the case of m = n = 500
// there are only 249500 posibilities
// this is kinda safe for loop calc

// EDIT: shit I miscalculated
// 2 dimensional dynamic ?

// global
int m, n, p;	// p = x + y
int ** arr;		// arr = m * n

// use this instead of cout in real test
ofstream out;

// initializers
void init() {
	out.open("hiring.out");
}

// utils
int calc_s(int ty, int tx, int by, int bx) {
	int s = 0;
	for (int i = ty; i <= by; i++) {
		for (int j = tx; j <= bx; j++) {
			s += arr[i][j];
		}
	}
	return s;
}

// perf
int calc() {
	int best = 0;
	for (int ty = 0; ty < m; ty++) {				// top-y
		for (int tx = 0; tx < n; tx++) {			// top-x
			for (int by = ty; by < m; by++) {		// bot-y
				for (int bx = tx; bx < n; bx++) {	// bot-x
					best = max(best, calc_s(ty, tx, by, bx));
				}
			}
		}
	}
	//
	return best;
}

// io
void get_inp() {
	ifstream inp; inp.open("hiring.inp");
	int x, y;
	//
	inp >> m; inp >> n; inp >> x; inp >> y; p = x + y;
	//
	arr = new int*[m];
	for (int i = 0; i < m; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			inp >> arr[i][j];
			arr[i][j] -= p;
		}
	}
}

// drivers
int main() {
	init();
	get_inp();
	cout << calc();
	//
	getchar();
	return 0;
}
