
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Sep 18 13:03:14 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// nên tăng độ khó

#include <iostream>
using namespace std;

const int I = 1e4+7;
int l, r, sum[I];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> l >> r;
	for (int i = 2; i < (I>>1); i++) {
		for (int j = i<<1; j < I; j += i) {
			sum[j] += i;
		}
	}
	//
	int res = 0;
	for (int i = l; i <= r; i++)
		if (sum[i] > i) res++;
	cout << res << "\n";
	for (int i = l; i <= r; i++)
		if (sum[i] > i) cout << i << " ";
	cout << "\n";
	return 0;
}
