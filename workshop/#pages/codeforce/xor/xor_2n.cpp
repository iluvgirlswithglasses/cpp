#include <iostream>
using namespace std;

typedef long long int lli;

//
bool calc() {
	int n; cin >> n;
	//
	lli * arr = new lli[n];
	lli xo = 0;
	//
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		xo ^= arr[i];
	}
	// even case
	if (xo == 0) {
		delete[] arr;
		return true;
	}
	// odd case
	lli temp = 0;
	int counters = 0;
	for (int i = 0; i < n; i++) {
		temp ^= arr[i];
		if (temp == xo) {
			// can't break
			// cuz if I do, I won't know if the last stuffs would == xo or not
			counters += 1;
			temp = 0;
		}
	}
	if (temp == 0 && counters >= 2) {
		// temp == 0 if temp == xo in previous loop
		delete[] arr;
		return true;
	}
	// meh case
	delete[] arr;
	return false;
}

int main() {
	int t; cin >> t;
	while (t--) {
		if (calc()) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	//
	return 0;
}
