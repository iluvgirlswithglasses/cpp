#include <iostream>
#include <fstream>
using namespace std;

// moves: down / right only

// vars
int n, m;
int ** arr;

// perf
int calc(int n, int m, int ** arr) {
	// first row / col
	for (int i = 1; i < n; i++) arr[i][0] += arr[i-1][0];
	for (int i = 1; i < m; i++) arr[0][i] += arr[0][i-1];
	//
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			arr[i][j] += max(arr[i-1][j], arr[i][j-1]);
		}
	}
	//
	return arr[n-1][m-1];
}

// io
void get_inp() {
	ifstream inp("inp.txt");
	//
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
	cout << calc(n, m, arr);
	//
	system("pause");
	return 0;
}
