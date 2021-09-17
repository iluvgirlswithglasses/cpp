#include <bits/stdc++.h>
using namespace std;
ofstream out("bear.out");

// tạm ngưng: hình như ví dụ của đề sai

// strat:
// tìm cây khung nhỏ nhất
// cây nào có nhiều hơn 1 nhánh => giá thành của nhánh có giá bé hơn được nhân 2

//
int n, m;
int * escapeT;
int ** mat;

//
void printmat(int ** mat) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == INT_MAX) {
				cout << "- ";
			} else {
				cout << mat[i][j] << " ";
			}
		} cout << endl;
	} cout << endl;
}

//
void getinp() {
	ifstream inp("bear.inp");
	inp >> n >> m;
	//
	escapeT = new int[n];
	for (int i = 0; i < n; i++) {
		inp >> escapeT[i];
	}
	for (int i = 0; i < n; i++) cout << escapeT[i] << " "; cout << endl << endl;
	//
	mat = new int*[n];
	for (int i = 0; i < n; i++) {
		mat[i] = new int[n];
		for (int j = 0; j < n; j++) {
			mat[i][j] = INT_MAX;	// can't travel
		}
	}
	//
	for (int i = 0; i < m; i++) {
		//
		int a, b, t; inp >> a >> b >> t;
		a -= 1; b -= 1;
		cout << a << " " << b << " " << t << endl;
		mat[a][b] = min(t, mat[a][b]);
		mat[b][a] = min(t, mat[b][a]);
	} cout << endl;
}

int main() {
	getinp();
	printmat(mat);
	//
	getchar();
	return 0;
}
