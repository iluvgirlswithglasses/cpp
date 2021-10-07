#include <unordered_set>
#include <iostream>
using namespace std;

/**
 * vars
 * */
const int nlim = 1e5;
int price, n, arr[nlim];

/**
 * perf
 * */
// O(n) with std::map
int calc() {
	int res = 0;
	unordered_set<int> m;
	for (int i = 0; i < n; i++) {
		// if find a number that can make pair with this one
		// also:
		// since each friend helds a unique amount of money
		// we don't even need to do anything more than this
		if (m.find(price - arr[i]) != m.end()) {
			res ++;
		}
		m.insert(arr[i]);
	}
	return res;
}

/**
 * drivers
 * */
int main() {
	//
	int t; cin >> t;
	while (t--) {
		// inp
		cin >> n >> price;
		for (int i = 0; i < n; i++) cin >> arr[i];
		// calc
		cout << calc() << endl;
	}
	//
	return 0;
}

