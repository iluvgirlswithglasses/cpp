
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct 16 12:49:00 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

int __gcd(int a, int b) {
	if (b == 0) return a;
	return __gcd(b, a%b);
}

int gcd(int a, int b) {
	if (b > a) 
		return __gcd(b, a);
	return __gcd(a, b);
}

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 42;
int n, a[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		//
		int k = 0, b = *min_element(a, a+n);
		for (int i = 0; i < n; i++)
			k = gcd(k, a[i]-b);
		//
		if (k == 0) k = -1;
		cout << k << "\n";
	}
	return 0;
}

