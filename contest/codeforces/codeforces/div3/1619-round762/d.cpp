
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Dec 22 11:22:41 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define mat vector<vector<int>>

bool check(int m, int n, mat& p, int c) {
	vector<bool> got(n, false);
	int doubled = false;
	//
	for (int i = 0; i < m; i++) {
		int here = 0;
		for (int j = 0; j < n; j++) {
			if (p[i][j] >= c) {
				got[j] = true;
				here++;
			}
		}
		if (here >= 2) doubled = true;
	}
	//
	return doubled && find(got.begin(), got.end(), false) == got.end();
}

int calc(int m, int n, mat& p) {
	int l = 1, r = 1e9+7;
	while (l < r) {
		int c = (l + r + 1) >> 1;
		if (check(n, m, p, c)) {
			l = c;
		} else {
			r = c - 1;
		}
	}
	return l;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int m, n;
		cin >> m >> n;
		mat p(m, vector<int>(n));
		for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			cin >> p[i][j];
		}
		cout << calc(n, m, p) << "\n";
	}
	return 0;
}

