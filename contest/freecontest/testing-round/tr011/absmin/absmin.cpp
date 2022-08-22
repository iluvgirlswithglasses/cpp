
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Oct 07 12:10:09 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5+7, I = 2e9+7;
int n, a[N];
int res = I;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	for (int i = 1; i < n && res != 0; i++) {
		res = min(res, a[i] - a[i-1]);
	}
	cout << res << "\n";
	return 0;
}

