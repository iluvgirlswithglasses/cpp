
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct  8 08:09:08 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<char> m;

bool repeatcheck(string &s) {
	for (int i = 1; i < s.length(); i++)
		if (s[i-1] == s[i]) return true;
	return false;
}

bool simplecheck(string &s, char l, char r) {
	for (char c: s) if (l <= c && c <= r) return true;
	return false;
}

bool strong(string &s) {
	if (s.length() < 8 || repeatcheck(s)) return false;
	for (char c: s) if (m.find(c) != m.end()) {
		return simplecheck(s, 'a', 'z') && simplecheck(s, 'A', 'Z') && simplecheck(s, '0', '9');
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (char c: "!@#$%^&*()-+") m.insert(c);
	//
	string s; cin >> s;
	if (strong(s))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
