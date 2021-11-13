
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Nov 12 16:27:52 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/* 
vnoj/v11water 
*/

#include <iostream>
using namespace std;

#define ll long long

const int N = 1e6+7;
const ll  I = 1e9+7;
int n;
ll a[N], l[N], r[N];

ll base() {
	ll res = 0;
	for (int i = 2; i < n; i++) {
		int add = min(l[i-1], r[i+1]) - a[i];
		if (add > 0) 
			res += add;
	}
	return res;
}

ll exts() {
	int res = 0, cr = 0;
	for (int i = 2; i < n; i++) {
		if (
			l[i-1] >= a[i] && 
			r[i+1] >= a[i] && 
			abs(l[i-1] - r[i+1]) > 0
		) {
			res = max(res, ++cr);
		} else {
			cr = 0;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	// made one mistake here
	// i = 1, but typed i = 2
	// took me a day to debug
	for (int i = 1; i <= n; i++)
		l[i] = max(l[i-1], a[i]);
	for (int i = n; i >= 1; i--)
		r[i] = max(r[i+1], a[i]);
	//
	cout << base() + exts() << "\n";
	return 0;
}

