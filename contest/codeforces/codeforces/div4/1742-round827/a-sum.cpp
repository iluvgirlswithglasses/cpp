
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Oct 14 12:59:08 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

int a[3];

const char* calc() {
	int s = a[0] + a[1] + a[2];
	for (int i = 0; i < 3; i++) {
		if (s - a[i] == a[i]) return "YES\n";
	}
	return "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> a[0] >> a[1] >> a[2];
		cout << calc();
	}
	return 0;
}
