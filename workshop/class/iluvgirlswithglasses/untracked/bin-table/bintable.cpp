#include <iostream>
using namespace std;

//@ vars
int n, k, s;

//@ perf
bool check(int i, int j) {
	int pattern_i = i % k, pattern_j = j % k;
	return pattern_i*k + pattern_j < s;
}

//@ drivers
int main() {
	//
	cin >> n >> k >> s;
	//
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << check(i, j) << " ";
		} cout << endl;
	}
	// returns
	cin >> n;
	return 0;
}
