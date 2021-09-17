#include <iostream>
using namespace std;

#define ll long long

const int N = 1e5+7;
int n, m, t, a[N], b[N];

ll quan(int arr[], int l, int t) {
	ll res = 0;
	for (int i = 0; i < l; i++)
		res += t / arr[i];
	return res;
}

ll quan(int l) {
	return min(quan(a, n, l), quan(b, m, t-l));
}

/**
 * drivers
 * */
ll calc() {
	int l = 0, h = t;
	while (l < h) {
		int mid = (l + h + 1) >> 1;
		if (quan(a, n, mid) < quan(b, m, t - mid)) {
			l = mid;
		} else {
			h = mid - 1;
		}
	}
	//
	ll res = quan(l);
	if (l <= t) res = max(res, quan(l+1));
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> b[i];
	//
	cout << calc() << endl;
	return 0;
}
