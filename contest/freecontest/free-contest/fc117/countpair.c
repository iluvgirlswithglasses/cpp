
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Nov 16 20:22:11 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <stdio.h>
#include <string.h>

int n;
char s[1000007];

int cnt;
long long res;

int main() {
	scanf("%s", s);
	n = strlen(s);
	for (char *c = s; c != s+n; c++) {
		if (*c == '1') cnt++;
		if (*c == '2') res += cnt; 
	}
	printf("%Ld\n", res);
	return 0;
}

