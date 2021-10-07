#include <iostream>
using namespace std;

// vars
const int lim = 1e4;
int n, q;
int t[lim<<1];


// segment tree
void build() {
	// segment tree starts with 1
	for (int i = n - 1; i > 0; i--)
		t[i] = t[i<<1] + t[i<<1|1];
}

void update(int p, int v) {
	t[n + p] = v;
	for (int i = (n + p) >> 1; i > 0; i >>= 1) {
		t[p >> 1] = t[p] + t[p^1];
	}
}

int query(int l, int r) {
	int res = 0;
	//
	for (l += n, r += n; r > l; l >>= 1, r >>= 1) {
		if (l&1) res += t[l++];
		if (r&1) res += t[--r];
	}
	//
	return res;
}


// drivers
void getinp() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> t[n + i];
	}
	build();
}

int main() {
	getinp();
	while (q--) {
		int p, a, b; cin >> p >> a >> b;
		if (p) {
			cout << query(a, b) << endl;
		} else {
			update(a, b);
			for (int i = 0; i < n; i++) cout << t[n + i] << " ";
			cout << endl;
		}
	}
	//
	system("pause");
	return 0;
}
