#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+7;
int n, arr[N];

long double calc() {
	long double sl = 0, sm = 0;
	long double res = -2e9 - 7, cr;
	for (int i = 0; i < n; i++) sm += arr[i];
	//
	for (int i = 0; i < n-1; i++) {
		sl += arr[i];
		sm -= arr[i];
		//
		cr = sl / (i+1) + sm / (n - i - 1);
		if (cr <= res) return res;
		res = cr;
	}
	//
	return -1;
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		sort(arr, arr+n, [](int i, int j){
			return i > j;
		});
		long double res = calc();
		cout << res << endl;
	}
	// system("pause");
	return 0;
}
