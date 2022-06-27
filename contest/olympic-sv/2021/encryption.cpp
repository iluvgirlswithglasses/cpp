
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Jun 26 12:05:35 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cmath>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define ld long double
#define pi pair<int, int>
#define st first
#define nd second

/*
as = km --> as/k in Z (1)
with g = gcd(a, k), x = a/g, y = k/g
	--> (1) <=> xs/y in Z <=> s = ny
*/

ll l, r, a, k, g, x, y;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> l >> r >> a >> k;
	g = gcd(a, k);
	y = k/g;
	//
	l = ceil((ld) l / y) * y;
	r = floor((ld) r / y) * y;
	cout << (r - l) / y + 1 << "\n";
	return 0;
}
