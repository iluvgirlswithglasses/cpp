
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Sep 12 21:38:58 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

int n;
string s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q; cin >> q;
	while (q--) {
		cin >> n >> s;
		vector<bool> loc(n, false);
		for (int i = n-1; i >= 2; ) {
			if (s[i] == '0') {
				loc[i-2] = true;
				i -= 3;
			} else {
				i--;
			}
		}
		//
		for (int i = 0; i < n;) {
			char c;
			if (loc[i]) {
				c = 'a' - 1 + stoi(s.substr(i, 2));
				i += 3;
			} else {
				int tmp = s[i++] - '0';
				c = 'a' - 1 + tmp;
			}
			cout << c;
		}
		cout << "\n";
	}
	return 0;
}
