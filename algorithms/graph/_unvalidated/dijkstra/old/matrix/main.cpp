// reference: Chuyên Lê Quý Đôn 2011 > Hội chợ
// we don't have to print the solution in 2021
// so the dijkstra parent algorithm is skipped
#include <climits>
#include <iostream>
#include <fstream>
using namespace std;

//
int n, m;
int ** arr;
//
int movs = 4;
int y_mov[movs] = {0, 0, 1, -1};
int x_mov[movs] = {1, -1, 0, 0};

// debug
void print_arr(int ** arr) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		} cout << endl;
	} cout << endl;
}

// utils
void set_init_min(int ** res) {
	int index = 0, lowest = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (res[i][0] < lowest) {
			index = i;
			lowest = res[i][0];
		}
	}
	//
	res[index][0] = arr[index][0];
}

int * get_min(int ** res, bool ** spt) {
	int y, x, lowest = INT_MAX;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// if ... && not included in spt
			if (res[i][j] < lowest && !spt[i][j]) {
				y = i; x = j; lowest = res[i][j];
			}
		}
	}
	//
	return new int[2]{y, x};
}

//
int dijkstra() {
	//
	int ** res = new int*[n];
	bool ** spt = new bool*[n];
	//
	for (int i = 0; i < n; i++) {
		res[i] = new int[m];
		spt[i] = new bool[m];
		//
		for (int j = 0; j < m; j++) {
			res[i][j] = INT_MAX;
			spt[i][j] = false;
		}
	}
	set_init_min(res);
	//
	while (true) {
		//
		int * loc = get_min(res, spt);
		if (loc[1] == m - 1) {
			// if found the min weighted path that leads to last column
			return res[ loc[0] ][ loc[1] ];
		}
		//
		spt[ loc[0] ][ loc[1] ] = true;
		//
		for (int mov = 0; mov < movs; mov++) {
			int i = loc[0] + y_mov[mov], 
				j = loc[1] + x_mov[mov];
			if (i >= 0 && j >= 0 && i < n && j < m) {
				res[i][j] = min(
					res[i][j], res[ loc[0] ][ loc[1] ] + arr[i][j]
				);
			}
		}
	}
	//
	return -1;
}

// io
void get_inp() {
	ifstream inp("inp.txt");
	inp >> n; inp >> m;
	//
	arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
		//
		for (int j = 0; j < m; j++) {
			inp >> arr[i][j];
		}
	}
	//
}

// driver
int main() {
	get_inp();
	cout << dijkstra();
	//
	system("pause");
	return 0;
}
