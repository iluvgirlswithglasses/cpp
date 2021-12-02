
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Dec  2 14:09:36 2021
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

/**
 * @defs & @vars
 * */
const int N = 1e5+7, I = 2e6+7;
int n, a;
long long res;

/**
 * @utils
 * 
 * sqr[i] = ceil( sqrt(i) )
 * exx[i] = floor( i^(3/2) ) = floor( i*sqrt(i) )
 * 
 * a[j] - a[i] = sqr[j] + exx[i]
 * --> a[j] - sqr[j] = a[i] + exx[i]
 * 
 * cnt[x]: số số thỏa a[i] + exx[i] == x
 * */
int sqr[N], exx[N];
int cnt[I];

void init() {
	sqr[1] = 1;
	exx[1] = 1;
	for (int i = 2; i < N; i++) {
		double s = sqrt((double) i);
		sqr[i] = ceil(s); 
		exx[i] = floor(s * i);
	}
	// for (int i = 1; i < 20; i++)
	// 	cout << sqr[i] << " " << exx[i] << "\n";
}

/**
 * @drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	init();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		res += cnt[a - sqr[i]];
		if (a + exx[i] < I)
			cnt[a + exx[i]]++;
	}
	cout << res << "\n";
	return 0;
}
