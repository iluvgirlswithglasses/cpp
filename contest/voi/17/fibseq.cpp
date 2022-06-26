
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Jan 20 08:23:45 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define ll long long
#define pi pair<ll, ll>
#define st first
#define nd second

pi fastfib(int i, const ll r) {
	if (i == 0) 
		return make_pair(0ll, 1ll);
	pi p = fastfib(i>>1, r);
	ll c = p.st * (p.nd * 2 - p.st + r) % r;
	ll d = (p.st * p.st + p.nd * p.nd) % r;
	//
	if (i&1)
		return make_pair(c, (c+d) % r);
	return make_pair(c, d);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	return 0;
}
