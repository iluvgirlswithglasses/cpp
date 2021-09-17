#include <iostream>
using namespace std;

const int N = 57;
int n, mat[N][N];

int sqrt(int a) {
	for (int i = 1; i * i <= a; i++) {
		if (i * i == a) return i;
	}
	return a;
}

void calc() {
	for (int i = 0; i < n; i++) {
		cout << sqrt(mat[i][i]) << " ";
	} cout << endl;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	//
	calc();
	//
	system("pause");
	return 0;
}

