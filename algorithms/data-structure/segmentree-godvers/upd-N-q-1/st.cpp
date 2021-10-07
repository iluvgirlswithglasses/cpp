#include <iostream>
using namespace std;

const int N = 1e5+7;
int n, t[N<<1];

void update(int l, int r, int v) {
	for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
		if (l&1) t[l++] += v;
		if (r&1) t[--r] += v;
	}
}

int query(int p) {
	int res = 0;
	for (p+=n; p > 0; p>>=1) {
		res += t[p];
	}
	return res;
}

void push() {
	for (int i = 1; i < n; i++) {
		t[i<<1] += t[i];
		t[i<<1|1] += t[i];
		t[i] = 0;
	}
}

int typ, l, r, p, v;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> t[i+n];
	//
	while (true) {
		cin >> typ;
		if (typ) {
			cin >> p;
			cout << query(p) << "\n";
		} else {
			cin >> l >> r >> v;
			update(l, r, v);
		}
	}
}
