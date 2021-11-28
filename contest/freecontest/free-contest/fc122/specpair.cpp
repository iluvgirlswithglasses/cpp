
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Nov 28 14:23:20 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

/** defs */
const int N = 2e5+7, I = 2e6+7;
const int spc[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99, 111, 222, 333, 444, 555, 666, 777, 888, 999, 1111, 2222, 3333, 4444, 5555, 6666, 7777, 8888, 9999, 11111, 22222, 33333, 44444, 55555, 66666, 77777, 88888, 99999, 111111, 222222, 333333, 444444, 555555, 666666, 777777, 888888, 999999, 1111111};
const int S = sizeof(spc) / sizeof(spc[0]);

/** vars */
int n, a, cnt[I];
long long res;

/** drivers */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = upper_bound(spc, spc+S, a) - spc; j < S; j++) {
			int target = spc[j] - a;
			res += cnt[target];
		}
		//
		cnt[a]++;
	}
	cout << res << "\n";
	return 0;
}
