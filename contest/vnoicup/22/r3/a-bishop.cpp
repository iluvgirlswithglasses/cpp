
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Jul  6 16:50:55 2022
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

int n, q, a, b, c, d, k, l, x, y;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	while (q--) {
		cin >> a >> b >> c >> d;
		if (a == c && b == d) {
			// already there
			cout << "0\n";
		} else if (abs(a-c) == abs(b-d)) {
			// if can move in one
			cout << 1 << "\n" << c << " " << d << "\n";
		} else if ((abs(a-b)&1) == (abs(c-d)&1)) {
			// if two cell is still the same color
			// line 1:	y = -x + k 	|| y =  x + k
			// line 2:	y =  x + l 	|| y = -x + l
			// 1x2:		x + l + x - k = 0 --> 2x = k - l
			//			x + k + x - l = 0 --> 2x = l - k
			k = b + a;
			l = d - c;
			x = (k - l) >> 1;
			y = x + l;
			if (x <= 0 || x > n || y <= 0 || y > n) {
				k = b - a;
				l = d + c;
				x = (l - k) >> 1;
				y = -x + l;
			}
			cout << 2 << "\n";
			cout << x << " " << y << "\n";
			cout << c << " " << d << "\n";
		} else {
			// can not move
			cout << "-1\n";
		}
	}
	return 0;
}
