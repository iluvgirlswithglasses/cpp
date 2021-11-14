
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Nov 14 13:00:21 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e9+7, M = 1e6+7;
int n, m, a[M];

bool check(int mid) {
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		cnt += a[i] / mid;
		if (a[i] % mid > 0) cnt++;
		// có hoa thừa --> false
		// return ở đây để chặn tràn số
		if (cnt > n) return false;	
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> a[i];
	//
	int l = 1, r = *max_element(a, a+m);
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			// giảm đc tí xíu nè
			r = mid;
		} else {
			// k giảm đc nè 
			l = mid+1;
		}
	}
	cout << r << "\n";
	return 0;
}

