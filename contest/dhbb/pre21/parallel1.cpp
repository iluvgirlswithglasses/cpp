
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 16 19:48:56 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <map>
using namespace std;

#define pi pair<const int, int>
#define st first
#define nd second

const char* check(map<int, int> &m) {
	for (pi &p: m) while (p.nd > 0) {
		p.nd -= 4;
		if (p.nd < 0) return "no\n";
	}
	return "yes\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while (true) {
		map<int, int> m;
		for (int i = 0; i < 12; i++) {
			int a; cin >> a;
			m[a]++;
		}
		if (m[0] == 12)
			break;
		cout << check(m);
	}
	return 0;
}
