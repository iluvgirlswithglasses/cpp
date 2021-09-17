#include <iostream>
#include <math.h>
using namespace std;

const int N = 2e5+7, K = 18;
int plog[N];
int n, mr[N], st[N][K];

void build() {
	int k = ceil(log(n)) + 1;
	for (int j = 1; j <= k; j++) {
		for (int i = 0; i + (1<<j) <= n; i++) {
			st[i][j] = min(
				st[i][j-1],
				st[i + (1<<(j-1))][j-1]
			);
		}
	}
}

int get(int l, int r) {
	int j = plog[r - l + 1];
	// [l; r] = [l; l + (1<<j) - 1] giao [r - (1<<j) + 1; r];
	return min(
		st[l][j],
		st[r - (1<<j) + 1][j]
	);
}

bool find() {
	int c = -1;
	for (int i = 0; i < n-2; i++) {
		c = max(c, st[i][0]);
		int l = i+2, r = n-1;
		while (l < r) {
			int m = (l + r + 1) >> 1;
			if (
				get(i+1, m-1) >= c && mr[m] >= c
			) {
				l = m;
			} else {
				r = m-1;
			}
		}
		if (c == get(i+1, l-1) && c == mr[l]) {
			cout << "YES\n";
			cout << i+1 << " " << l-i-1 << " " << n-l << "\n";
			return true;
		}
	}
	//
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	plog[1] = 0;
	for (int i = 2; i < N; i++)
		plog[i] = plog[i/2] + 1;
	//
	int t; cin >> t;
	while (t--) {
		cin >> n;
		mr[n] = 0;
		for (int i = 0; i < n; i++) 
			cin >> st[i][0];
		for (int i = n-1; i > 0; i--) 
			mr[i] = max(st[i][0], mr[i+1]);
		//
		build();
		if (!find()) cout << "NO\n";
	}
	return 0;
}
