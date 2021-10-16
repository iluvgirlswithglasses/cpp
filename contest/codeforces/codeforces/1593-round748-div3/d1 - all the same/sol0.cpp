
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct 16 11:54:07 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

// the easier version of 
// OLP Can Tho 19: SEQ

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
using namespace std;

const int N = 41;
int n, a[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int x = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				x = gcd(abs(a[i] - a[j]), x);
			}
		}
		if (x == 0) x = -1;
		cout << x << "\n";
	}
	return 0;
}

