#include <iostream>
using namespace std;

#define ll long long

const int N = 6e4+7, I = 6e4+7;
int n, f[I];

int get(int i) {
	int res = 0;
	while (i < I) {
		res += f[i];
		i += i&-i;
	}
	return res;
}

void update(int i) {
	while (i > 0) {
		f[i]++;
		i -= i&-i;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	//
	ll res = 0;
	for (int i = 0; i < n; i++) {
		int v; cin >> v;
		res += get(v+1);
		update(v);
	}
	cout << res << "\n";
	return 0;
}
