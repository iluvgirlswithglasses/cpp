
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct 30 13:00:59 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

string s;
unordered_set<char> c = {'u', 'e', 'o', 'a', 'i'};

char cap(char c) {
	if ('a' <= c && c <= 'z') c = c - 'a' + 'A';
	return c;
}

char low(char c) {
	if ('A' <= c && c <= 'Z') c = c - 'A' + 'a';
	return c;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> s;
		for (char i: s) {
			i = low(i);
			if (c.find(i) != c.end()) {
				cout << cap(i);
			} else {
				cout << low(i);
			}
		}
		cout << "\n";
	}
	return 0;
}

