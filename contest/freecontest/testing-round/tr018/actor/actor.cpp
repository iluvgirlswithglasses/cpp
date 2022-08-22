#include <iostream>
#include <algorithm>
using namespace std;

const int T = 3;
int n, arr[T];

int calc_min() {
	int discard = 0;
	for (int i = 0; i < T; i++) discard += n - arr[i];
	return max(0, n - discard);
}

int calc_max() {
	return *min_element(arr, arr + T);
}

int main() {
	int r, t; cin >> r >> t;
	while (t--) {
		cin >> n >> arr[0] >> arr[1] >> arr[2];
		if (r == 1) {
			cout << calc_min() << endl;
		} else {
			cout << calc_max() << endl;
		}
	}
	return 0;
}
