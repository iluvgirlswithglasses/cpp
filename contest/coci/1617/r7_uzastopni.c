
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Nov 19 01:27:41 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <stdio.h>

#define ll long long
ll x;

// upgraded from c++ to c
int main() {
	scanf("%Ld", &x); x <<= 1;
	for (ll n = 2; n*(n-1) < x; n++) {
		if ((x - n*(n+1)) % (n<<1) == 0) {
			ll u = ((x/n) - n + 1)>>1;
			printf("%Ld %Ld\n", u, u+n-1);
		}
	}
	return 0;
}

