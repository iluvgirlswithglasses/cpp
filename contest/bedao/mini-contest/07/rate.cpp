
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Nov 14 20:04:01 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <bits/stdc++.h>
using namespace std;

const int L = 1e6+7;
int n = 0, m = 1e9+7;
vector<bool> mat[L];

void getmat() {
	int l; string s;
	cin >> l >> s;
	for (char c: s) {
		if (c == '#') {
			n++;
		} else {
			int i = c;
			for (int j = 6; j >= 0; j--) {
				mat[n].push_back(i>>j&1);
			}
		}
	}
	//
	n++;
	for (int i = 0; i < n; i++) {
		m = min(m, (int) mat[i].size());
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	getmat();
	cout << n << " " << m << "\n";
	// for (int i = 0; i < n; i++) {
	// 	for (bool j: mat[i]) cout << j;
	// 	cout << "\n";
	// }
	//
	int a = 0, b = 0;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++) {
		if (mat[i][j]) 
			a++;
		else 
			b++;
	}
	long double res = a;
	res /= b;
	cout << setprecision(9) << fixed << res << "\n";
	return 0;
}

