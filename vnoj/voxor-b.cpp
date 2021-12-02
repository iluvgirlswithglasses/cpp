
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Dec  2 17:21:00 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
using namespace std;

const int N = 1e3+7;
int n, q, x, a[N];

void dec2bin(int n) {
	if (n == 0) return;
	dec2bin(n>>1);
	cout << (n%2);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	//
	while (q--) {
		string typ; cin >> typ;
		if (typ == "FIND") {

		} else {
			int x; cin >> x;
			for (int i = 0; i < n; i++)
				a[i] ^= x;
		}
	}
	//
	for (int i = 0; i < n; i++) {
		dec2bin(a[i]); cout << "\n";
	}
	return 0;
}
