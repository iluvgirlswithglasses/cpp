#include <iostream>
using namespace std;

//
const int N = 1e5+7;
int n, q, p, arr[N];

//
void update(int i, int v) {
	i++;
	v -= arr[i];
	while (i <= n) {
		arr[i] += v;
		i += i & (-i);
	}
}

int calc(int i) {
	// sum(a[0:i]) or sum(arr[1:++i])
	i++;
	int res = 0;
	while (i > 0) {
		res += arr[i];
		i -= i & (-i);
	}
	return res;
}

//
int main() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		int v; cin >> v;
		update(i, v);
	}
	//
	while (q--) {
		cin >> p;
		if (p == 0) {
			int i, v; cin >> i >> v;
			update(i, v);
		} else {
			int i; cin >> i;
			cout << calc(i) << endl;
		}
	}
	//
	system("pause");
	return 0;
}
