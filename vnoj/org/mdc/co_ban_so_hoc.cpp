
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Oct 04 21:58:42 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// i wrote 3 tests and 7 sols today
// also rewrite the whole eratos tools base
// kinda tired

#include <iostream>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

int twocnt, fivecnt;

void split(int x) {
	while (x % 2 == 0) {
		twocnt++;
		x /= 2;
	}
	while (x % 5 == 0) {
		fivecnt++;
		x /= 5;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		split(i);
	}
	cout << min(twocnt, fivecnt) << "\n";
	return 0;
}
