
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Nov 23 09:14:54 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <stdio.h>

#define ll long long
#define N 200007
#define I 1000000000000000007
ll n, l[N], r[N];
ll res = I;

ll min(ll a, ll b) {
    if (a < b) return a;
    return b;
}

ll abs(ll x) {
    if (x < 0) return -x;
    return x;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%Ld", &l[i]);
    //
    for (int i = n; i >= 1; i--)
        r[i] = r[i+1] + l[i];
    for (int i = 1; i <= n; i++)
        l[i] = l[i-1] + l[i];
    //
    for (int i = 1; i < n; i++)
        res = min(res, abs(l[i] - r[i+1]));
    printf("%Ld\n", res);
	return 0;
}
