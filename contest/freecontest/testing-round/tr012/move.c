
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 20 15:34:46 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <stdio.h>

int abs(int x) {
    if (x < 0) return -x;
    return x;
}

int n, m, a, b, c, d;

int main() {
    scanf("%d%d%d%d%d%d", &n, &m, &a, &b, &c, &d);
    if ((a&1) == (c&1) && (b&1) == (d&1)) {
        printf("%d\n", (abs(a-c)>>1) + (abs(b-d)>>1));
    } else {
        printf("-1\n");
    }
	return 0;
}
