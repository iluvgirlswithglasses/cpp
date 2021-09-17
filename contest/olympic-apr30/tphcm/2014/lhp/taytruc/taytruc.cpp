#include <bits/stdc++.h>
using namespace std;

//
int n, m;
int * arr;

//
bool comparator(int i, int j, int * kcols) {
	int remains = kcols[j] - (i - j - 1);
	return false;
}

int calc() {
	int * res = new int[n];
	int * kcols = new int[n];
	for (int i = 0; i < n; i++) {
		res[i] = arr[i];
		for (int j = 0; j < i; j++) {
			if (comparator(i, j, kcols) && res[j] + arr[i] > res[i]) {
				res[i] = res[j] + arr[i];
			}
		}
	}
	//
	return res[n-1];
}

//
void getinp() {
	ifstream inp("taytruc.inp");
	inp >> n >> m;
	arr = new int[n];
	//
	for (int i = 0; i < n; i++) inp >> arr[i];
}

int main() {
	getinp();
	cout << calc();
	//
	getchar();
	return 0;
}
