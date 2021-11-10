
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Nov 10 15:26:18 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int N = 1e3+7;
int n, m, q, a[N][N], b[N];

bool check(int i) {
	for (int j = 0; j < m; j++) if (b[j] != -1) {
		if (b[j] != a[i][j]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		cin >> a[i][j];
	cin >> q;
	while (q--) {
		for (int i = 0; i < m; i++)
			cin >> b[i];
		//
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (check(i)) cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}

