
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Nov 14 20:16:59 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define u64 unsigned long long int
const int N = 37;

u64 n, x, a[N];

int calc() {
	int res = 0;
	for (u64 mk = 1; mk < (1<<n); mk++) {
		u64 k = 0, s = 0;
		for (u64 i = 0; i < n; i++) if (mk>>i&1) {
			k++;
			s += a[i];
		}
		if (s % k == 0 && s / k == x) res++;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> x;
	for (u64 i = 0; i < n; i++) cin >> a[i];
	//
	cout << calc() << "\n";
	return 0;
}

