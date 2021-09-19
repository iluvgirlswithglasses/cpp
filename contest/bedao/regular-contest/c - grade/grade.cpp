#include <iostream>
#include <vector>
using namespace std;

const int N = 1e3+1, A = 1e6+2;
int n, q;
vector<bool> cls[N];

int calc(int k) {
	int res = 0, cr = 0;
	for (int i = 0; i < n; i++) {
		if (cls[i][k]) cr++;
		else cr = 0;
		//
		res = max(res, cr);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cls[i].resize(A);
		int s, v; cin >> s;
		while (s--) {
			cin >> v;
			cls[i][v] = true;
		}
	}
	//
	while (q--) {
		int k; cin >> k;
		cout << calc(k) << "\n";
	}
	return 0;
}
