
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Nov 16 20:35:39 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <stdio.h>

#define ll long long
ll n, a, b, c, d, x, y;

ll abs(ll x) {
	if (x < 0ll) return -x;
	return x;
}

int main() {
	scanf("%Ld %Ld %Ld %Ld %Ld", &n, &a, &b, &c, &d);
	x = abs(a-b);
	y = abs(c-d);
	if ((x&1) == (y&1)) {
		printf("yes\n");
	} else {
		printf("no\n");
	}
	return 0;
}

