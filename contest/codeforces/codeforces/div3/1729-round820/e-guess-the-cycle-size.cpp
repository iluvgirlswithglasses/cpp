
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Oct 04 15:18:48 2022
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

ll query(int a, int b) {
	printf("? %d %d\n", a, b);
	fflush(stdout);
	ll d;
	scanf("%lld", &d);
	return d;
}

ll ask() {
	for (int i = 2; i < 30; i++) {
		ll f = query(1, i), g = query(i, 1);
		// i > n --> n == i-1
		if (f == -1ll) 
			return i - 1;
		if (f != g)	// --> two different paths
			return f + g;
	}
	return -1;
}

int main() {
	ll res = ask();
	printf("! %lld\n", res);
	fflush(stdout);
	return 0;
}
