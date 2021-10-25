
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Oct 25 08:38:45 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e3+7;
int n, h, x, y, a[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> h;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		//
		int *p = max_element(a, a+n);
		x = *p;
		*p = 0;
		p = max_element(a, a+n);
		y = *p;
		//
		int turn = (h/(x+y))<<1;
		h %= x+y;
		if (h > x) 
			turn += 2;
		else if (h > 0) 
			turn += 1;
		cout << turn << "\n";
	}
	return 0;
}

