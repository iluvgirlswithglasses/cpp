
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct 30 15:05:05 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <cmath>
using namespace std;

#define u64 unsigned long long
const int R = 1e9+7;

int n;
u64 res = 1;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	n++;
	for (u64 i = 0; i < (1<<n); i++) {
		u64 cr = 1;
		for (int j = 2; j < n; j++) {
			if (i>>j&1) cr *= j;
		}
		//
		u64 t = floor(sqrt(cr));
		if (t*t == cr) res = max(res, cr);
	}
	cout << (res % R) << "\n";
	return 0;
}

