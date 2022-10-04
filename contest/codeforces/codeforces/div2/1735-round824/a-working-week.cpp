
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Oct 04 14:12:23 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

int min(int a, int b, int c) {
	if (a < b || b < c || a < 0 || b < 0) return 0;
	return min(a-b, min(b-c, a-c));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		n -= 3;
		if (n < 4) {
			cout << "0\n";
		} else {
			int c = 1, b = (n-1)/3, a = n - c - b;
			int x = min(a, b, c);
			x = max(x, min(--a, ++b, c));
			x = max(x, min(--a, ++b, c));
			cout << x << "\n";
		}
	}
	return 0;
}
