
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct 08 14:43:14 2022
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

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const string RES = ".py";

void lower(string &s) {
	for (char &c: s) if ('A' <= c && c <= 'Z') {
		c = c - 'A' + 'a';
	}
}

bool check(string &s) {
	int n = s.length();
	for (int i = n-1; i >= 0; i--) if (s[i] == '.') {
		return s.substr(i, n-i) == RES;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin >> s;
	lower(s);
	if (check(s))
		cout << "yes\n";
	else
		cout << "no\n";
	return 0;
}
