
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Nov 30 13:37:03 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

/**
 * @defs
 * */
int __gcd(int a, int b) {
	if (b == 0) return a;
	return __gcd(b, a%b);
}

int gcd(int a, int b) {
	if (b > a) return __gcd(b, a);
	return __gcd(a, b);
}

/**
 * @vars
 * */
const int N = 1e5+7;
int n, f[N<<1];
int len = N, le, ri;

int query(int l, int r) {
	l += n, r += n + 1;
	int res = f[l];
	for (; l < r; l>>=1, r>>=1) {
		if (l&1) res = gcd(res, f[l++]);
		if (r&1) res = gcd(res, f[--r]);
	}
	return res;
}

/**
 * @drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> f[n+i];
	for (int i = n-1; i >= 1; i--)
		f[i] = gcd(f[i<<1], f[i<<1|1]);
	//
	for (int l = 0, r = 1; r < n; r++) {
		while (query(l, r) == 1) {
			if (r - l + 1 < len) {
				len = r - l + 1;
				le = l;
				ri = r;
			}
			l++;
		}
	}
	//
	if (len != N) {
		cout << len << " " << le+1 << " " << ri+1 << "\n";
	} else {
		cout << "-1\n";
	}
	return 0;
}
