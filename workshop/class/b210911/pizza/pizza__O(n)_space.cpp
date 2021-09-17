#include <algorithm>
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
// sorting O(nlogn)
// two pointers O(n)
int calc() {
	sort(arr, arr+n, [](int i, int j){
		return i < j;
	});
	//
	int res = 0, l = 0, r = n-1;
	while (l < r) {
		int s = arr[l] + arr[r];
		//
		if (s == price) {
			l++; r--;
			res++;
		} else if (s < price) {
			l++;
		} else {
			r--;
		}
	}
	//
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

