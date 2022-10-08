
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct  8 10:04:23 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
using namespace std;

int n;
string s; 

bool check() {
	int first = 0, secon = n/3, third = n/3*2;
	for (int i = 0; i < n/3; i++) {
		if (s[first + i] != s[third + i]) return false;
	}
	for (int i = 0; i < n/3; i++) {
		if (s[secon + i] != s[third-1-i]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> s;
		n = s.length();
		if (n % 3 == 0) {
			cout << check() << "\n";
		} else {
			cout << "0\n";
		}
	}
	return 0;
}
