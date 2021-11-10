
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Nov 10 19:36:05 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int N = 1e4+7, M = 7;
int n, m, a[N][M];

const char* calc() {
	// top-left cell remains
	int tlr = a[0][0] % 7;
	// there ain't enough column
	if (7 - tlr < m) return "No";
	// the first row
	for (int i = 1; i < m; i++) {
		if (
			a[0][i-1] + 1 != a[0][i]
		) return "No";
	}
	// the other row
	for (int i = 1; i < n; i++) 
	for (int j = 0; j < m; j++) {
		if (a[i-1][j] + 7 != a[i][j]) return "No";
	}
	//
	return "Yes";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++) {
		int x; cin >> x;
		a[i][j] = --x;
	}
	//
	cout << calc() << "\n";
	return 0;
}

