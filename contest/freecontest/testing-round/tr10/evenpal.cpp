
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Dec 14 20:30:47 2021
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

const char* calc() {
	for (int i = 0; i < n-1; i++) {
		if (s[i] == s[i+1]) return "YES";
	}
	return "NO";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> s;
		n = s.length();
		cout << calc() << "\n";
	}
	return 0;
}
