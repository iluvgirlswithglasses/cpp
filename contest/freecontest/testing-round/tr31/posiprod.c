
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
Mon Jun 13 11:35:28 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <stdio.h>
int n, a, pc, nc, zero;

int min(int a, int b) {
    if (a < b) return a;
    return b;
}

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        if (a == 0) zero = 1;
        else if (a < 0) nc++;
        else pc++;
    }
    if (zero) 
        printf("%d\n", -1);
    else
        printf("%d\n", min(pc, nc));
	return 0;
}
