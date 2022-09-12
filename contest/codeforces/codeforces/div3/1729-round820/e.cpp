
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Sep 12 22:58:56 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <cstdio>
using namespace std;

#define ll long long
const ll LIM = 12;

ll rep;

ll max(ll a, ll b) {
	return a > b ? a : b;
}

ll min(ll a, ll b) {
	return a < b ? a : b;
}

int main() {
	ll l = 3, r = 1e18;
	// try to reduce `r`
	for (ll i = 1; i <= LIM; i++) {
		printf("? %lld %lld\n", i, i+2);
		fflush(stdout);
		//
		scanf("%lld", &rep);
		if (rep != -1ll) {
			l = max(l, rep);
			r = min(r, rep<<1);
		} else {
			break;
		}
	}
	//
	while (l < r) {
		ll m = (l+r+1)>>1;
		printf("? 1 %lld\n", m);
		fflush(stdout);
		//
		scanf("%lld", &rep);
		if (rep == -1ll)
			r = m-1;
		else
			// if the path is > m
			// n is > m
			l = max(m, max(rep, r));
	}
	printf("! %lld\n", l);
	fflush(stdout);
	return 0;
}
