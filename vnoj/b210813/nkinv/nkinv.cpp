#include <iostream>
using namespace std;

#define ll long long

//
const int N = 6e4+7;
int n, f[N];

//
void update(int v) {
	while (v > 0) {
		f[v]++;
		v -= v & (-v);
	}
}

ll get(int v) {
	ll res = 0;
	while (v < N) {
		res += f[v];
		v += v & (-v);
	}
	//
	return res;
}

//
int main() {
	cin >> n;
	ll res = 0;
	for (int i = 0; i < n; i++) {
		int v; cin >> v;
		res += get(v+1);
		update(v);
	}
	cout << res << endl;
	//
	system("pause");
	return 0;
}
