#include <bits/stdc++.h>
using namespace std;

//
int n, m;
int ** arr;

//
int movs = 4;
int aMov[2][4] = {
	{-1, -1, 0, 0},
	{0, 0, -1, -1},
};
int bMov[2][4] = {
	{0, -1, -1, 0},
	{-1, 0, 0, -1},
};

// use this instead of cout in real test
ofstream out("brothers.out");

// debug
void print_arr(int ** arr) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << "\t";
		} cout << endl;
	} cout << endl;
}

// utils
int ** clone_arr(int ** arr) {
	int ** res = new int*[n];
	//
	for (int i = 0; i < n; i++) {
		res[i] = new int[m];
		//
		for (int j = 0; j < m; j++) {
			res[i][j] = arr[i][j];
		}
	}
	//
	return res;
}

// calc_arr(arrA, 1, 0); calc_arr(arrB, 0, 1);
void calc_arr_a(int ** arr) {
	for (int j = 1; j < m; j++) {
		arr[0][j] = 0;
	}
	for (int i = 0; i < n; i++) {
		arr[i][m-1] = 0;
	}
	// first col
	for (int i = 2; i < n; i++) {
		arr[i][0] += arr[i-1][0];
	}
	// first row
	for (int j = 1; j < m - 1; j++) {
		arr[1][j] += arr[1][j-1];
	}
	// the rest
	for (int i = 2; i < n; i++) {
		for (int j = 1; j < m - 1; j++) {
			arr[i][j] += max(arr[i-1][j], arr[i][j-1]);
		}
	}
}

void calc_arr_b(int ** arr) {
	for (int j = 0; j < m; j++) {
		arr[n-1][j] = 0;
	}
	for (int i = 0; i < n; i++) {
		arr[i][0] = 0;
	}
	// first col
	for (int i = 1; i < n-1; i++) {
		arr[i][1] += arr[i-1][1];
	}
	// first row
	for (int j = 2; j < m; j++) {
		arr[0][j] += arr[0][j-1];
	}
	// the rest
	for (int i = 1; i < n-1; i++) {
		for (int j = 2; j < m; j++) {
			arr[i][j] += max(arr[i-1][j], arr[i][j-1]);
		}
	}
}

int * move_to(int * pos, int moveSet[][4], int mov) {
	int i = pos[0] + moveSet[0][mov], j = pos[1] + moveSet[1][mov];
	return new int[2]{i, j};
}

bool is_safe(int * pos) {
	int i = pos[0], j = pos[1];
	return i >= 0 && j >= 0 && i < n && j < m;
}

bool overlaped(int * a, int * b) {
	return a[0] == b[0] && a[1] == b[1];
}

int get_val(int ** arr, int * pos) {
	return arr[ pos[0] ][ pos[1] ];
}

// main
void recursion(int & s, int ** arrA, int ** arrB, int * crA, int * crB) {
	// printf("%d %d - %d %d\n", crA[0], crA[1], crB[0], crB[1]);
	//
	s += get_val(arr, crA) + get_val(arr, crB);
	if (crA[0] == 1 && crA[1] == 0) return;
	//
	int * bestA; int * bestB;
	int bestVal;
	//
	for (int i = 0; i < movs; i++) {
		int * nxtA = move_to(crA, aMov, i);
		int * nxtB = move_to(crB, bMov, i);
		if (overlaped(nxtA, nxtB)) continue;
		//
		if (is_safe(nxtA) && is_safe(nxtB)) {
			int crVal = get_val(arrA, nxtA) + get_val(arrB, nxtB);
			if (crVal > bestVal) {
				bestVal = crVal;
				bestA = nxtA;
				bestB = nxtB;
			}
		}
	}
	//
	recursion(s, arrA, arrB, bestA, bestB);
}

int calc() {
	//
	int ** arrA = clone_arr(arr); calc_arr_a(arrA);
	int ** arrB = clone_arr(arr); calc_arr_b(arrB);
	//
	// print_arr(arr);
	// print_arr(arrA); print_arr(arrB);
	//
	int s = 0;
	//
	recursion(s, arrA, arrB, new int[2]{n-1, m-2}, new int[2]{n-2, m-1});
	//
	return s;
}

//
void get_inp() {
	ifstream inp("brothers.inp");
	inp >> n; inp >> m;
	//
	arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
		for (int j = 0; j < m; j++) {
			inp >> arr[i][j];
		}
	}
}

//
int main() {
	get_inp();
	cout << calc();
	//
	getchar();
	return 0;
}
