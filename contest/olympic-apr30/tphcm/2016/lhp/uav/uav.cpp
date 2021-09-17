#include <bits/stdc++.h>
using namespace std;
ofstream out("uav.out");

//
int l, n;
int * arr;

// utils
void reverse_arr() {
	for (int i = 0; i < n / 2; i++) {
		arr[i] ^= arr[n-i-1];
		arr[n-i-1] ^= arr[i];
		arr[i] ^= arr[n-i-1];
	}
}

void print_arr(int * arr) {
	for (int i = 0; i < n; i++) cout << arr[i] << " "; cout << endl << endl;
}

// perf
int calc_u(int cr, int u) {
	if (cr + l >= n) return u + 1;
	//
	for (int j = l + cr; j > cr; j--) {
		if (arr[j] & 1 && arr[j] != 0) {
			return calc_u(j, u + 1);
		}
	}
	return -1;	// nah this won't happen cuz the ques guarantee
}

int calc_v(int cr, int v) {
	reverse_arr();
	int * res = new int[n];
	//
	for (int i = 1; i < n - 1; i++) res[i] = INT_MIN / 2;
	res[0] = 1001;
	res[n-1] = 1000;
	//
	for (int i = 0; i < n; i++) {
		// nếu là số lẻ || nếu là 0 => drop
		if (arr[i] & 1 || arr[i] == 0) continue;
		//
		int subval = INT_MIN / 2;
		for (int j = max(0, i - l + 1); j < i; j++) {
			if (subval < res[j] - arr[i]) subval = res[j] - arr[i];
		}
		if (i - l >= 0) {
			res[i] = max(subval, res[i - l] + arr[i]);
		} else {
			res[i] = subval;
		}
	}
	return res[n-1];
}

//
void getinp() {
	ifstream inp("uav.inp");
	inp >> l >> n;
	//
	arr = new int[n];
	arr[0] = 1000, arr[n-1] = 1001;
	// there are only n-2 number given
	for (int i = 1; i < n - 1; i++) inp >> arr[i];
	//
}

int main() {
	getinp();
	cout << calc_u(0, 1) << endl;
	cout << calc_v(0, 1) << endl;
	//
	getchar();
	return 0;
}
