
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Nov 14 10:35:49 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// I gonna try C out

#include <stdio.h>

int n, x, s, i, j, k;

int abs(int x) {
	if (x > 0) return x;
	return -x;
}

int max(int i, int j) {
	if (i > j) return i;
	return j;
}

int main() {
	scanf("%d %d", &n, &x);
	while (n--) {
		scanf("%d %d", &i, &j);
		if (abs(i - j) > x) {
			scanf("%d", &k);
			s += k;
		} else {
			s += max(i, j);
		}
	}
	printf("%d\n", s);
	return 0;
}

