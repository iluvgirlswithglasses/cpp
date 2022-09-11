
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Dec 21 20:41:15 2021
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n = s.length();
		if (n&1) {
			cout << "NO\n";
		} else if (s.substr(0, n>>1) == s.substr(n>>1, n>>1)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}
