
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:    Mon Oct 10 21:14:41 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <stdio.h>

int a[6];

int main() {
    for (int i = 1; i <= 5; i++)
        scanf("%d", a+i);
    for (int i = 5; i >= 1; i--)
        if (a[i]) printf("%d", i);
    printf("\n");
	return 0;
}
