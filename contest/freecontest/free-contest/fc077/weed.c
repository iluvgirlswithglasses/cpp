
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Nov 19 12:15:24 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <stdio.h>

int min(int a, int b) {
	if (a < b) return a;
	return b;
}

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int n, w, ma, mi, res;

int main() {
	scanf("%d%d", &n, &ma);
	mi = ma;
	while (--n) {
		scanf("%d", &w);
		mi = min(mi, w);
		ma = max(ma, w);
		res = max(res, max(
			w - mi,
			ma - w
		));
	}
	printf("%d\n", res);
	return 0;
}

