
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Sep 15 14:45:48 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define all(c) c.begin(), c.end()
#define u32 unsigned long
u32 n;
vector<u32> a, b;

void calc() {
	for (u32 bt = 0; bt < (n>>1); bt++) {
		a[bt] = (1ul<<30) + bt + 1;
		b[bt] = bt + 1;
	}
	// a.size() % 2 != 0 --> (1ul<<30) không triệt tiêu
	if (n>>1&1) {
		a[0] = (1ul<<29) + 1;
		b[1] = (1ul<<29) + 2;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		a.assign(n>>1, 0);
		b.assign(n>>1, 0);
		if (n >= 4) {
			calc();
			for (int i = 0; i < (n>>1); i++)
				cout << a[i] << " " << b[i] << " ";
			if (n&1)
				cout << 0;
			cout << "\n";
		} else {
			cout << "1 2 3\n";
		}
	}
	return 0;
}
