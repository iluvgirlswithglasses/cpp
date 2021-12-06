
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Dec  6 13:56:07 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define ll long long
const int N = 1e5+7;
int n, arr[N], len[N];
ll  le, ri;

ll pow10(int n) {
	ll res = 1;
	for (int i = 0; i < n; i++)
		res *= 10;
	return res;
}

/**
 * concat(a, b)
 * == a * 10^(len[b]) + b
 * */
int get_l(int l, int r, int j) {
	int b = arr[j];
	ll  bpow = pow10(len[j]);
	// nghiệm phải
	if (le > bpow * arr[r] + b) return r+1;
	//
	while (l < r) {
		int m = (l + r) >> 1;
		if (le <= bpow * arr[m] + b) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	return r;
}

int get_r(int l, int r, int j) {
	int b = arr[j];
	ll  bpow = pow10(len[j]);
	// nghiệm trái
	if (bpow * arr[l] + b > ri) return r+1;
	//
	while (l < r) {
		int m = (l + r + 1) >> 1;
		if (bpow * arr[m] + b <= ri) {
			l = m;
		} else {
			r = m - 1;
		}
	}
	return l;
}

/**
 * drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> le >> ri;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr+n);
		for (int i = 0; i < n; i++)
			len[i] = to_string(arr[i]).length();
		//
		ll res = 0;
		for (int i = 0; i < n; i++) {
			int l = get_l(0, n-1, i), r = get_r(0, n-1, i);
			if (l != n && r != n) {
				res += r - l + 1;
			}
		}
		cout << res << "\n";
	}
	return 0;
}
