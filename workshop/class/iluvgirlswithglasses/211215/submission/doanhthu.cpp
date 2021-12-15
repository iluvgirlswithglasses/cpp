
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Dec 15 18:27:26 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

// bài này con lười, con sẽ trâu O(n^2)
const int N = 1e3+7;
int n, s, a[N];
int res = N;

int main() {
	freopen("DOANHTHU.INP", "r", stdin);
	freopen("DOANHTHU.OUT", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}
	//
	for (int i = 1; i <= n; i++) 
	for (int j = i-1; j >= 0; j--) {
		if (a[i] - a[j] >= s) {
			res = min(res, i-j);
			break;
		}
	}
	//
	if (res == N) {
		cout << "-1\n";
	} else {
		cout << res << "\n";
	}
	return 0;
}

