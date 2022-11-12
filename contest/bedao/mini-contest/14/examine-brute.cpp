
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 12 13:55:36 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int n, n2, s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	n2 = n*n;
	for (int a = 1; a <= n; a++) {
		for (int b = a; b <= n; b++) {
			// gcd(a, b) == 1;
			int g = gcd(b*n, a*n);
			if (g != n) continue;
			int l = a * b * n * n / g;
			if (l == n2) {
				s += a + b;
				cout << a*n << " " << b*n << "\n";
			}
		}
	}
	cout << s*n << "\n";
	return 0;
}
