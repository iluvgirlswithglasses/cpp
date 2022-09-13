
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Sep 12 09:38:40 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <cstdio>
using namespace std;

char rep[2];

int main() {
	int l = 1, r = 1e6;
	while (l < r) {
		int m = (l+r+1)>>1;
		printf("%d\n", m);
		fflush(stdout);
		scanf("%s", rep);
		if (rep[0] == '<')
			r = m-1;
		else
			l = m;
	}
	printf("! %d\n", l);
	fflush(stdout);
	return 0;
}
