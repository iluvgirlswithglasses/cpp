#include <iostream>
using namespace std;

//@ vars
const int nlim = 1001;
const int alim = 1002;
int n, a;
int appear[alim];
int choice, self;
long long int method;

//@ utils
long long int calc_cols(int a) {
	// return aC2
	long long int res = 1;
	for (int i = a - 1; i <= a; i++) {
		res *= i;
	}
	return res >> 1;
}

//@ driver
int main() {
	// getinp
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		appear[a] += 1;
	}
	for (int i = 1; i < alim; i++) {
		if (appear[i] >= 2) choice += 1;
		if (appear[i] >= 4) self += 1;
	}
	//
	method = (long long int) self + calc_cols(choice);
	cout << method << endl;
	//
	return 0;
}
