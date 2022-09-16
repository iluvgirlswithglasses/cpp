
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

const int N = 5007;
int n, a[N];

int main() {
	// io
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("inp.txt"); cin.rdbuf(fin.rdbuf());
	// timer
	system_clock::time_point start = system_clock::now();
	// work
	cin >> n;
	int res = 0, left, right, mid;
	//
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; a[i] += a[i-1];
		//
		for (int k = 1; k < i; k++) {
			int right_sum = a[i] - a[k];
			//
			int v = a[k] - right_sum, l = 1, r = k;
			while (l < r) {
				int m = (l + r + 1) >> 1;
				if (a[m] <= v) {
					l = m;
				} else {
					r = m - 1;
				}
			}
			//
			if (right_sum == a[k] - a[l])
				if (i - l > res) {
					res = i - l;
					left = l;
					right = i;
					mid = k;
				}
		}
	}
	cout << res << endl;
	// timer
	duration<double> diff = system_clock::now() - start;
	cout << "Time passed since the program first started: ";
	cout << diff.count() << "s" << endl;
	return 0;
}
